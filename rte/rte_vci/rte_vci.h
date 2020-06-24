#pragma once

#include "rte_type.h"
#include "rte_health_monitor_type.h"

// lean or ad or operator hmi
void RTE_VCI_RecvAccPedalPercent();
void RTE_VCI_RecvBrakeCmdMpss();
void RTE_VCI_RecvSteelWheelAngleRad();
void RTE_VCI_SendVechileReport();

//aa
void RTE_VCI_RecvFallbackLevel(Te_FallbackLevel_u8 fallback_level);

// health monitor
extern void RTE_HM_SetFaultInfo(uint16_t health_obj, HealthInfo_S info);