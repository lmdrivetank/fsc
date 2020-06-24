#ifndef _RTE_TASK_H_
#define _RTE_TASK_H_

#include "rte_type.h"
#include "FreeRTOS.h"
#include "task.h"

#define         TaskStartPublicDelayUs                  (1000*1000)
#define         US_TO_MS(a)                             (a/1000)
#define         MS_TO_TICK(a)                           (a/portTICK_RATE_MS)

typedef struct
{
    char                            task_name[10];
    TaskHandle_t *                  ptask_handle;

    uint32_t                        start_us;       //uint: us    system absolute time; should bigger than cycle_time
    uint32_t                        cycle_us;       //uint: us
    TickType_t                      prev_ticks;
    TickType_t                      cycle_ticks;

    TaskFunction_t                  pxTaskRunnable;
} Ts_TaskContext;

void rte_task_create(   TaskFunction_t                  pxTaskCode,     //if NULL, will be set module_thread_runnable; else user self define (only ssm except)
                        const char* const               pcName,
                        const uint16_t                  usStackDepth,
                        UBaseType_t                     uxPriority,
                        StackType_t* const              puxStackBuffer,
                        StaticTask_t* const             pxTaskBuffer,
                        uint32_t                        uStartTimeUs,
                        uint32_t                        uCycleTimeUs,
                        Ts_TaskContext *                pxTaskContext);

void rte_task_release(Ts_TaskContext* pxTaskContext);

void rte_task_polling(Ts_TaskContext* pxTaskContext);

#endif