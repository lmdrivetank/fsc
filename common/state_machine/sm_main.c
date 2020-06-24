#include "sm_main.h"
#include "sm_state.h"
//#include "sm_exception.h"
#include "sm_heartbeat.h"
#include "rte_sm.h"

bool SM_UpdateContext(Ts_StateMachine* sm)
{
	bool result = false;
	Te_ModuleIdentify_u16 module_id = sm->state_machine_id;
	Ts_StateManager* curr_state;

	sm->request_state = RTE_SM_RecvStateRequest(module_id);
	if (sm->current_state != sm->request_state && 
		SM_GetJumpResult(sm->map, sm->current_state, sm->request_state))
	{
		curr_state = &(sm->buff_state_manager[sm->current_state]);
		SM_ExitCurrState(curr_state);

		sm->prev_state = sm->current_state;
		sm->current_state = sm->request_state;
		RTE_SM_SendStateCurrent(module_id, sm->current_state);
		result = true;
	}
	return result;
}

void SM_Polling(Ts_StateMachine* sm)
{
	Ts_StateManager * curr_state;
	uint16_t module_id = sm->state_machine_id;

	SM_HeartBeating(module_id);

	SM_UpdateContext(sm);
	do {
		curr_state = &(sm->buff_state_manager[sm->current_state]);
		SM_Schedule(module_id, curr_state);
	} while (SM_UpdateContext(sm));
}