#include "rte_task.h"
#include "StaticAllocation.h"

void rte_task_create(TaskFunction_t                  pxTaskCode,     //if NULL, will be set module_thread_runnable; else user self define (only ssm except)
                    const char* const               pcName,
                    const uint16_t                  usStackDepth,
                    UBaseType_t                     uxPriority,
                    StackType_t* const              puxStackBuffer,
                    StaticTask_t* const             pxTaskBuffer,
                    const uint32_t                  uStartTimeUs,
                    const uint32_t                  uCycleTimeUs,
                    Ts_TaskContext*                 pxTaskContext)
{
    pxTaskContext->pxTaskRunnable = pxTaskCode;
    pxTaskContext->start_us = uStartTimeUs + TaskStartPublicDelayUs;
    pxTaskContext->cycle_us = uCycleTimeUs;
    configASSERT(pxTaskContext->start_us > uCycleTimeUs);
    pxTaskContext->prev_ticks = MS_TO_TICK(US_TO_MS(pxTaskContext->start_us - uCycleTimeUs));
    pxTaskContext->cycle_ticks = MS_TO_TICK(US_TO_MS(uCycleTimeUs));

    pxTaskContext->ptask_handle = 
        xTaskCreateStatic((TaskFunction_t)rte_task_polling, pcName, usStackDepth, pxTaskContext, uxPriority, puxStackBuffer, pxTaskBuffer);
}
void rte_task_release(Ts_TaskContext* pxTaskContext)
{
    vTaskDelete(pxTaskContext->ptask_handle);
}
void rte_task_polling(Ts_TaskContext* pxTaskContext)
{
    while (1)
    {
        vTaskDelayUntil(&(pxTaskContext->prev_ticks), pxTaskContext->cycle_ticks);
        pxTaskContext->pxTaskRunnable(NULL);
    }
}
