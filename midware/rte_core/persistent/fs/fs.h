#pragma once


void configurature_read(uint16_t cid, uint8_t * config_addr);
void configurature_write(uint16_t cid, uint8_t * config_addr);

int file_open_s(char * name);
void file_read_s(int fid, int len, uint8_t* cache_addr);
void file_write_s(int fid, int len, uint8_t* cache_addr);