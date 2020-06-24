#pragma once

#include "rte_sm.h"
#include "rte_type.h"
#include "rte_health_monitor_type.h"

void RTE_LeanControl_RecvFallbackLevel(Te_FallbackLevel_u8 fallback_level);

//to health monitor
extern void RTE_HM_SetFaultInfo(uint16_t health_obj, HealthInfo_S info);