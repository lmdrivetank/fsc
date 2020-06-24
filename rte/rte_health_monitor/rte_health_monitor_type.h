#pragma once

#include "rte_type.h"

#define MaxFallCount 100
typedef enum
{
    Te_FallbackLevel_None,
    Te_FallbackLevel_A,
    Te_FallbackLevel_B,
    Te_FallbackLevel_C,
    Te_FallbackLevel_D,
    Te_FallbackLevel_E
}Te_FallbackLevel;
typedef uint8_t Te_FallbackLevel_u8;

typedef struct
{
    Te_FallbackLevel_u8 level;
    int detail;
} FaultInfo_S;

typedef struct
{
    bool is_health;
    Te_FallbackLevel_u8 level_max;
    FaultInfo_S fall_info[MaxFallCount];
} HealthInfo_S;