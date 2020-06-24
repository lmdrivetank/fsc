//
// Copyright 2020 Inceptio Technology. All Rights Reserved.
//

#ifndef AXEP_STACK_H_
#define AXEP_STACK_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    AXEP_STATUS_OK = 0,
    AXEP_STATUS_NULL_PARAM_OR_WRONG_LENGTH = 1,
    AXEP_STATUS_INVALID_INPUT_DATA = 2,
    AXEP_STATUS_EncodeFailed = 3,
    AXEP_STATUS_DecodeFailed = 4,
    AXEP_STATUS_Unknown = 0xFFFF
}Axep_Status_E;

#define AXEP_MSG_ID_CANMSG      0
#define AXEP_MSG_ID_CANOPEN     1
#define AXEP_MSG_ID_CANCLOSE    2
#define AXEP_MSG_ID_OTA         3
#define AXEP_MSG_ID_SYS         4
#define AXEP_MSG_ID_MAX         AXEP_MSG_ID_SYS


// Encode AXEP Message.
// The minimum size of output buffer should be input_len+1
// Output message: 1 byte message length + input message
Axep_Status_E AxepEncodeMessage(uint8_t msg_id,
              const uint8_t *input, uint32_t input_len,
              uint8_t *output, uint32_t *output_len);

// Decode AXEP Message.
// The minimum size of output buffer should be input_len-1
Axep_Status_E AxepDecodeMessage(uint8_t *msg_id,
              const uint8_t *input, uint32_t input_len,
              uint8_t *output, uint32_t *output_len);

#endif  // AXEP_STACK_H_

