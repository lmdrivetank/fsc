#ifndef _SM_COOPERATE_TYPE_H_
#define _SM_COOPERATE_TYPE_H_

#include "sm_task_type.h"
#include "rte_sm_type.h"


#define MaxLimit_Cooperate_Fail					5


typedef uint8_t Te_StateCooperateStyle;
#define Te_StateCooperateStyle_Negotiating       0
#define Te_StateCooperateStyle_Steady			 1

typedef uint8_t Te_StateCooperateLimit;
#define Te_StateCooperateLimitDefault			(1)
#define Te_StateCooperateLimitMax				(255)

typedef uint8_t Te_StateCooperateResult;
#define Te_StateCooperateResultFail				(0)
#define Te_StateCooperateResultSucc				(1)

typedef struct
{
	Te_ModuleIdentify_u16 module_id;
	Te_StateIdentify_i8 state_mid;
	Te_StateIdentify_i8 state_dst;
} Ts_StateDepend;

typedef struct
{
	uint8_t step;
	uint8_t buff_count;
	Ts_StateDepend *buff_depend;
} Ts_CooperateStep;

typedef struct
{
	Te_StateIdentify_i8 state_self;
	Te_StateCooperateStyle style;
	uint8_t step_count;
	Ts_CooperateStep* buff_step;
	uint8_t step_pos;
	
	Te_StateCooperateResult step_result;
	uint8_t cooperate_fail_limit;
	uint8_t cooperate_fail_count;
} Ts_StateCooperate;

#endif