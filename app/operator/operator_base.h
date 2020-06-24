#pragma once

#include "adm_public.h"
// operator communicate with hmi by share data struct Ts_HMI_ad
#include "hmi_data.h"
#include "hmi.h"

//Te_HMI_adr_u8 recvr_hmi_ad();
void sends_hmi_ad(Ts_ad_state ad_status);
Te_ads_u8 recvs_adm(); // read state in adm
void sendr_adm(Te_adr req);

// v2x-ota
void sendr_download(Ts_package pkg); //upgradepackage
bool recvs_download();
void sendr_upgrade(Ts_upgrade ug);  //
bool recvs_upgrade();

bool reads_download();   // whether new version can be download
bool reads_upgrade();    // true while new version package have downloaded, one upgrade task in queue
void remind_download();
void remind_upgrade();

// green  adm should not manager xeon or other power state, should cooperate themselves or manager overall by operator
void sendr_xeon(bool sleep); //false wake-up true sleep
void sendr_fpgi(bool sleep);
void sendr_aurix(bool sleep);
void sendr_network(uint16_t channel_id, bool sleep);

bool reads_xeon(); //false wake-up true sleep
bool reads_fpgi();
bool reads_aurix();
bool reads_network(uint16_t channel_id);

