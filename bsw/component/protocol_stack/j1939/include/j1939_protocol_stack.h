//
// Copyright 2020 Inceptio Technology. All Rights Reserved.
//

#ifndef J1939_PROTOCOL_STACK_
#define J1939_PROTOCOL_STACK_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef enum {
	J1939_MSG_STATUS_UNKNON = 0,
	J1939_MSG_STATUS_OK = 1,
	J1939_MSG_STATUS_TIMEOUT_OUT = 2,
	J1939_MSG_STATUS_OVER_FOLLOW = 3,
}J1939_Message_Status_E;

typedef struct {
	uint8_t channel;
	uint32_t can_id;
	uint8_t data[64];
	uint8_t size;
	int64_t time_stamp;
	J1939_Message_Status_E status;
}J1939_Message_S;

typedef struct {
	uint8_t channel;
	uint32_t can_id;
	uint8_t data[8];
	uint8_t size;
	int64_t time_stamp;
	bool extended;
}CAN_RAW_Message_S;

void J1939_Protocol_Stack_Init();

int J1939_Protocol_Stack_Receive(const CAN_RAW_Message_S* in_message, J1939_Message_S* ret_message, uint8_t* size);

bool J1939_Protocol_Stack_Write(const J1939_Message_S* in_message, CAN_RAW_Message_S* ret_message, uint8_t* size);

#endif