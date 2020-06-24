typedef struct Ts_eeprom_data
{
	uint16_t kam_id;
	uint16_t len;
	uint8_t* default_addr;	//	rom
	uint8_t* data_addr;		//	ram

	uint8_t delay_ms;
};