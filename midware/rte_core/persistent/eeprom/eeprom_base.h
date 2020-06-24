#pragma once
#include "kam.h"

void nvm_write(uint16_t nvm_id, uint8_t* data_addr);
void nvm_read(uint16_t nvm_id, uint8_t* data_addr);

void kam_write(uint16_t kam_id, uint8_t* data_addr);
void kam_read(uint16_t kam_id, uint8_t* data_addr);