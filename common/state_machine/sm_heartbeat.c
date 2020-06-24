#include "sm_heartbeat.h"
#include "rte_sm.h"


void SM_HeartBeating(Te_ModuleIdentify_u16 module_id)
{
	RTE_SM_HeartBeating(module_id);
}