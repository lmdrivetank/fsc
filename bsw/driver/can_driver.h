//
// Copyright 2020 Inceptio Technology. All Rights Reserved.
//

#ifndef CAN_DRIVER_H_
#define CAN_DRIVER_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>



//For Classic CAN, it is 8
//For CAN FD,      it can be up to 64
#define CAN_PAYLOAD_LEN (8)

/*
  Data structure for CAN msg
*/
typedef struct {
	uint8_t  chnID;                 /*CAN channel ID */
	uint32_t id;                   /* CAN indentifier*/
    uint8_t  dlc ;                 /* CAN dlc (data length code)  
	                                   The lenghth of this message in bytes
	                                   For Classic CAN dlc can be at most 8.  For now our SW use Classic CAN
					                  For CAN FD dlc can be one of the following 0-8, 12, 16, 20, 24, 32, 48, 64*/
	uint8_t  msg[CAN_PAYLOAD_LEN]; /* can msg Data */
    uint8_t  extended;             /* 0 11-bit standard identifier, 1 29-bit extended identifier*/
} Can_Msg_S;


/* 
  Total number of Channel this ECU needs to use
  e,g 4 
  for Aurix in our ADU, it can up to 8
*/
#define TOTAL_NUM_CANCHN       4
 

/*
Below should be got from our App SW's configuration
e.g for MKZ car
   For now we use the number with the max CANIDs in a channel
*/
#define TOTAL_NUM_RXMSG        10



/*
Below global contant buffer needs to be defined in App SW when App SW is configured
 e.g for our MKZ car, it is c_listRxMsgId[0][10]= 
{0x10, 0x200, 0x204, 0x228, 0x22C, 0x400, 0x407, 0x40D, 0x419, 0x41A}
*/
extern const uint32_t c_listRxMsgId[TOTAL_NUM_CANCHN][TOTAL_NUM_RXMSG];

/* 
Below global variable buffer   needs to be defined in App SW when App SW is configured
*/
extern Can_Msg_S v_RxMsgBuf[TOTAL_NUM_CANCHN][TOTAL_NUM_RXMSG];



typedef enum {
  CAN_STATUS_OK = 0,
  CAN_STATUS_OpenFailed = 1,
  CAN_STATUS_BadParam = 2,
  CAN_STATUS_NoChannelFound = 3,
  CAN_STATUS_ChannelClosed = 4,
  CAN_STATUS_NoMessagesReceived = 5,
  CAN_STATUS_ReadFailed = 6,
  CAN_STATUS_WriteFailed = 7,
  CAN_STATUS_CloseFailed = 8,
  CAN_STATUS_CanMsgOverrun = 9,
  CAN_STATUS_Timeout = 10,
  CAN_STATUS_Error = 11,
  
  CAN_STATUS_Unknown = 0xFFFF
} CAN_Status_E;


// Channel description structure
typedef struct {
  uint8_t channel_id;
  uint32_t bit_rate;
  uint8_t  numberOfRxCanId;        //number of CAN IDs can read from this Channel
  const uint32_t *listRxCanId;     //list all of CAN IDs that can be received by this CAN channel
  uint8_t echo_on;
} Channel_Parameter_S;

// Called to pass in parameters and open a CAN channel
CAN_Status_E CanOpen(const Channel_Parameter_S *channel_params);


// Close a CAN channel
CAN_Status_E CanClose(uint8_t channel_id);

// Check to see if a CAN is open
bool IsCanOpen(uint8_t channel_id);


/*
 This function is to send a message to CAN bus
 Parameters

	[in] txMsg:       the msg that will write to CAN bus with "chnID, id, dlc, *msgData" in structure data.,       	
	
 Returns:
     CAN_STATUS_OK:           If the msg is sent successully with available CAN bus resource
     CAN_STATUS_WriteFailed:  If the msg has a failure to send the msg to the CAN bus, Such as Bus busy, Bus Off..etc	 
*/
CAN_Status_E CanWrite(const Can_Msg_S *txMsg);



/*
The function is to read all of available messages on CAN bus 
If no message is available, 
         the function waits until a message arrives or a timeout occurs if timeout_ms!=0; 
		 the function returns CAN_STATUS_NoMessagesReceived immediately if timeout_ms = 0 

Parameters
	[out] rxMsgList:  Pointer to a variable buffer which stores all of available messages  	
	[out]  listSize:  Pointer to a variable for how many messages is read in. 	                  
    [in]	timeout:  If no message is immediately available, 
	                     this parameter gives the number of milliseconds to wait for a message before returning to CAN_STATUS_Timeout 
						 0xFFFFFFFF gives an infinite timeout
						 0x0 lets the function return to CAN_STATUS_NoMessagesReceived immediately to not block the running process
						 
Returns
   CAN_STATUS_OK:                 If a message was read into msg buffer successully
   CAN_STATUS_Timeout:            If no message is available after waiting for timeout (!=0) ms.
   CAN_STATUS_NoMessagesReceived: If no message is available with timeout parameter is 0 
   CAN_STATUS_ReadFailed:         any other cause for read failure

   rxMsgList can be v_RxMsgBuf
*/
CAN_Status_E CanReadSync(Can_Msg_S *rxMsgList, uint8_t *listSize, uint32_t timeout_ms);


#endif  // CAN_DRIVER_H_
