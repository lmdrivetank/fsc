#ifndef _SM_STATE_H_
#define _SM_STATE_H_

#include "sm_state_type.h"

void SM_Schedule(Te_ModuleIdentify_u16 sm_id, Ts_StateManager* curr_state);

void SM_ExitCurrState(Ts_StateManager* curr_state);

bool SM_GetJumpResult(Ts_StateJumpMap * map, Te_StateIdentify_i8 state_current, Te_StateIdentify_i8 state_request);

Te_StateIdentify_i8 SM_GetFinishState(Ts_StateManager* curr_state, Te_StateIdentify_i8 state_id);

#endif