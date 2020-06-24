#ifndef _RTE_BUFF_H_
#define _RTE_BUFF_H_

#include "rte_type.h"

uint8_t* FindOneFromBuffByFirstInt(uint8_t * buff, int unit_len, int feature)
{
	while (buff != NULL)
	{
		if (*buff != feature)
		{
			buff += unit_len;
			continue;
		}
		return buff;
	}
}

#endif
