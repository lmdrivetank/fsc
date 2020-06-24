#ifndef _RTE_AA_H_
#define _RTE_AA_H_

#include "rte_sm.h"
#include "rte_type.h"
// service include
#include "rte_health_monitor_type.h"
#include "rte_power_manager_type.h"

/* operator */
void RTE_AA_RecvOperatorMergeRequest(Te_admerge_state_u8 * state);

/* cybertron */
void RTE_AA_SendCybertronMergeRequest(Te_admerge_state_u8 state);

/* lean control */

/* vci */
Te_ControlSwitch_u8 RTE_AA_RecvControlSwitch();
void RTE_AA_SendControlSwitch(Te_ControlSwitch_u8 control_switch);

/* ad members */
void RTE_AA_SendFallbackLevel(Te_FallbackLevel_u8 fallback_level);

// health monitor
extern void RTE_HM_SetFaultInfo(uint16_t health_obj, HealthInfo_S info);

#endif