#ifndef _SM_TASK_TYPE_H_
#define _SM_TASK_TYPE_H_

#include  "rte_type.h"

typedef uint8_t Te_WorkReuslt_u8;
#define Te_WorkReuslt_Succ                  (0x0)
#define Te_WorkReuslt_Fail                  (0x1)
/////////////////////
typedef uint8_t Te_BranchType_u8;
#define Te_BranchType_Switch                (0x1)
#define Te_BranchType_ParallelWith          (0x2)
#define Te_BranchType_ParallelOr            (0x3)
//////////////////
typedef uint8_t Te_TaskLocalization_u8;
#define Te_Branch_Begin                     (0x1)
#define Te_Branch_End                       (0x2)
#define Te_Branch_First                     (0x3)
#define Te_Branch_Mid                       (0x4)
//////////////////

typedef Te_WorkReuslt_u8(*Tpf_Work)();

typedef struct {
    // workPerformance will doing until conditon result equal p_depend_c
    Te_WorkReuslt_u8 p_depend_c;
    Tpf_Work workCondition;
    Tpf_Work workPerformance;
} Ts_WorkPair;

typedef struct {
    // static
    //int branch_id;
    Te_BranchType_u8 branch_type;
    //int father_branch_id;
    int parallel_limit; //TaskBranch_ParallelOr
    //int task_count;
    //int branch_head;    //task_id
    //int branch_tail;    //task_id
    // dynamic for control branch start and finish
    int fork_started;
    int fork_arrived;
} Ts_BranchContext;

extern struct Ts_StateTask;
typedef struct {
    //static
    //int task_id;
    //int father_state_id;
    //int father_branch_id;

    Ts_WorkPair work_pair;

    Ts_BranchContext* branch;
    Te_TaskLocalization_u8 localization;
    
    struct Ts_StateTask* order_next;
    struct Ts_StateTask* parallel_next; // if not null mean branch start and this is first tasks
    //dynamic
    struct Ts_StateTask* polling_prev;
    struct Ts_StateTask* polling_next;
} Ts_StateTask;

#endif