#include "rte_main.h"
#include "rte_task.h"
#include "StaticAllocation.h"
#include "test_aa.h"

void rte_main()
{
    static Ts_TaskContext TaskContext_smtest;
    static StaticTask_t xCreatorTaskTCBBuffer_smtest;
    static StackType_t uxCreatorTaskStackBuffer_sm_test[100];
    rte_task_create(test_aa_runnable,
        "test_aa_runnable",
        100,
        2,
        &(uxCreatorTaskStackBuffer_sm_test[0]),
        &xCreatorTaskTCBBuffer_smtest,
        6000000,
        5000000,
        &TaskContext_smtest);
}