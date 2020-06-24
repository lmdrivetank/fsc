#ifndef _SM_COOPERATE_H_
#define _SM_COOPERATE_H_

#include "sm_cooperate_type.h"

bool SM_CooperateStep(Ts_CooperateStep * step_cooperate);
Te_StateCooperateResult SM_StateCooperate(Ts_StateCooperate * state_cooperate);
void SM_CooperateClear(Ts_StateCooperate* state_cooperate);
#endif