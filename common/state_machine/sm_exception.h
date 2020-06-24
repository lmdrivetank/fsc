#ifndef _SM_EXCEPTION_H_
#define _SM_EXCEPTION_H_

#include "sm_exception_type.h"
#include "sm_state_type.h"

//Ts_ExceptionResult SM_CooperateInterrupt(Ts_StateException* exception);
//Ts_ExceptionResult SM_BusinessInterrupt(Ts_StateException* exception);
Ts_ExceptionResult SM_ExceptionInterrupt(Ts_StateException* exception);

void SM_SetCooperateFault(Ts_StateException* exception);
void SM_ClearCooperateFault(Ts_StateException* exception);
#endif