//
// Copyright 2020 Inceptio Technology. All Rights Reserved.
//

#ifndef AXEP_DRIVER_H_
#define AXEP_DRIVER_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/*
 Data structure for AXEP msg
*/
typedef  struct
{
uint8_t   *data;
uint8_t    data_size;      
} AXEP_Msg_S;


typedef enum {
  AXEP_DRIVER_STATUS_OK = 0,
  AXEP_DRIVER_STATUS_WriteFailed = 1,
  AXEP_DRIVER_STATUS_NoDataReceived = 2,
  AXEP_DRIVER_STATUS_ReadFailed = 3,
  AXEP_DRIVER_STATUS_OpenFailed = 4,

  AXEP_DRIVER_STATUS_Unknown = 0xFFFF
} AXEP_Driver_Status_E;


/* 
   Define msg types based on AXEP driver usage
   Msg types can be more than these per request
*/
typedef enum {
	AXEP_MSG_TYPE_CANMSG =0,
	AEXP_MSG_TYPE_CANOPEN = 1,
	AEXP_MSG_TYPE_CANCLOSE = 2,
	AXEP_MSG_TYPE_OTA =3,
	AXEP_MSG_TYPE_SYS =4,	
	AXEP_MSG_TYPE_NUM = 5	 /* it can be used as array size for data declare */
} AXEP_MSG_TYPE_E;



/*
  This function  is to Open AXEP Driver device
  It should be called once when system SW is initialized
  
  Parameters:  None
  
  Returns:
      AXEP_DRIVER_STATUS_OK  -- if the driver opened succ
	  AXEP_DRIVER_STATUS_OpenFailed -- if the driver is opened with any failure
	    
*/
AXEP_Driver_Status_E AxepDriverOpen(void);

/*
  This function is to close AXEP Driver device
  It can be called when System SW is shutdown

  Parameters:  None
  
  Returns:
      AXEP_DRIVER_STATUS_OK  -- if the driver closed succ	    
*/
AXEP_Driver_Status_E AxepDriverClose(void);

/* 
This function is to get the AXEP driver’s status.
It can be called when the AXEP driver’s status need to be checked

  Return to AXEP driver connection status
     If the driver open succ, return TRUE
     If the driver not opened or closed,  return  FALSE

    It can be used by the upper layer system 
*/
bool GetAxepConnStatus(void);


/* 
    This function is to send a AXEP message to Eth
    It can be called from higher layer SW or 
   other interface API function call, such canWrite or OTA write function

   Parameters:
       [in] msg_type:  msg’s type 
       [in] txMsg:   msg in data struct {*data,  data_size}
       [in] timeout_ms: 0 - Nonblock; >0 - timeout in milliseconds
   Returns:
       AXEP_DRIVER_STATUS_OK   -- msg send out successfully
       AXEP_DRIVER_STATUS_WriteFailed  -- failure by any reason
       
*/
AXEP_Driver_Status_E AxepDriverWrite(AXEP_MSG_TYPE_E msg_type,
                     const  AXEP_Msg_S *txMsg , uint32_t timeout_ms);



/*
 This function is to read one or all available message(s) for a specific of AXEP msg type.
 It can be called by upper level API when this type of msg's data is needed by App. 

Parameters
	[in] msg_type:   specify a msg type to be read out.
	[in] &[out] list_size:  this parameter can be used as input and output
	     [in]:   If content value=0 for this point var. i.e vSize=0, call this API(... &vSize...)
		           this function read out all of available messages for this msg type.
				 If content value =n (>0) for this point var, i.e vSize=n, call this API(... &vSize...)
                   this function read out the number of n available messages for this msg type				 
		 [out]:  Store the actual value of result for size of output rxMsg_list	
                   		 
	[out] rxMsg_list:  Pointer to a variable buffer which stores the output msgs   	

						 
Returns
   AXEP_DRIVER_STATUS_OK:               If a message was read out succ
   AXEP_DRIVER_STATUS_NoDataReceived:   If no message is available to be raed out for this type of msg at this time
*/
AXEP_Driver_Status_E AxepDriverRead(AXEP_MSG_TYPE_E msg_type, 
                              uint32_t *list_size,  AXEP_Msg_S *rxMsg_list);



#endif  // AXEP_DRIVER_H_