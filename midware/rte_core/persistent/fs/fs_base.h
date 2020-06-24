#pragma once

int file_open(char * file_name);
void file_write(int fid, int len, uint8_t* cache_addr);
void file_read(int fid, int len, uint8_t* cache_addr);