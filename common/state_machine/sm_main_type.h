#ifndef _SM_MAIN_TYPE_H_
#define _SM_MAIN_TYPE_H_

#include "rte_type.h"
#include "rte_sm_type.h"
#include "sm_state_type.h"

typedef struct {
    // static
    Te_ModuleIdentify_u16 state_machine_id;

    //Ts_HeartBeat heartbeat_manager;

    Te_StateIdentify_i8 state_count;
    Te_StateIdentify_i8 default_state_id;
    Ts_StateManager * buff_state_manager;
    
    Ts_StateJumpMap * map;
    // dynamic
    Te_StateIdentify_i8 prev_state;
    Te_StateIdentify_i8 current_state;
    Te_StateIdentify_i8 request_state;
} Ts_StateMachine;

#endif