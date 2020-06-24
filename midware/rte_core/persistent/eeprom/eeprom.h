#pragma once


void eeprom_write(uint16_t eep_id, uint8_t * data_addr);
void eeprom_read(uint16_t eep_id, uint8_t * data_addr);