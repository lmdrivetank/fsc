#pragma once

//adu health green upgrade v2x intelligent_traffic coexistenceand cooperation strategy, include operator decision
void operator_task();

void ad_checkhmirequest();
void ad_prepare();
void ad_exit();
void ad_engage();
void ad_takeover(uint8_t action_type); //0 horizontal 1 vertical 2 all
void ad_mergelane(bool is_left); //false right true left
void ad_fallback();

void ota_check();
void ota_download_check();
void ota_upgrade_check();

void green_check();
void sleep_check();
void wakeup_check();

void health_check();
