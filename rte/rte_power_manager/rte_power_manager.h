#ifndef _RTE_POWER_MANAGER_H_
#define _RTE_POWER_MANAGER_H_

#include "rte_power_manager_type.h"

void RTE_GetPowerStatus(uint16_t power_obj, uint8_t status);
void RTE_SetPowerExpect(uint16_t power_obj, uint8_t expect);

#endif