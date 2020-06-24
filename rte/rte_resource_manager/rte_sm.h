#pragma once

#include "rte_sm_type.h"

void RTE_SM_SendStateRequest(Te_ModuleIdentify_u16 module_id, Te_StateIdentify_i8 request);
Te_StateIdentify_i8 RTE_SM_RecvStateRequest(Te_ModuleIdentify_u16 module_id);
void RTE_SM_SendStateCurrent(Te_ModuleIdentify_u16 module_id, Te_StateIdentify_i8 current);
Te_StateIdentify_i8 RTE_SM_RecvStateCurrent(Te_ModuleIdentify_u16 module_id);


void RTE_SM_HeartBeating(Te_ModuleIdentify_u16 module_id);
bool RTE_SM_HeartCheck(Te_ModuleIdentify_u16 module_id);
bool RTE_SM_GetHeartStatus(Te_ModuleIdentify_u16 module_id);


void RTE_SM_SetException(Te_ModuleIdentify_u16 module_id, uint8_t exception_level, uint8_t * exception_info);
uint8_t RTE_SM_GetException(Te_ModuleIdentify_u16 module_id);