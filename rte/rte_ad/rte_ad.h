#ifndef _RTE_AD_H_
#define _RTE_AD_H_

#include "rte_sm.h"
#include "rte_type.h"
#include "rte_health_monitor_type.h"

// ad proxy
// merge
void RTE_AD_RecvMergeRequest(Te_CybertronMerge_state_u8 req);

void RTE_AD_RecvFallbackLevel(Te_FallbackLevel_u8 fallback_level);

void RTE_AD_SendControlResult(uint8_t * control_result);

#endif // !_RTE_AD_H_