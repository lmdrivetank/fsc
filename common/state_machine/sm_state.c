#include "sm_state.h"
#include "sm_cooperate.h"
#include "sm_exception.h"

void PollingRemove(Ts_StateManager* curr_state, Ts_StateTask* polling_curr)
{
	Ts_StateTask* task_prev = polling_curr->polling_prev;
	Ts_StateTask* task_next = polling_curr->polling_next;

	// remove self from polling list
	if (task_prev != NULL)
	{
		task_prev->polling_next = task_next;
	}
	else
	{
		curr_state->polling_head = task_next;
	}
	if (task_next != NULL)
	{
		task_next->polling_prev = task_prev;
	}
	else
	{
		curr_state->polling_tail = task_prev;
	}
}
void PollingContinue(Ts_StateManager* curr_state, Ts_StateTask* polling_curr)
{
	Te_TaskLocalization_u8 localization = polling_curr->localization;
	Ts_BranchContext* branch = polling_curr->branch;
	Ts_StateTask* task_point;
	bool flag_add = true;

	switch (localization)
	{
	case Te_Branch_Begin:
		branch->fork_started = 0;
		branch->fork_arrived = 0;
		break;
	case Te_Branch_First:
		branch->fork_started++;
		break;
	default:
		break;
	}
	// add next task to polling tail, if exist
	task_point = polling_curr->order_next;
	while (task_point != NULL)
	{
		if (task_point->localization == Te_Branch_End)
		{
			branch->fork_arrived++;
			if (branch->fork_arrived < branch->parallel_limit)
			{
				flag_add = false;
			}
		}
		if (flag_add == true)
		{
			curr_state->polling_tail->polling_next = task_point;
			task_point->polling_prev = curr_state->polling_tail;
			curr_state->polling_tail = task_point;
		}
		task_point = task_point->parallel_next; // mostly like occur at first of branch
	}
	PollingRemove(curr_state, polling_curr);
}

void SM_Schedule(Te_ModuleIdentify_u16 sm_id, Ts_StateManager* curr_state)
{
	Te_PollingResult_u8 polling_result = Te_PollingResult_Finish;
	Ts_StateTask* polling_curr;
	Ts_WorkPair work_pair;
	Ts_BranchContext* branch;
	Te_TaskLocalization_u8 localization;
	Ts_StateCooperate* cooperate = curr_state->cooperate;
	Ts_ExceptionResult exception_result;

	printf("SM_Schedule module %d, state %d \n", sm_id, curr_state->state_id);

	if (curr_state->polling_head == NULL)
	{
		curr_state->polling_head = curr_state->state_begin;
		curr_state->polling_tail = curr_state->state_begin;
	}
	polling_curr = curr_state->polling_head;

	if (cooperate->style == Te_StateCooperateStyle_Negotiating
		&& SM_StateCooperate(curr_state->cooperate) == Te_StateCooperateResultFail)
	{
		polling_result = Te_PollingResult_Hold;
		if (cooperate->cooperate_fail_count > cooperate->cooperate_fail_limit)
		{
			printf("cooperate fail over limit %d\n", cooperate->cooperate_fail_limit);
			SM_SetCooperateFault(curr_state->exception);
		}
	}

	do {
		if (cooperate->style == Te_StateCooperateStyle_Steady
			&& SM_StateCooperate(curr_state->cooperate) == false)
		{
			polling_result = Te_PollingResult_Hold;
			SM_SetCooperateFault(curr_state->exception);
		}
		exception_result = SM_ExceptionInterrupt(curr_state->exception);
		if (exception_result.polling_result == Te_PollingResult_Break)
		{
			RTE_SM_SendStateRequest(sm_id, exception_result.state_dest);
			break;
		}
		if (polling_curr)
		{
			branch = polling_curr->branch;
			localization = polling_curr->localization;
			work_pair = polling_curr->work_pair;
			if (localization == Te_Branch_End && branch->fork_arrived != branch->parallel_limit)
			{
				// branch can not finish, must likely push end task by last fork, so this condition almost match
				polling_result = Te_PollingResult_Hold;
			}
			else if (localization == Te_Branch_First && branch->fork_started == branch->parallel_limit)
			{
				PollingRemove(curr_state, polling_curr);
			}
			else if ((work_pair.workCondition != NULL) && (work_pair.workCondition() != work_pair.p_depend_c))
			{
				// exist condition, but not match	
				polling_result = Te_PollingResult_Hold;
			}
			else
			{
				if (localization == Te_Branch_First)
				{
					branch->fork_started++;
				}
				else if (localization == Te_Branch_End)
				{
					branch->fork_arrived--;
				}
				// work and delelte self, then add next tasks
				work_pair.workPerformance();

				PollingContinue(curr_state, polling_curr);
			}
			polling_curr = polling_curr->polling_next;
		}
	} while (polling_curr != NULL);

	if (polling_result == Te_PollingResult_Finish &&
		curr_state->finish_dest != curr_state->state_id)
	{
		RTE_SM_SendStateRequest(sm_id, curr_state->finish_dest);
	}
}

void SM_ExitCurrState(Ts_StateManager* curr_state)
{
	Ts_StateTask* polling_curr;

	SM_CooperateClear(curr_state->cooperate);

	if (curr_state->polling_head != NULL)
	{
		polling_curr = curr_state->polling_head;

		do {
			PollingRemove(curr_state, polling_curr);
			polling_curr = polling_curr->polling_next;
		} while (polling_curr != NULL);
	}	
}

bool SM_GetJumpResult(Ts_StateJumpMap* map, Te_StateIdentify_i8 state_current, Te_StateIdentify_i8 state_request)
{
	bool result = false;
#if 0
	if (state_current < 32 && 
		state_request < 32 && 
		(map->map[state_request] >> state_current == 1))
	{
		result = true;
	}
#else
	result = true;
#endif
	return result;
}

Te_StateIdentify_i8 SM_GetFinishState(Ts_StateManager* curr_state)
{
	return curr_state->finish_dest;
}