#include "aa_config.h"
#include "aa_data.h"
#include "rte_sm_type.h"
#include "rte_health_monitor_type.h"
#include "aa.h"
#if 1
Ts_BusinessCheck g_aa_buff_exception_business[] = 
{
    {
        //Te_FallbackLevel_u8 level;
        Te_FallbackLevel_None,
        //Tpf_Work exception_check;
        AA_HealthExceptionOccur,
        //Te_WorkReuslt_u8 check_result;
        Te_WorkReuslt_Succ
    }
};
Ts_StateException g_aa_exception[] =
{
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_IDLE,
        //T_StateIdentify_i8 state_dest;
        TE_ADS_IDLE,
        //Te_FallbackLevel_u8 fault_level;
        Te_FallbackLevel_None,

        //Ts_CooperateInterrupt cooperate;
        {
            //bool exception_exit;
            false,
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
        },
        //Ts_BusinessInterrupt business;
        {
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,            
            //int buff_count;
            0,
            //Ts_BusinessCheck* buff_exception;
            NULL,
        }
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_INIT,
        //T_StateIdentify_i8 state_dest;
        TE_ADS_TERMINATE,
        //Te_FallbackLevel_u8 fault_level;
        Te_FallbackLevel_None,

        //Ts_CooperateInterrupt cooperate;
        {
            //bool exception_exit;
            false,
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
        },
        //Ts_BusinessInterrupt business;
        {
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,            
            //int buff_count;
            0,
            //Ts_BusinessCheck* buff_exception;
            NULL,
        }
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_TERMINATE,
        //T_StateIdentify_i8 state_dest;
        TE_ADS_TERMINATE,
        //Te_FallbackLevel_u8 fault_level;
        Te_FallbackLevel_None,

        //Ts_CooperateInterrupt cooperate;
        {
            //bool exception_exit;
            false,
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
        },
        //Ts_BusinessInterrupt business;
        {
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,            
            //int buff_count;
            0,
            //Ts_BusinessCheck* buff_exception;
            NULL,
        }
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_READY,
        //T_StateIdentify_i8 state_dest;
        TE_ADS_TERMINATE,
        //Te_FallbackLevel_u8 fault_level;
        Te_FallbackLevel_None,

        //Ts_CooperateInterrupt cooperate;
        {
            //bool exception_exit;
            false,
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
        },
        //Ts_BusinessInterrupt business;
        {
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,            
            //int buff_count;
            0,
            //Ts_BusinessCheck* buff_exception;
            NULL,
        }
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_ADPREPARE,
        //T_StateIdentify_i8 state_dest;
        TE_ADS_ADEXIT,
        //Te_FallbackLevel_u8 fault_level;
        Te_FallbackLevel_None,

        //Ts_CooperateInterrupt cooperate;
        {
            //bool exception_exit;
            false,
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
        },
        //Ts_BusinessInterrupt business;
        {
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
            //int buff_count;
            0,
            //Ts_BusinessCheck* buff_exception;
            NULL,
        }
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_ADEXIT,
        //T_StateIdentify_i8 state_dest;
        TE_ADS_ADEXIT,
        //Te_FallbackLevel_u8 fault_level;
        Te_FallbackLevel_None,

        //Ts_CooperateInterrupt cooperate;
        {
            //bool exception_exit;
            false,
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
        },
        //Ts_BusinessInterrupt business;
        {
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
            //int buff_count;
            0,
            //Ts_BusinessCheck* buff_exception;
            NULL,
        }
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_ADREADY,
        //T_StateIdentify_i8 state_dest;
        TE_ADS_ADPREPARE,
        //Te_FallbackLevel_u8 fault_level;
        Te_FallbackLevel_None,

        //Ts_CooperateInterrupt cooperate;
        {
            //bool exception_exit;
            false,
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
        },
        //Ts_BusinessInterrupt business;
        {
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
            //int buff_count;
            1,
            //Ts_BusinessCheck* buff_exception;
            g_aa_buff_exception_business,
        }
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_ADENGAGE,
        //T_StateIdentify_i8 state_dest;
        TE_ADS_FALLBACK,
        //Te_FallbackLevel_u8 fault_level;
        Te_FallbackLevel_None,

        //Ts_CooperateInterrupt cooperate;
        {
            //bool exception_exit;
            false,
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
        },
        //Ts_BusinessInterrupt business;
        {
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
            //int buff_count;
            1,
            //Ts_BusinessCheck* buff_exception;
            g_aa_buff_exception_business,
        }
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_ADOFF,
        //T_StateIdentify_i8 state_dest;
        TE_ADS_ADOFF,
        //Te_FallbackLevel_u8 fault_level;
        Te_FallbackLevel_None,

        //Ts_CooperateInterrupt cooperate;
        {
            //bool exception_exit;
            false,
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
        },
        //Ts_BusinessInterrupt business;
        {
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
            //int buff_count;
            1,
            //Ts_BusinessCheck* buff_exception;
            g_aa_buff_exception_business,
        }
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_ADRUN,
        //T_StateIdentify_i8 state_dest;
        TE_ADS_FALLBACK,
        //Te_FallbackLevel_u8 fault_level;
        Te_FallbackLevel_None,

        //Ts_CooperateInterrupt cooperate;
        {
            //bool exception_exit;
            false,
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
        },
        //Ts_BusinessInterrupt business;
        {
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
            //int buff_count;
            1,
            //Ts_BusinessCheck* buff_exception;
            g_aa_buff_exception_business,
        }
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_FALLBACK,
        //T_StateIdentify_i8 state_dest;
        TE_ADS_FALLBACK,
        //Te_FallbackLevel_u8 fault_level;
        Te_FallbackLevel_None,

        //Ts_CooperateInterrupt cooperate;
        {
            //bool exception_exit;
            false,
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
        },
        //Ts_BusinessInterrupt business;
        {
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
            //int buff_count;
            0,
            //Ts_BusinessCheck* buff_exception;
            NULL,
        }
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_MRC,
        //T_StateIdentify_i8 state_dest;
        TE_ADS_MRC,
        //Te_FallbackLevel_u8 fault_level;
        Te_FallbackLevel_None,

        //Ts_CooperateInterrupt cooperate;
        {
            //bool exception_exit;
            false,
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
        },
        //Ts_BusinessInterrupt business;
        {
            //Te_FallbackLevel_u8 level;
            Te_FallbackLevel_None,
            //int buff_count;
            0,
            //Ts_BusinessCheck* buff_exception;
            NULL,
        }
    }
};
// cooperate TE_ADS_IDLE start
Ts_StateDepend g_aa_cooperate_idle0[] =
{
    {
        //uint16_t module_id;
        Te_ModuleIdentify_VCI,
        TE_ADS_IDLE,
        TE_ADS_IDLE
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_Cybertron,
        //uint16_t state_id;
        TE_ADS_IDLE,
        TE_ADS_IDLE
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_LeanControl,
        //uint16_t state_id;
        Te_lean_s_idle,
        Te_lean_s_idle
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_LeanLocalization,
        //uint16_t state_id;
        TE_ADS_IDLE,
        TE_ADS_IDLE
    }
};
Ts_CooperateStep g_aa_cooperate_idle[] =
{
    {
        //uint8_t step;
        0,
        //uint8_t buff_count;
        4,
        //Ts_ModuleStatePair* buff_depend;
        g_aa_cooperate_idle0
    }
};
// cooperate TE_ADS_IDLE finish
// cooperate TE_ADS_INIT start
Ts_StateDepend g_aa_cooperate_init0[] =
{
   {
        //uint16_t module_id;
        Te_ModuleIdentify_Cybertron,
        //uint16_t state_id;
        TE_ADS_INIT,
        TE_ADS_READY
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_VCI,
        //uint16_t state_id;
        TE_ADS_INIT,
        TE_ADS_READY
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_LeanControl,
        //uint16_t state_id;
        Te_lean_s_init,
        Te_lean_s_ready
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_LeanLocalization,
        //uint16_t state_id;
        TE_ADS_INIT,
        TE_ADS_READY
    },
};
Ts_CooperateStep g_aa_cooperate_init[] =
{
    {
        //uint8_t step;
        0,
        //uint8_t buff_count;
        4,
        //Ts_ModuleStatePair* buff_depend;
        g_aa_cooperate_init0
    }
};
// cooperate TE_ADS_INIT end
// cooperate TE_ADS_TERMINATE start
Ts_StateDepend g_aa_cooperate_terminate0[] =
{
    {
        //uint16_t module_id;
        Te_ModuleIdentify_Cybertron,
        //uint16_t state_id;
        TE_ADS_TERMINATE,
        TE_ADS_IDLE
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_VCI,
        //uint16_t state_id;
        TE_ADS_TERMINATE,
        TE_ADS_IDLE
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_LeanControl,
        //uint16_t state_id;
        Te_lean_s_terminate,
        Te_lean_s_idle
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_LeanLocalization,
        //uint16_t state_id;
        TE_ADS_TERMINATE,
        TE_ADS_IDLE
    },
};
Ts_CooperateStep g_aa_cooperate_terminate[] =
{
    {
        //uint8_t step;
        0,
        //uint8_t buff_count;
        4,
        //Ts_ModuleStatePair* buff_depend;
        g_aa_cooperate_terminate0
    }
};
// cooperate TE_ADS_TERMINATE end
// cooperate TE_ADS_READY start
Ts_StateDepend g_aa_cooperate_ready0[] =
{
    {
        //uint16_t module_id;
        Te_ModuleIdentify_Cybertron,
        //uint16_t state_id;
        TE_ADS_READY,
        TE_ADS_READY
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_VCI,
        //uint16_t state_id;
        TE_ADS_READY,
        TE_ADS_READY
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_LeanControl,
        //uint16_t state_id;
        Te_lean_s_ready,
        Te_lean_s_ready
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_LeanLocalization,
        //uint16_t state_id;
        TE_ADS_READY,
        TE_ADS_READY
    },
};
Ts_CooperateStep g_aa_cooperate_ready[] =
{
    {
        //uint8_t step;
        0,
        //uint8_t buff_count;
        4,
        //Ts_ModuleStatePair* buff_depend;
        g_aa_cooperate_ready0
    }
};
// cooperate TE_ADS_READY end
// cooperate TE_ADS_ADPREPARE start
Ts_StateDepend g_aa_cooperate_adprepare0[] =
{
    {
        //uint16_t module_id;
        Te_ModuleIdentify_Cybertron,
        //uint16_t state_id;
        TE_ADS_ADPREPARE,
        TE_ADS_ADREADY
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_VCI,
        //uint16_t state_id;
        TE_ADS_ADPREPARE,
        TE_ADS_ADREADY
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_LeanControl,
        //uint16_t state_id;
        Te_lean_s_ready,
        Te_lean_s_ready
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_LeanLocalization,
        //uint16_t state_id;
        TE_ADS_ADPREPARE,
        TE_ADS_ADREADY
    },
};
Ts_CooperateStep g_aa_cooperate_adprepare[] =
{
    {
        //uint8_t step;
        0,
        //uint8_t buff_count;
        4,
        //Ts_ModuleStatePair* buff_depend;
        g_aa_cooperate_adprepare0
    }
};
// cooperate TE_ADS_ADPREPARE end

// cooperate TE_ADS_ADEXIT start
Ts_StateDepend g_aa_cooperate_adexit0[] =
{
    {
        //uint16_t module_id;
        Te_ModuleIdentify_Cybertron,
        //uint16_t state_id;
        TE_ADS_ADEXIT,
        TE_ADS_ADREADY
    },
   {
        //uint16_t module_id;
        Te_ModuleIdentify_VCI,
        //uint16_t state_id;
        TE_ADS_ADEXIT,
        TE_ADS_ADREADY
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_LeanControl,
        //uint16_t state_id;
        Te_lean_s_ready,
        Te_lean_s_ready
    },
    {
        //uint16_t module_id;
        Te_ModuleIdentify_LeanLocalization,
        //uint16_t state_id;
        TE_ADS_ADEXIT,
        TE_ADS_ADREADY
    }
};
Ts_CooperateStep g_aa_cooperate_adexit[] =
{
    {
        //uint8_t step;
        0,
        //uint8_t buff_count;
        4,
        //Ts_ModuleStatePair* buff_depend;
        g_aa_cooperate_adexit0
    }
};
// cooperate TE_ADS_ADEXIT end

// cooperate TE_ADS_ADREADY start
Ts_StateDepend g_aa_cooperate_adready0[] =
{
    {
        //uint16_t module_id;
        Te_ModuleIdentify_Cybertron,
        //uint16_t state_id;
        TE_ADS_ADREADY,
        TE_ADS_ADREADY
    },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_VCI,
       //uint16_t state_id;
       TE_ADS_ADREADY,
       TE_ADS_ADREADY
   },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_LeanControl,
       //uint16_t state_id;
       Te_lean_s_ready,
       Te_lean_s_ready
   },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_LeanLocalization,
       //uint16_t state_id;
       TE_ADS_ADREADY,
       TE_ADS_ADREADY
   }
};
Ts_CooperateStep g_aa_cooperate_adready[] =
{
    {
        //uint8_t step;
        0,
        //uint8_t buff_count;
        4,
        //Ts_ModuleStatePair* buff_depend;
        g_aa_cooperate_adready0
    }
};
// cooperate TE_ADS_ADREADY end

// cooperate TE_ADS_ADENGAGE start
Ts_StateDepend g_aa_cooperate_adengage0[] =
{
    {
        //uint16_t module_id;
        Te_ModuleIdentify_Cybertron,
        //uint16_t state_id;
        TE_ADS_ADENGAGE,
        TE_ADS_ADRUN
    },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_LeanControl,
       //uint16_t state_id;
       Te_lean_s_enable,
       Te_lean_s_run
   },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_LeanLocalization,
       //uint16_t state_id;
       TE_ADS_ADENGAGE,
        TE_ADS_ADRUN
   }
};
Ts_StateDepend g_aa_cooperate_adengage1[] =
{
   {
       //uint16_t module_id;
       Te_ModuleIdentify_VCI,
       //uint16_t state_id;
       TE_ADS_ADENGAGE,
        TE_ADS_ADRUN
   }
};
Ts_CooperateStep g_aa_cooperate_adengage[] =
{
    {
        //uint8_t step;
        0,
        //uint8_t buff_count;
        3,
        //Ts_ModuleStatePair* buff_depend;
        g_aa_cooperate_adengage0
    },
    {
        //uint8_t step;
        1,
        //uint8_t buff_count;
        1,
        //Ts_ModuleStatePair* buff_depend;
        g_aa_cooperate_adengage1
    }
};
// cooperate TE_ADS_ADENGAGE end

// cooperate TE_ADS_ADOFF start
Ts_StateDepend g_aa_cooperate_adoff0[] =
{
   {
        //uint16_t module_id;
        Te_ModuleIdentify_VCI,
        //uint16_t state_id;
        TE_ADS_ADOFF,
        TE_ADS_ADREADY
    }
};
Ts_StateDepend g_aa_cooperate_adoff1[] =
{
    {
        //uint16_t module_id;
        Te_ModuleIdentify_Cybertron,
        //uint16_t state_id;
        TE_ADS_ADOFF,
        TE_ADS_ADREADY
    },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_LeanControl,
       //uint16_t state_id;
       Te_lean_s_disable,
       Te_lean_s_ready
   },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_LeanLocalization,
       //uint16_t state_id;
       TE_ADS_ADOFF,
        TE_ADS_ADREADY
   }
};
Ts_CooperateStep g_aa_cooperate_adoff[] =
{
    {
        //uint8_t step;
        0,
        //uint8_t buff_count;
        1,
        //Ts_ModuleStatePair* buff_depend;
        g_aa_cooperate_adoff0
    },
    {
        //uint8_t step;
        1,
        //uint8_t buff_count;
        3,
        //Ts_ModuleStatePair* buff_depend;
        g_aa_cooperate_adoff1
    }
};
// cooperate TE_ADS_ADOFF end

// cooperate TE_ADS_ADRUN start
Ts_StateDepend g_aa_cooperate_adrun0[] =
{
    {
        //uint16_t module_id;
        Te_ModuleIdentify_Cybertron,
        //uint16_t state_id;
        TE_ADS_ADRUN,
        TE_ADS_ADRUN
    },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_VCI,
       //uint16_t state_id;
       TE_ADS_ADRUN,
        TE_ADS_ADRUN
   },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_LeanControl,
       //uint16_t state_id;
       Te_lean_s_run,
       Te_lean_s_run
   },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_LeanLocalization,
       //uint16_t state_id;
       TE_ADS_ADRUN,
        TE_ADS_ADRUN
   }
};
Ts_CooperateStep g_aa_cooperate_adrun[] =
{
    {
        //uint8_t step;
        0,
        //uint8_t buff_count;
        4,
        //Ts_ModuleStatePair* buff_depend;
        g_aa_cooperate_adrun0
    }
};
// cooperate TE_ADS_ADRUN end

// cooperate TE_ADS_FALLBACK start
Ts_StateDepend g_aa_cooperate_fallback0[] =
{
    {
        //uint16_t module_id;
        Te_ModuleIdentify_Cybertron,
        //uint16_t state_id;
        TE_ADS_FALLBACK,
        TE_ADS_FALLBACK
    },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_VCI,
       //uint16_t state_id;
       TE_ADS_FALLBACK,
       TE_ADS_FALLBACK
   },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_LeanControl,
       //uint16_t state_id;
       Te_lean_s_run,
       Te_lean_s_run
   },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_LeanLocalization,
       //uint16_t state_id;
       TE_ADS_FALLBACK,
       TE_ADS_FALLBACK
   }
};
Ts_CooperateStep g_aa_cooperate_fallback[] =
{
    {
        //uint8_t step;
        0,
        //uint8_t buff_count;
        4,
        //Ts_ModuleStatePair* buff_depend;
        g_aa_cooperate_fallback0
    }
};
// cooperate TE_ADS_FALLBACK end

// cooperate TE_ADS_MRC start
Ts_StateDepend g_aa_cooperate_mrc0[] =
{
    {
        //uint16_t module_id;
        Te_ModuleIdentify_Cybertron,
        //uint16_t state_id;
        TE_ADS_MRC,
        TE_ADS_MRC
    },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_VCI,
       //uint16_t state_id;
       TE_ADS_MRC,
       TE_ADS_MRC
   },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_LeanControl,
       //uint16_t state_id;
       Te_lean_s_run,
       Te_lean_s_run
   },
   {
       //uint16_t module_id;
       Te_ModuleIdentify_LeanLocalization,
       //uint16_t state_id;
       TE_ADS_MRC,
       TE_ADS_MRC
   }
};
Ts_CooperateStep g_aa_cooperate_mrc[] =
{
    {
        //uint8_t step;
        0,
        //uint8_t buff_count;
        4,
        //Ts_ModuleStatePair* buff_depend;
        g_aa_cooperate_mrc0
    }
};
// cooperate TE_ADS_MRC end

Ts_StateCooperate g_aa_cooperate[] =
{
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_IDLE,
        //Te_StateCooperateStyle style;
        Te_StateCooperateStyle_Steady,
        //uint8_t step_count;
        1,
        //Ts_CooperateStep* buff_step;
        & g_aa_cooperate_idle,
        //uint8_t step_pos;
        0,
        //Te_StateCooperateResult step_result;
        Te_StateCooperateResultSucc,
        //uint8_t cooperate_fail_limit;
        MaxLimit_Cooperate_Fail,
        //uint8_t cooperate_fail_count;
        0
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_INIT,
        //Te_StateCooperateStyle style;
        Te_StateCooperateStyle_Negotiating,
        //uint8_t step_count;
        1,
        //Ts_CooperateStep* buff_step;
        &g_aa_cooperate_init,
        //uint8_t step_pos;
        0,
        //Te_StateCooperateResult step_result;
        Te_StateCooperateResultSucc,
        //uint8_t cooperate_fail_limit;
        MaxLimit_Cooperate_Fail,
        //uint8_t cooperate_fail_count;
        0
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_TERMINATE,
        //Te_StateCooperateStyle style;
        Te_StateCooperateStyle_Negotiating,
        //uint8_t step_count;
        1,
        //Ts_CooperateStep* buff_step;
        &g_aa_cooperate_terminate,
        //uint8_t step_pos;
        0,
        //Te_StateCooperateResult step_result;
        Te_StateCooperateResultSucc,
        //uint8_t cooperate_fail_limit;
        MaxLimit_Cooperate_Fail,
        //uint8_t cooperate_fail_count;
        0
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_READY,
        //Te_StateCooperateStyle style;
        Te_StateCooperateStyle_Steady,
        //uint8_t step_count;
        1,
        //Ts_CooperateStep* buff_step;
        &g_aa_cooperate_ready,
        //uint8_t step_pos;
        0,
        //Te_StateCooperateResult step_result;
        Te_StateCooperateResultSucc,
        //uint8_t cooperate_fail_limit;
        MaxLimit_Cooperate_Fail,
        //uint8_t cooperate_fail_count;
        0
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_ADPREPARE,
        //Te_StateCooperateStyle style;
        Te_StateCooperateStyle_Negotiating,
        //uint8_t step_count;
        1,
        //Ts_CooperateStep* buff_step;
        &g_aa_cooperate_adprepare,
        //uint8_t step_pos;
        0,
        //Te_StateCooperateResult step_result;
        Te_StateCooperateResultSucc,
        //uint8_t cooperate_fail_limit;
        MaxLimit_Cooperate_Fail,
        //uint8_t cooperate_fail_count;
        0
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_ADEXIT,
        //Te_StateCooperateStyle style;
        Te_StateCooperateStyle_Negotiating,
        //uint8_t step_count;
        1,
        //Ts_CooperateStep* buff_step;
        &g_aa_cooperate_adexit,
        //uint8_t step_pos;
        0,
        //Te_StateCooperateResult step_result;
        Te_StateCooperateResultSucc,
        //uint8_t cooperate_fail_limit;
        MaxLimit_Cooperate_Fail,
        //uint8_t cooperate_fail_count;
        0
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_ADREADY,
        //Te_StateCooperateStyle style;
        Te_StateCooperateStyle_Steady,
        //uint8_t step_count;
        1,
        //Ts_CooperateStep* buff_step;
        &g_aa_cooperate_adready,
        //uint8_t step_pos;
        0,
        //Te_StateCooperateResult step_result;
        Te_StateCooperateResultSucc,
        //uint8_t cooperate_fail_limit;
        MaxLimit_Cooperate_Fail,
        //uint8_t cooperate_fail_count;
        0
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_ADENGAGE,
        //Te_StateCooperateStyle style;
        Te_StateCooperateStyle_Negotiating,
        //uint8_t step_count;
        2,
        //Ts_CooperateStep* buff_step;
        &g_aa_cooperate_adengage,
        //uint8_t step_pos;
        0,
        //Te_StateCooperateResult step_result;
        Te_StateCooperateResultSucc,
        //uint8_t cooperate_fail_limit;
        MaxLimit_Cooperate_Fail,
        //uint8_t cooperate_fail_count;
        0
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_ADOFF,
        //Te_StateCooperateStyle style;
        Te_StateCooperateStyle_Negotiating,
        //uint8_t step_count;
        2,
        //Ts_CooperateStep* buff_step;
        &g_aa_cooperate_adoff,
        //uint8_t step_pos;
        0,
        //Te_StateCooperateResult step_result;
        Te_StateCooperateResultSucc,
        //uint8_t cooperate_fail_limit;
        MaxLimit_Cooperate_Fail,
        //uint8_t cooperate_fail_count;
        0
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_ADRUN,
        //Te_StateCooperateStyle style;
        Te_StateCooperateStyle_Steady,
        //uint8_t step_count;
        1,
        //Ts_CooperateStep* buff_step;
        &g_aa_cooperate_adrun,
        //uint8_t step_pos;
        0,
        //Te_StateCooperateResult step_result;
        Te_StateCooperateResultSucc,
        //uint8_t cooperate_fail_limit;
        MaxLimit_Cooperate_Fail,
        //uint8_t cooperate_fail_count;
        0
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_FALLBACK,
        //Te_StateCooperateStyle style;
        Te_StateCooperateStyle_Steady,
        //uint8_t step_count;
        1,
        //Ts_CooperateStep* buff_step;
        &g_aa_cooperate_fallback,
        //uint8_t step_pos;
        0,
        //Te_StateCooperateResult step_result;
        Te_StateCooperateResultSucc,
        //uint8_t cooperate_fail_limit;
        MaxLimit_Cooperate_Fail,
        //uint8_t cooperate_fail_count;
        0
    },
    {
        //T_StateIdentify_i8 state_self;
        TE_ADS_MRC,
        //Te_StateCooperateStyle style;
        Te_StateCooperateStyle_Steady,
        //uint8_t step_count;
        1,
        //Ts_CooperateStep* buff_step;
        &g_aa_cooperate_mrc,
        //uint8_t step_pos;
        0,
        //Te_StateCooperateResult step_result;
        Te_StateCooperateResultSucc,
        //uint8_t cooperate_fail_limit;
        MaxLimit_Cooperate_Fail,
        //uint8_t cooperate_fail_count;
        0
    }
};
// cooperate TE_ADS_IDLE finish
Ts_StateManager g_aa_buff_state[] =
{
    {
        //T_StateIdentify_i8 state_id;
        TE_ADS_IDLE,
        //T_StateIdentify_i8 finish_dest;
        TE_ADS_IDLE,
        //T_StateIdentify_i8 except_dest;
        TE_ADS_IDLE,
        //Ts_StateTask* state_begin;
        NULL,
        //Ts_StateException* exception;   
        & g_aa_exception[TE_ADS_IDLE],
        //Ts_StateCooperate* cooperate;
        & g_aa_cooperate[TE_ADS_IDLE],
        //Ts_StateTask* polling_head;
        NULL,
        //Ts_StateTask* polling_tail;
        NULL,
    },
    {
        //T_StateIdentify_i8 state_id;
        TE_ADS_INIT,
        //T_StateIdentify_i8 finish_dest;
        TE_ADS_READY,
        //T_StateIdentify_i8 except_dest;
        TE_ADS_TERMINATE,
        //Ts_StateTask* state_begin;
        NULL,
        //Ts_StateException* exception;   
        &g_aa_exception[TE_ADS_INIT],
        //Ts_StateCooperate* cooperate;
        &g_aa_cooperate[TE_ADS_INIT],
        //Ts_StateTask* polling_head;
        NULL,
        //Ts_StateTask* polling_tail;
        NULL,
    },
    {
        //T_StateIdentify_i8 state_id;
        TE_ADS_TERMINATE,
        //T_StateIdentify_i8 finish_dest;
        TE_ADS_IDLE,
        //T_StateIdentify_i8 except_dest;
        TE_ADS_TERMINATE,
        //Ts_StateTask* state_begin;
        NULL,
        //Ts_StateException* exception;   
        &g_aa_exception[TE_ADS_TERMINATE],
        //Ts_StateCooperate* cooperate;
        &g_aa_cooperate[TE_ADS_TERMINATE],
        //Ts_StateTask* polling_head;
        NULL,
        //Ts_StateTask* polling_tail;
        NULL,
    },
    {
        //T_StateIdentify_i8 state_id;
        TE_ADS_READY,
        //T_StateIdentify_i8 finish_dest;
        TE_ADS_READY,
        //T_StateIdentify_i8 except_dest;
        TE_ADS_TERMINATE,
        //Ts_StateTask* state_begin;
        NULL,
        //Ts_StateException* exception;   
        &g_aa_exception[TE_ADS_READY],
        //Ts_StateCooperate* cooperate;
        &g_aa_cooperate[TE_ADS_READY],
        //Ts_StateTask* polling_head;
        NULL,
        //Ts_StateTask* polling_tail;
        NULL,
    },
    {
        //T_StateIdentify_i8 state_id;
        TE_ADS_ADPREPARE,
        //T_StateIdentify_i8 finish_dest;
        TE_ADS_ADREADY,
        //T_StateIdentify_i8 except_dest;
        TE_ADS_ADEXIT,
        //Ts_StateTask* state_begin;
        NULL,
        //Ts_StateException* exception;   
        &g_aa_exception[TE_ADS_ADPREPARE],
        //Ts_StateCooperate* cooperate;
        &g_aa_cooperate[TE_ADS_ADPREPARE],
        //Ts_StateTask* polling_head;
        NULL,
        //Ts_StateTask* polling_tail;
        NULL,
    },
    {
        //T_StateIdentify_i8 state_id;
        TE_ADS_ADEXIT,
        //T_StateIdentify_i8 finish_dest;
        TE_ADS_READY,
        //T_StateIdentify_i8 except_dest;
        TE_ADS_ADEXIT,
        //Ts_StateTask* state_begin;
        NULL,
        //Ts_StateException* exception;   
        &g_aa_exception[TE_ADS_ADEXIT],
        //Ts_StateCooperate* cooperate;
        &g_aa_cooperate[TE_ADS_ADEXIT],
        //Ts_StateTask* polling_head;
        NULL,
        //Ts_StateTask* polling_tail;
        NULL,
    },
    {
        //T_StateIdentify_i8 state_id;
        TE_ADS_ADREADY,
        //T_StateIdentify_i8 finish_dest;
        TE_ADS_ADREADY,
        //T_StateIdentify_i8 except_dest;
        TE_ADS_ADPREPARE,
        //Ts_StateTask* state_begin;
        NULL,
        //Ts_StateException* exception;   
        &g_aa_exception[TE_ADS_ADREADY],
        //Ts_StateCooperate* cooperate;
        &g_aa_cooperate[TE_ADS_ADREADY],
        //Ts_StateTask* polling_head;
        NULL,
        //Ts_StateTask* polling_tail;
        NULL,
    },
    {
        //T_StateIdentify_i8 state_id;
        TE_ADS_ADENGAGE,
        //T_StateIdentify_i8 finish_dest;
        TE_ADS_ADRUN,
        //T_StateIdentify_i8 except_dest;
        TE_ADS_FALLBACK,
        //Ts_StateTask* state_begin;
        NULL,
        //Ts_StateException* exception;   
        &g_aa_exception[TE_ADS_ADENGAGE],
        //Ts_StateCooperate* cooperate;
        &g_aa_cooperate[TE_ADS_ADENGAGE],
        //Ts_StateTask* polling_head;
        NULL,
        //Ts_StateTask* polling_tail;
        NULL,
    },
    {
        //T_StateIdentify_i8 state_id;
        TE_ADS_ADOFF,
        //T_StateIdentify_i8 finish_dest;
        TE_ADS_ADPREPARE,
        //T_StateIdentify_i8 except_dest;
        TE_ADS_FALLBACK,
        //Ts_StateTask* state_begin;
        NULL,
        //Ts_StateException* exception;   
        &g_aa_exception[TE_ADS_ADOFF],
        //Ts_StateCooperate* cooperate;
        &g_aa_cooperate[TE_ADS_ADOFF],
        //Ts_StateTask* polling_head;
        NULL,
        //Ts_StateTask* polling_tail;
        NULL,
    },
    {
        //T_StateIdentify_i8 state_id;
        TE_ADS_ADRUN,
        //T_StateIdentify_i8 finish_dest;
        TE_ADS_ADRUN,
        //T_StateIdentify_i8 except_dest;
        TE_ADS_FALLBACK,
        //Ts_StateTask* state_begin;
        NULL,
        //Ts_StateException* exception;   
        &g_aa_exception[TE_ADS_ADRUN],
        //Ts_StateCooperate* cooperate;
        &g_aa_cooperate[TE_ADS_ADRUN],
        //Ts_StateTask* polling_head;
        NULL,
        //Ts_StateTask* polling_tail;
        NULL,
    },
    {
        //T_StateIdentify_i8 state_id;
        TE_ADS_FALLBACK,
        //T_StateIdentify_i8 finish_dest;
        TE_ADS_MRC,
        //T_StateIdentify_i8 except_dest;
        TE_ADS_FALLBACK,
        //Ts_StateTask* state_begin;
        NULL,
        //Ts_StateException* exception;   
        &g_aa_exception[TE_ADS_FALLBACK],
        //Ts_StateCooperate* cooperate;
        &g_aa_cooperate[TE_ADS_FALLBACK],
        //Ts_StateTask* polling_head;
        NULL,
        //Ts_StateTask* polling_tail;
        NULL,
    },
    {
        //T_StateIdentify_i8 state_id;
        TE_ADS_MRC,
        //T_StateIdentify_i8 finish_dest;
        TE_ADS_MRC,
        //T_StateIdentify_i8 except_dest;
        TE_ADS_MRC,
        //Ts_StateTask* state_begin;
        NULL,
        //Ts_StateException* exception;   
        &g_aa_exception[TE_ADS_MRC],
        //Ts_StateCooperate* cooperate;
        &g_aa_cooperate[TE_ADS_MRC],
        //Ts_StateTask* polling_head;
        NULL,
        //Ts_StateTask* polling_tail;
        NULL,
    }
};
Ts_StateJumpMap g_aa_state_jump_map = { 0 };
Ts_StateMachine g_aa_sm =
{
    //uint16_t state_machine_id;
    Te_ModuleIdentify_AA,
    //int state_count;
    TE_ADS_COUNT,
    //int default_state_id;         
    TE_ADS_IDLE,
    //Ts_StateManager * buff_state_manager;     
    g_aa_buff_state,
    //Ts_StateJumpMap * map;
    & g_aa_state_jump_map,
    //int prev_state;
    0,
    //int current_state;
    0,
    //int request_state;
    0
};

#endif