#include "aa.h"
#include "rte_aa.h"
#include "aa_data.h"
#include "sm_main.h"

TaskFunction_t AA_Task()
{
	SM_Polling(&g_aa_sm);
}

Tpf_Work AA_Merge()
{
	Te_WorkReuslt_u8 result = Te_WorkReuslt_Succ;
	Te_admerge_state_u8 state;
	RTE_AA_RecvOperatorMergeRequest(&state);
	// approval
	RTE_AA_SendCybertronMergeRequest(state);
	return result;
}

Tpf_Work AA_HealthExceptionOccur()
{
	Te_WorkReuslt_u8 result = Te_WorkReuslt_Fail;

	if (RTE_HM_GetSystemHealthInfo().is_health == true)
	{
		result = Te_WorkReuslt_Succ;
	}
	return result;
};

Tpf_Work AA_SwitchControl()
{
	Te_WorkReuslt_u8 result = Te_WorkReuslt_Succ;

	// fallback switch to lean control
	// else switch to cybertron
	if (RTE_HM_GetFallbackLevel() == Te_FallbackLevel_E &&
		RTE_AA_RecvControlSwitch() == Te_ControlSwitch_Cybertron)
	{
		RTE_AA_SendControlSwitch(Te_ControlSwitch_LeanControl);
	}
	else if (RTE_HM_GetFallbackLevel() < Te_FallbackLevel_E &&
		RTE_AA_RecvControlSwitch() != Te_ControlSwitch_Cybertron)
	{
		RTE_AA_SendControlSwitch(Te_ControlSwitch_Cybertron);
	}

	return result;
}