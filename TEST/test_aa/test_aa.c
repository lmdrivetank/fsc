#include "test_aa.h"
#include "rte_sm.h"

void test_aa_runnable()
{
	static int test_step = 0;


	AA_Task();

	switch (test_step++)
	{
	case 0:
	{
		RTE_SM_SendStateRequest(Te_ModuleIdentify_AA, TE_ADS_INIT);
	}
		break;
	case 1:
	{
		RTE_SM_SendStateCurrent(Te_ModuleIdentify_Cybertron, TE_ADS_INIT);
		RTE_SM_SendStateCurrent(Te_ModuleIdentify_VCI, TE_ADS_INIT);
		RTE_SM_SendStateCurrent(Te_ModuleIdentify_LeanControl, Te_lean_s_init);
		RTE_SM_SendStateCurrent(Te_ModuleIdentify_LeanLocalization, TE_ADS_INIT);
	}
		break;
	case 2:
	{
		RTE_SM_SendStateRequest(Te_ModuleIdentify_Cybertron, TE_ADS_READY);
		RTE_SM_SendStateRequest(Te_ModuleIdentify_VCI, TE_ADS_READY);
		RTE_SM_SendStateRequest(Te_ModuleIdentify_LeanControl, Te_lean_s_ready);
		RTE_SM_SendStateRequest(Te_ModuleIdentify_LeanLocalization, TE_ADS_READY);
	}
	break;
	case 3:
	{
		RTE_SM_SendStateCurrent(Te_ModuleIdentify_Cybertron, TE_ADS_READY);
		RTE_SM_SendStateCurrent(Te_ModuleIdentify_VCI, TE_ADS_READY);
		RTE_SM_SendStateCurrent(Te_ModuleIdentify_LeanControl, Te_lean_s_ready);
		RTE_SM_SendStateCurrent(Te_ModuleIdentify_LeanLocalization, TE_ADS_READY);
	}
	break;
	case 4:
	{
		RTE_SM_SendStateRequest(Te_ModuleIdentify_AA, TE_ADS_ADPREPARE);
	}
	break;
	case 5:
	{
		RTE_SM_SendStateCurrent(Te_ModuleIdentify_Cybertron, TE_ADS_ADPREPARE);
		RTE_SM_SendStateCurrent(Te_ModuleIdentify_VCI, TE_ADS_ADPREPARE);
		//RTE_SM_SendStateCurrent(Te_ModuleIdentify_LeanControl, Te_lean_s_ready);
		RTE_SM_SendStateCurrent(Te_ModuleIdentify_LeanLocalization, TE_ADS_ADPREPARE);
	}
	break;
	case 6:
	{
		RTE_SM_SendStateRequest(Te_ModuleIdentify_Cybertron, TE_ADS_ADREADY);
		RTE_SM_SendStateRequest(Te_ModuleIdentify_VCI, TE_ADS_ADREADY);
		//RTE_SM_SendStateRequest(Te_ModuleIdentify_LeanControl, Te_lean_s_ready);
		RTE_SM_SendStateRequest(Te_ModuleIdentify_LeanLocalization, TE_ADS_ADREADY);
	}
	break;
	case 7:
	{
		RTE_SM_SendStateCurrent(Te_ModuleIdentify_Cybertron, TE_ADS_ADREADY);
		RTE_SM_SendStateCurrent(Te_ModuleIdentify_VCI, TE_ADS_ADREADY);
		//RTE_SM_SendStateCurrent(Te_ModuleIdentify_LeanControl, Te_lean_s_ready);
		RTE_SM_SendStateCurrent(Te_ModuleIdentify_LeanLocalization, TE_ADS_ADREADY);
	}
	break;
	default:
		break;
	}	
}