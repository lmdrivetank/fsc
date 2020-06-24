//
// Copyright 2020 Inceptio Technology. All Rights Reserved.
//

#ifndef CAN_SWITCH_H_
#define CAN_SWITCH_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    CAN_SWITCH_STATUS_OK = 0,
    CAN_SWITCH_STATUS_InitFailed = 1,
    CAN_SWITCH_STATUS_ReleaseFailed = 2,
    CAN_SWITCH_STATUS_Unknown = 0xFFFF
}Can_Switch_Status_E;


// Initiaiize CAN switch app
Can_Switch_Status_E CanSwichInit(void);

// Release CAN switch app resource
Can_Switch_Status_E CanSwichRelease(void);

#endif  // CAN_SWITCH_H_

