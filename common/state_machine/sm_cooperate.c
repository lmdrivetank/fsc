#include "sm_cooperate.h"
#include "rte_health_monitor.h"
#include "rte_sm.h"
bool SM_CooperateStep(Ts_CooperateStep* step_cooperate)
{
	bool result = true;
	uint8_t pos = 0;
	Ts_StateDepend depend;
	Te_StateIdentify_i8 state;

	for (; pos < step_cooperate->buff_count; pos++)
	{
		depend = step_cooperate->buff_depend[pos];

		if (depend.state_dst != RTE_SM_RecvStateCurrent(depend.module_id))
		{
			result = false; 
			state = RTE_SM_RecvStateRequest(depend.module_id);
			if (depend.state_mid != state &&
				depend.state_dst != state)
			{
				RTE_SM_SendStateRequest(depend.module_id, depend.state_mid);
			}
		}		
	}
	return result;
}

Te_StateCooperateResult SM_StateCooperate(Ts_StateCooperate* state_cooperate)
{
	Te_StateCooperateResult result = Te_StateCooperateResultSucc;
	uint8_t pos = 0;
	FaultInfo_S fault_info;

	for (pos = state_cooperate->step_pos; pos < state_cooperate->step_count; pos++)
	{
		if (true == SM_CooperateStep(&(state_cooperate->buff_step[pos])))
		{
			continue;
		}
		else
		{
			result = Te_StateCooperateResultFail;
			state_cooperate->cooperate_fail_count++;
			printf("SM_StateCooperate fail pos %d\n", pos);
			break;
		}
	}
	if (result == Te_StateCooperateResultSucc && state_cooperate->style == Te_StateCooperateStyle_Steady)
	{
		state_cooperate->step_pos = 0;
	}

	state_cooperate->step_result = result;

	return result;
}

void SM_CooperateClear(Ts_StateCooperate* state_cooperate)
{
	state_cooperate->cooperate_fail_count = 0;
	state_cooperate->step_pos = 0;
	state_cooperate->step_result = Te_StateCooperateResultSucc;
}