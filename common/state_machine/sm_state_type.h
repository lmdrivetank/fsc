#ifndef _SM_STATE_TYPE_H_
#define _SM_STATE_TYPE_H_

#include "rte_sm_type.h"
#include "sm_task_type.h"
#include "sm_exception_type.h"
#include "sm_cooperate_type.h"

typedef struct {
 // state count can not bigger than 32
    uint32_t map[32];
} Ts_StateJumpMap;

typedef struct {
    // static
    Te_StateIdentify_i8 state_id;
    Te_StateIdentify_i8 finish_dest;
    Te_StateIdentify_i8 except_dest;
    // int task_count;
    Ts_StateTask* state_begin;
    Ts_StateException *exception;// out of planning    
    Ts_StateCooperate *cooperate;
    // dynamic
    Ts_StateTask* polling_head;
    Ts_StateTask* polling_tail;
} Ts_StateManager;

#endif