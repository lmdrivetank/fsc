#include "rte_sm.h"

Ts_ModuleManager g_ModuleManager;

void RTE_SM_SendStateRequest(Te_ModuleIdentify_u16 module_id, Te_StateIdentify_i8 request)
{
	printf("RTE_SM_SendStateRequest module %d state %d\n", module_id, request);
	g_ModuleManager.buff_module[module_id].state.state_request = request;
}
Te_StateIdentify_i8 RTE_SM_RecvStateRequest(Te_ModuleIdentify_u16 module_id)
{
	//printf("RTE_SM_RecvStateRequest module %d state %d\n", module_id, g_ModuleManager.buff_module[module_id].state.state_request);
	return g_ModuleManager.buff_module[module_id].state.state_request;
}
void RTE_SM_SendStateCurrent(Te_ModuleIdentify_u16 module_id, Te_StateIdentify_i8 current)
{
	printf("RTE_SM_SendStateCurrent module %d state %d\n", module_id, current);
	g_ModuleManager.buff_module[module_id].state.state_current = current;
}
Te_StateIdentify_i8 RTE_SM_RecvStateCurrent(Te_ModuleIdentify_u16 module_id)
{
	return g_ModuleManager.buff_module[module_id].state.state_current;
}

void RTE_SM_HeartBeating(Te_ModuleIdentify_u16 module_id)
{
	g_ModuleManager.buff_module[module_id].heart_beat.heart_beating = true;
}
bool RTE_SM_HeartCheck(Te_ModuleIdentify_u16 module_id)
{
	if (g_ModuleManager.buff_module[module_id].heart_beat.heart_beating == true)
	{
		g_ModuleManager.buff_module[module_id].heart_beat.heart_beating = false;
		g_ModuleManager.buff_module[module_id].heart_beat.sleep_count = 0;
		g_ModuleManager.buff_module[module_id].heart_beat.heart_dead = false;
	}
	else
	{
		g_ModuleManager.buff_module[module_id].heart_beat.sleep_count++;
		if (g_ModuleManager.buff_module[module_id].heart_beat.sleep_count >= Macro_Module_Dead)
		{
			g_ModuleManager.buff_module[module_id].heart_beat.heart_dead = true;
		}
		else
		{
			g_ModuleManager.buff_module[module_id].heart_beat.heart_dead = false;
		}
	}
	return g_ModuleManager.buff_module[module_id].heart_beat.heart_dead;
}
bool RTE_SM_GetHeartStatus(Te_ModuleIdentify_u16 module_id)
{
	return g_ModuleManager.buff_module[module_id].heart_beat.heart_dead;
}


void RTE_SM_SetException(Te_ModuleIdentify_u16 module_id, uint8_t exception_level, uint8_t* exception_info)
{
	int level = g_ModuleManager.buff_module[module_id].exception.exception_level;
	level = exception_level > level ? exception_level : level;
	g_ModuleManager.buff_module[module_id].exception.exception_level = level;
}
uint8_t RTE_SM_GetException(Te_ModuleIdentify_u16 module_id)
{
	return g_ModuleManager.buff_module[module_id].exception.exception_level;
}