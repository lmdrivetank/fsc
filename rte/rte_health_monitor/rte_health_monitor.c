#include "rte_health_monitor.h"

Te_FallbackLevel RTE_HM_GetFallbackLevel()
{
	Te_FallbackLevel level = Te_FallbackLevel_None;
	return level;
}

HealthInfo_S RTE_HM_GetSystemHealthInfo()
{
	HealthInfo_S info = { 0 };
	return info;
}

void RTE_HM_SetFaultInfo(uint16_t health_obj, HealthInfo_S info)
{
}