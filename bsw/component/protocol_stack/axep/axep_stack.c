//
// Copyright 2020 Inceptio Technology. All Rights Reserved.
//

#include "axep_stack.h"

Axep_Status_E AxepEncodeMessage(uint8_t msg_id,
              const uint8_t *input, uint32_t input_len,
              uint8_t *output, uint32_t *output_len) {
    if (NULL == input || input_len <= 0
        || NULL == output || output_len <= 0
        || *output_len < input_len + 1) {
        return AXEP_STATUS_NULL_PARAM_OR_WRONG_LENGTH;
    }

    *output_len = input_len + 1;
    *output = msg_id;
    if (output + 1 != input) {
        memmove(output + 1, input, input_len);
    }

    return AXEP_STATUS_OK;
}

Axep_Status_E AxepDecodeMessage(uint8_t *msg_id,
              const uint8_t *input, uint32_t input_len,
              uint8_t *output, uint32_t *output_len) {
    if (NULL == input || input_len <= 0
        || NULL == output || output_len <= 0
        || *output_len < input_len - 1) {
        return AXEP_STATUS_NULL_PARAM_OR_WRONG_LENGTH;
    }

    if (*input > AXEP_MSG_ID_MAX) {
        return AXEP_STATUS_INVALID_INPUT_DATA;
    }

    *msg_id = *input;
    *output_len = input_len - 1;
    if (output != input + 1) {
        memmove(output, input + 1, *output_len);
    }

    return AXEP_STATUS_OK;
}
