#include "sm_exception.h"

Ts_ExceptionResult SM_CooperateInterrupt(Ts_StateException* exception)
{
	Ts_ExceptionResult result;
	Ts_CooperateInterrupt* cooperate = &(exception->cooperate);

	if (cooperate->exception_exit == true)
	{
		result.polling_result = Te_PollingResult_Break;
		result.fault_level = cooperate->level;
	}
	else
	{
		result.polling_result = Te_PollingResult_Continue;
		result.fault_level = Te_FallbackLevel_None;
	}

	return result;
}
Ts_ExceptionResult SM_BusinessInterrupt(Ts_StateException* exception)
{
	Ts_ExceptionResult result;
	Ts_BusinessInterrupt* business = &(exception->business);
	Ts_BusinessCheck* buff_exception = business->buff_exception;
	int check_id = 0;
	Te_FallbackLevel_u8 fault_level = Te_FallbackLevel_None;

	result.polling_result = Te_PollingResult_Continue;
	for (check_id = 0; check_id < business->buff_count; check_id++)
	{
		if (buff_exception[check_id].exception_check() == buff_exception[check_id].check_result)
		{
			fault_level = buff_exception->level > fault_level ? buff_exception->level : fault_level;
			result.polling_result = Te_PollingResult_Break;
		}
	}
	result.fault_level = fault_level;

	return result;
}

Ts_ExceptionResult SM_ExceptionInterrupt(Ts_StateException* exception)
{
	Ts_ExceptionResult result;
	Ts_ExceptionResult cooperate;
	Ts_ExceptionResult business;
	
	cooperate = SM_CooperateInterrupt(exception);
	business = SM_BusinessInterrupt(exception);

	if (cooperate.polling_result == Te_PollingResult_Break || business.polling_result == Te_PollingResult_Break)
	{
		result.polling_result = Te_PollingResult_Break;
		result.fault_level = cooperate.fault_level > business.fault_level ? cooperate.fault_level : business.fault_level;
		result.state_dest = exception->state_dest;
	}
	else
	{
		result.polling_result = Te_PollingResult_Continue;
		result.fault_level = Te_FallbackLevel_None;
		result.state_dest = exception->state_self;
	}

	//RTE_SM_SendStateRequest(exception->module_id, exception->state_dest);

	return result;
}

void SM_SetCooperateFault(Ts_StateException* exception)
{
	exception->cooperate.exception_exit = true;
}
void SM_ClearCooperateFault(Ts_StateException* exception)
{
	exception->cooperate.exception_exit = false;
}