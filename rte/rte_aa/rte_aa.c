#include "rte_aa.h"
#include "rte_pool.h"
#include "rte_health_monitor.h"
#include "rte_power_manager.h"

void RTE_AA_RecvOperatorMergeRequest(Te_admerge_state_u8* state)
{
}

void RTE_AA_SendCybertronMergeRequest(Te_admerge_state_u8 state)
{
}

Te_ControlSwitch_u8 RTE_AA_RecvControlSwitch()
{
	Te_ControlSwitch_u8 control_switch = Te_ControlSwitch_Cybertron;
	return control_switch;
}

void RTE_AA_SendControlSwitch(Te_ControlSwitch_u8 control_switch)
{
}

void RTE_AA_SendFallbackLevel(Te_FallbackLevel_u8 fallback_level)
{
}


