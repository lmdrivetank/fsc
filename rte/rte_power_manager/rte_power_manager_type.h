#pragma once

#include "rte_type.h"

typedef enum
{
	Te_CybertronRequest_PowerOn,
	Te_CybertronRequest_PowerOff
}Te_CybertronRequest_Power;
typedef uint8_t Te_CybertronRequest_Power_u8;

typedef enum
{
	Te_CybertronStatus_PowerOn,
	Te_CybertronStatus_PowerOff
}Te_CybertronStatus_Power;
typedef uint8_t Te_CybertronStatus_Power_u8;

typedef struct
{
	int a;
} Ts_PowerManagerHealthInfo;