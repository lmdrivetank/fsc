//
// Copyright 2020 Inceptio Technology. All Rights Reserved.
//

#include "FreeRTOS.h"
#include "task.h"

#include "can_driver.h"
#include "axep_driver.h"
#include "axep_stack.h"
#include "j1939_protocol_stack.h"
#include "can_switch.h"

#define USE_STATIC_ALLOC

#define MAX_MSG_SIZE      102
#define AXEP_BUF_CNT      64
#define CAN_RX_MSG_CNT    10

#if 0
typedef struct {
    uint8_t channel;
    int64_t id;
    uint64_t time_stamp;
    bool extended;
    uint8_t msg_len;
    uint8_t msg[MAX_MSG_SIZE];
}CAN_MSG_S;
#endif

typedef struct {
    TaskHandle_t axep_recv_task_handle;
    TaskHandle_t axep_send_task_handle;
    TaskHandle_t can_recv_task_handle;
    TaskHandle_t can_send_task_handle;
#ifdef USE_STATIC_ALLOC
    StackType_t axep_recv_task_stack[1024];
    StackType_t axep_send_task_stack[1024];
    StackType_t can_recv_task_stack[1024];
    StackType_t can_send_task_stack[1024];
    StaticTask_t axep_recv_task_buf;
    StaticTask_t axep_send_task_buf;
    StaticTask_t can_recv_task_buf;
    StaticTask_t can_send_task_buf;
#endif
    bool axep_task_active;
    bool can_task_active;
    uint8_t axep_recv_buf[AXEP_BUF_CNT][MAX_MSG_SIZE];
    // Also for CAN receive
    uint8_t axep_send_buf[AXEP_BUF_CNT][MAX_MSG_SIZE];
    uint8_t axep_recv_widx;
    uint8_t axep_recv_ridx;
    uint8_t axep_snd_widx;
    uint8_t axep_snd_ridx;
}CAN_SWITCH_CONTEXT_S;
CAN_SWITCH_CONTEXT_S g_can_switch_context;


static void AxepRecvTask(void *param) {
    AXEP_Msg_S rxMsg;
    uint32_t list_size = 0;

    // Receive AXEP data
    while (g_can_switch_context.axep_task_active) {
        list_size = 1;
        rxMsg.data = g_can_switch_context.axep_recv_buf[g_can_switch_context.axep_recv_widx];
        if (AXEP_DRIVER_STATUS_OK
            == AxepDriverRead(AXEP_MSG_TYPE_CANMSG, &list_size, &rxMsg)) {
            g_can_switch_context.axep_recv_widx =
                (g_can_switch_context.axep_recv_widx + 1) % AXEP_BUF_CNT;
        }
    }
}

static void AxepSendTask(void *param) {
    AXEP_Msg_S txMsg = {NULL, (uint8_t)(sizeof(J1939_Message_S) + 1)};

    // Send AXEP data
    while (g_can_switch_context.axep_task_active) {
        // Start sending if CAN data prepared
        if (g_can_switch_context.axep_snd_ridx == g_can_switch_context.axep_snd_widx) {
            continue;
        }

        txMsg.data = g_can_switch_context.axep_send_buf[g_can_switch_context.axep_snd_ridx];
        if (AXEP_DRIVER_STATUS_OK
            == AxepDriverWrite(AXEP_MSG_TYPE_CANMSG, &txMsg, 10)) {
            g_can_switch_context.axep_snd_ridx =
                (g_can_switch_context.axep_snd_ridx + 1) % AXEP_BUF_CNT;
        }
    }
}

static void CanRecvTask(void *param) {
    J1939_Message_S *p_can_msg = NULL;
    CAN_RAW_Message_S raw_can_msg = {0};
    Can_Msg_S rxMsg[CAN_RX_MSG_CNT];
    uint32_t input_len = sizeof(J1939_Message_S);
    uint32_t output_len = 0;
    uint8_t list_size = 0;
    uint8_t j1939_output_size = 0;
    uint8_t i = 0;

    // Receive CAN data
    while (g_can_switch_context.can_task_active) {
        list_size = CAN_RX_MSG_CNT;
        if (CAN_STATUS_OK
            == CanReadSync(rxMsg, &list_size, 5)) {
            if (0 == list_size) {
                continue;
            }

            i = 0;
            do {
                p_can_msg = (J1939_Message_S *)(g_can_switch_context.axep_send_buf[g_can_switch_context.axep_snd_widx] + 1);

                // J1939 process
                raw_can_msg.channel = rxMsg[i].chnID;
                raw_can_msg.can_id = rxMsg[i].id;
                raw_can_msg.size = rxMsg[i].dlc;
                memcpy(raw_can_msg.data, rxMsg[i].msg, raw_can_msg.size);
                // Mock timestamp
                raw_can_msg.time_stamp = 0;
                raw_can_msg.extended = (bool)rxMsg[i].extended;
                J1939_Protocol_Stack_Receive(&raw_can_msg, p_can_msg, &j1939_output_size);

                // AXEP encode
                AxepEncodeMessage(AXEP_MSG_ID_CANMSG,
                    (uint8_t *)p_can_msg, input_len,
                    g_can_switch_context.axep_send_buf[g_can_switch_context.axep_snd_widx],
                    &output_len);

                g_can_switch_context.axep_snd_widx =
                    (g_can_switch_context.axep_snd_widx + 1) % AXEP_BUF_CNT;
            } while (++i != list_size);
        }
    }
}

static void CanSendTask(void *param) {
    J1939_Message_S *p_can_msg = NULL;
    CAN_RAW_Message_S raw_can_msg;
    Can_Msg_S txMsg;
    uint32_t input_len = sizeof(J1939_Message_S) + 1;
    uint32_t output_len = 0;
    uint8_t j1939_output_size = 0;
    uint8_t msg_id = 0;

    // Send CAN data
    while (g_can_switch_context.can_task_active) {
        // Start sending if AXEP data prepared
        if (g_can_switch_context.axep_recv_ridx == g_can_switch_context.axep_recv_widx) {
            continue;
        }

        p_can_msg = (J1939_Message_S *)(g_can_switch_context.axep_recv_buf[g_can_switch_context.axep_recv_ridx] + 1);
        // AXEP decode
        AxepDecodeMessage(&msg_id,
            g_can_switch_context.axep_recv_buf[g_can_switch_context.axep_recv_ridx],
            input_len,
            (uint8_t *)p_can_msg, &output_len);

        // J1939 process
        J1939_Protocol_Stack_Write(p_can_msg, &raw_can_msg, &j1939_output_size);
        txMsg.chnID = raw_can_msg.channel;
        txMsg.id = raw_can_msg.can_id;
        txMsg.dlc = raw_can_msg.size;
        memcpy(txMsg.msg, raw_can_msg.data, txMsg.dlc);
        txMsg.extended = (uint8_t)raw_can_msg.extended;

        if (CAN_STATUS_OK == CanWrite(&txMsg)) {
            g_can_switch_context.axep_recv_ridx =
                (g_can_switch_context.axep_recv_ridx + 1) % AXEP_BUF_CNT;
        }
    }
}

Can_Switch_Status_E CanSwichTaskCreate(void) {
    // Create AXEP task
    g_can_switch_context.axep_task_active = 1;
#ifndef USE_STATIC_ALLOC
    if (pdPASS != xTaskCreate(AxepRecvTask, "AXEPRecvTask", 2048, NULL, 2,
                              &g_can_switch_context.axep_recv_task_handle))
    {
        printf("AXEP recv task create failed");
        return CAN_SWITCH_STATUS_InitFailed;
    }
    if (pdPASS != xTaskCreate(AxepSendTask, "AXEPSendTask", 2048, NULL, 2,
                              &g_can_switch_context.axep_send_task_handle))
    {
        printf("AXEP send task create failed");
        return CAN_SWITCH_STATUS_InitFailed;
    }
#else
    g_can_switch_context.axep_recv_task_handle
        = xTaskCreateStatic(AxepRecvTask, "AXEPRecvTask", 1024, NULL, 2,
                            g_can_switch_context.axep_recv_task_stack,
                            &g_can_switch_context.axep_recv_task_buf);
    g_can_switch_context.axep_send_task_handle
        = xTaskCreateStatic(AxepSendTask, "AXEPSendTask", 1024, NULL, 2,
                            g_can_switch_context.axep_send_task_stack,
                            &g_can_switch_context.axep_send_task_buf);
#endif

    // Create CAN task
    g_can_switch_context.can_task_active = 1;
#ifndef USE_STATIC_ALLOC
    if (pdPASS != xTaskCreate(CanRecvTask, "CANRecvTask", 2048, NULL, 2,
                              &g_can_switch_context.can_recv_task_handle))
    {
        printf("CAN recv task create failed");
        return CAN_SWITCH_STATUS_InitFailed;
    }
    if (pdPASS != xTaskCreate(CanSendTask, "CANSendTask", 2048, NULL, 2,
                              &g_can_switch_context.can_send_task_handle))
    {
        printf("CAN send task create failed");
        return CAN_SWITCH_STATUS_InitFailed;
    }
#else
    g_can_switch_context.can_recv_task_handle
        = xTaskCreateStatic(CanRecvTask, "CANRecvTask", 1024, NULL, 2,
                            g_can_switch_context.can_recv_task_stack,
                            &g_can_switch_context.can_recv_task_buf);
    g_can_switch_context.can_send_task_handle
        = xTaskCreateStatic(CanSendTask, "CANSendTask", 1024, NULL, 2,
                            g_can_switch_context.can_send_task_stack,
                            &g_can_switch_context.can_send_task_buf);
#endif

    return CAN_SWITCH_STATUS_OK;
}

Can_Switch_Status_E CanSwichInit(void) {
    // Init resource
    memset(&g_can_switch_context, 0, sizeof(CAN_SWITCH_CONTEXT_S));

    // Open AXEP Device
    AxepDriverOpen();

    // Init J1939 protocol stack
    J1939_Protocol_Stack_Init();

    // Create task
    if (CAN_SWITCH_STATUS_OK != CanSwichTaskCreate())
    {
        printf("CAN switch task create failed");
        return CAN_SWITCH_STATUS_InitFailed;
    }

    return CAN_SWITCH_STATUS_OK;
}

Can_Switch_Status_E CanSwichRelease(void) {
    g_can_switch_context.can_task_active = 0;
    if (g_can_switch_context.can_recv_task_handle)
    {
        vTaskDelete(g_can_switch_context.can_recv_task_handle);
        g_can_switch_context.can_recv_task_handle = NULL;
    }
    if (g_can_switch_context.can_send_task_handle)
    {
        vTaskDelete(g_can_switch_context.can_send_task_handle);
        g_can_switch_context.can_send_task_handle = NULL;
    }

    g_can_switch_context.axep_task_active = 0;
    if (g_can_switch_context.axep_recv_task_handle)
    {
        vTaskDelete(g_can_switch_context.axep_recv_task_handle);
        g_can_switch_context.axep_recv_task_handle = NULL;
    }
    if (g_can_switch_context.axep_send_task_handle)
    {
        vTaskDelete(g_can_switch_context.axep_send_task_handle);
        g_can_switch_context.axep_send_task_handle = NULL;
    }

    return CAN_SWITCH_STATUS_OK;
}

