//
// Copyright 2020 Inceptio Technology. All Rights Reserved.
//

#include <j1939_protocol_stack.h>
#include "j1939_protocol_stack_internal.h"

#include <string.h>

#define J1939_PS_CACHE_SIZE 50

J1939_Message_S j1939_ps_cache[J1939_PS_CACHE_SIZE];
int j1939_ps_cache_pointer;
int j1939_ps_cache_count;

void J1939_Protocol_Stack_Init() {
	memset(&j1939_ps_cache, 0, sizeof(J1939_Message_S) * J1939_PS_CACHE_SIZE);
	j1939_ps_cache_pointer = 0;
	j1939_ps_cache_count = 0;
}

int J1939_Protocol_Stack_Receive(const CAN_RAW_Message_S* in_message, J1939_Message_S* ret_message, uint8_t* size) {
	int i = 0;
	if (*size < 1) {
		*size = 0;
		return 0;
	}
	ret_message[0].can_id = in_message->can_id;
	ret_message[0].channel = in_message->channel;
	ret_message[0].size = in_message->size;
	ret_message[0].time_stamp = in_message->time_stamp;
	ret_message[0].status = J1939_MSG_STATUS_OK;
	for (i = 0; i < in_message->size; i++) {
		ret_message[0].data[i] = in_message->data[i];
	}
	return 0;
}

bool J1939_Protocol_Stack_Write(const J1939_Message_S* in_message, CAN_RAW_Message_S* ret_message, uint8_t* size) {
	int raw_message_size = (in_message->size / 7) + (in_message->size % 7 == 0 ? 0 : 1);
	int index, i = 0;
	if (*size < raw_message_size) {
		return false;
	}
	if (*size <= 8) {
		for (index = 0; index < raw_message_size; index++) {
			ret_message[index].can_id = in_message->can_id;
			ret_message[index].channel = in_message->channel;
			for (i = 0; i < *size; i++) {
				ret_message[index].data[i] = in_message->data[i];
			}
			ret_message[index].size = in_message->size;
			ret_message[index].time_stamp = in_message->time_stamp;
			ret_message->extended = true;
		}
	}
	return true;
}



