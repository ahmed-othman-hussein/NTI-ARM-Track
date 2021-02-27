/*
 * Delay.c
 *
 *  Created on: Feb 20, 2021
 *      Author: ahmed
 */
#include "STD_TYPES.h"

void delay_us(u32 copy_u32time)
{
	for(u32 i=0;i<copy_u32time;i++)
	{
		for(u16 j=0;j<565;j++)
		{
			asm("NOP");
		}
	}
}
