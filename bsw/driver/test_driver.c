#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "axep_driver.h"
#include "can_driver.h"


/******************** Test AXP driver ***********************/
AXEP_Driver_Status_E AxepDriverOpen(void) {
    return AXEP_DRIVER_STATUS_OK;
}

AXEP_Driver_Status_E AxepDriverClose(void) {
    return AXEP_DRIVER_STATUS_OK;
}

bool GetAxepConnStatus(void) {
    return true;
}

AXEP_Driver_Status_E AxepDriverWrite(AXEP_MSG_TYPE_E msg_type,
                     const AXEP_Msg_S *txMsg, uint32_t timeout_ms) {
    return AXEP_DRIVER_STATUS_OK;
}

AXEP_Driver_Status_E AxepDriverRead(AXEP_MSG_TYPE_E msg_type,
                     uint32_t *list_size, AXEP_Msg_S *rxMsg_list) {
    return AXEP_DRIVER_STATUS_OK;
}


/******************** Test CAN driver ***********************/
CAN_Status_E CanOpen(const Channel_Parameter_S *channel_params) {
    return CAN_STATUS_OK;
}

CAN_Status_E CanClose(uint8_t channel_id) {
    return CAN_STATUS_OK;
}

bool IsCanOpen(uint8_t channel_id) {
    return true;
}

CAN_Status_E CanReadSync(Can_Msg_S *rxMsgList,
             uint8_t *listSize, uint32_t timeout_ms) {
    return CAN_STATUS_OK;
}

CAN_Status_E CanWrite(const Can_Msg_S *txMsg) {
    return CAN_STATUS_OK;
}


