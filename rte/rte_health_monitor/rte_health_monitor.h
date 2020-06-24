#ifndef _RTE_HEALTH_MONITOR_H_
#define _RTE_HEALTH_MONITOR_H_

#include "rte_health_monitor_type.h"
#include "rte_sm.h"

// to aa
Te_FallbackLevel RTE_HM_GetFallbackLevel();
HealthInfo_S RTE_HM_GetSystemHealthInfo();

// to aa members
void RTE_HM_SetFaultInfo(uint16_t health_obj, HealthInfo_S info);

#endif // !_RTE_HEALTH_MONITOR_H_