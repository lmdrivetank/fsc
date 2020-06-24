#pragma once
#include "rte_aa.h"
#include "sm_main.h"

// ad run
Tpf_Work Ad_Merge();
// ad prepare/ready/engage/disengage/run
Tpf_Work Ad_FaultReport();
// ad ready/engage/disengage/run
Tpf_Work Ad_Fallback();