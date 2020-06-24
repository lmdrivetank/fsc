#pragma once

#include "rte_sm.h"
#include "rte_type.h"
#include "rte_health_monitor_type.h"

// hmi
void RTE_Operator_RecvAdPowerOn();
void RTE_Operator_RecvAdPowerOff();
void RTE_Operator_RecvAdEngage();
void RTE_Operator_RecvAdTakeover();
void RTE_Operator_SendAdPowerStatus();
void RTE_Operator_RecvAdWorkStatus();
void RTE_Operator_RecvOperatorMergeRequest(Te_admerge_state_u8 state);
// aa
void RTE_Operator_SendMergeRequest();
// ota
void RTE_Operator_SendUpdateResponse();
void RTE_Operator_RecvUpdateRequest();
// power manager
// mcu manager
// board manager
//health monitor
extern void RTE_HM_SetFaultInfo(uint16_t health_obj, HealthInfo_S info);