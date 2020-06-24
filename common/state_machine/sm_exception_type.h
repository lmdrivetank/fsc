#ifndef _SM_EXCEPTION_TYPE_H_
#define _SM_EXCEPTION_TYPE_H_

#include "sm_task_type.h"
#include "rte_sm_type.h"
#include "rte_health_monitor_type.h"

typedef uint8_t Te_Exception_u8;
#define Te_Exception_None                   (0x00)
#define Te_Exception_Occur                  (0x01)
/////////
typedef struct {
	Te_PollingResult_u8 polling_result;
	Te_StateIdentify_i8 state_dest;
	Te_FallbackLevel_u8 fault_level;
} Ts_ExceptionResult;

typedef struct {
	Te_FallbackLevel_u8 level;
	Tpf_Work exception_check;
	Te_WorkReuslt_u8 check_result;		
} Ts_BusinessCheck;

typedef struct {
	Te_FallbackLevel_u8 level;
	int buff_count;
	Ts_BusinessCheck* buff_exception;
} Ts_BusinessInterrupt;

typedef struct {
	bool exception_exit;
	Te_FallbackLevel_u8 level;
} Ts_CooperateInterrupt;

typedef struct
{
	Te_StateIdentify_i8 state_self;
	Te_StateIdentify_i8 state_dest;
	Te_FallbackLevel_u8 fault_level;

	Ts_CooperateInterrupt cooperate;
	Ts_BusinessInterrupt business;
} Ts_StateException;

#endif