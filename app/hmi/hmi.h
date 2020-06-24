#pragma once

#include "hmi_type.h"

//hmi require a task
void hmi_task();

// request
Te_hmi_adreq_u8 recvr_hmi_ad();
// ack
void senda_hmi_ad(Te_hmi_adreq_u8 ack);
// response
void response_hmi_ad(Te_hmi_adres_u8 adm_state);

bool GetAdRequestPowerOn();
bool GetAdRequestPowerOff();
bool GetAdRequestEngage();
bool GetAdRequestDisengage();
bool GetAdRequestTakeoverLateral();
bool GetAdRequestTakeoverLongitudinal();
bool GetAdRequestMergeLeft();
bool GetAdRequestMergeRight();
bool GetAdRequestMergeCancel();

void SetAdResponsePowerOnDoing();
void SetAdResponsePowerOnSucceed();

// other request or response for upgrade, powerM, v2x and so on
void recv_upgrade();
void ack_upgrade();
void response_upgrade();


