#pragma once

#include  "rte_type.h"


//////////////////
typedef uint8_t Te_PollingResult_u8;
#define Te_PollingResult_Continue           (0x01)
#define Te_PollingResult_Break              (0x02)
#define Te_PollingResult_Finish             (0x03)
#define Te_PollingResult_Hold               (0x04)
//////////////////

typedef uint16_t Te_ModuleIdentify_u16;
#define Te_ModuleIdentify_Operator      0
#define Te_ModuleIdentify_HMI           1
#define Te_ModuleIdentify_AA            2
#define Te_ModuleIdentify_Cybertron     3
#define Te_ModuleIdentify_LeanControl   4
#define Te_ModuleIdentify_VCI           5
#define Te_ModuleIdentify_LeanLocalization  6
#define Te_ModuleIdentify_Count         7

typedef int8_t Te_StateIdentify_i8;
#define Te_StateIdentify_Idle           0


#define Macro_Module_Dead   100

typedef struct {
    uint16_t state_request;
    uint16_t state_current;
} Ts_StateContext;

typedef struct {
    bool heart_beating;
    bool heart_dead;
    uint32_t sleep_count;
}Ts_HeartBeatContext;

typedef struct {
    //uint32_t exception_type;
    uint8_t exception_level;
    uint8_t exception_count;
    uint8_t* plist_exception;
} Ts_ExceptionContext;

typedef struct {
    Ts_StateContext state;
    Ts_HeartBeatContext heart_beat;
    Ts_ExceptionContext exception;
} Ts_ModuleContext;

typedef struct{
    Ts_ModuleContext buff_module[Te_ModuleIdentify_Count];
} Ts_ModuleManager;