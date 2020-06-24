#ifndef _AA_H_
#define _AA_H_

/* president internal sub-funtion and state-machine */
#include "rte_aa.h"
#include "rte_health_monitor.h"
#include "sm_main.h"
#include "rte_task.h"

TaskFunction_t AA_Task();

Tpf_Work AA_Merge();

Tpf_Work AA_HealthExceptionOccur();
Tpf_Work AA_SwitchCybertronControl();
Tpf_Work AA_SwitchLeanControl();

#endif