/*
 * NVIC_program.c
 *
 *  Created on: Feb 7, 2021
 *      Author: Boon
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void NVIC_voidInit(void)
{
	/*		Number of Groups and Sub Groups	SCB			*/
#ifndef			SCB_AIRCR
	#define 	SCB_AIRCR 			*((u32 *)(0xE000ED00 + 0x0C))
#endif
	/*	2 G and 2 sub				*/
	SCB_AIRCR = NUM_GROUPS_AND_SUB;
}
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptNum)
{
	if(Copy_u8InterruptNum < 32)
	{
		NVIC_ISER0 = ( 1 << Copy_u8InterruptNum );
	}
	else if (Copy_u8InterruptNum < 60)
	{
		Copy_u8InterruptNum -= 32;
		NVIC_ISER1 = ( 1 << Copy_u8InterruptNum );
	}
	else{/*					Return ERROR						*/}
}
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptNum)
{
	if(Copy_u8InterruptNum < 32)
	{
		NVIC_ICER0 = ( 1 << Copy_u8InterruptNum );
	}
	else if (Copy_u8InterruptNum < 60)
	{
		Copy_u8InterruptNum -= 32;
		NVIC_ICER1 = ( 1 << Copy_u8InterruptNum );
	}
	else{/*					Return ERROR						*/}
}
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptNum)
{
	if(Copy_u8InterruptNum < 32)
	{
		NVIC_ISPR0 = ( 1 << Copy_u8InterruptNum );
	}
	else if (Copy_u8InterruptNum < 60)
	{
		Copy_u8InterruptNum -= 32;
		NVIC_ISPR1 = ( 1 << Copy_u8InterruptNum );
	}
	else{/*					Return ERROR						*/}
}
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptNum)
{
	if(Copy_u8InterruptNum < 32)
	{
		NVIC_ICPR0 = ( 1 << Copy_u8InterruptNum );
	}
	else if (Copy_u8InterruptNum < 60)
	{
		Copy_u8InterruptNum -= 32;
		NVIC_ICPR1 = ( 1 << Copy_u8InterruptNum );
	}
	else{/*					Return ERROR						*/}
}
u8	 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptNum)
{
	u8 Local_u8Active = 0xFF;
	if(Copy_u8InterruptNum < 32)
	{
		Local_u8Active = GET_BIT(NVIC_IABR0,Copy_u8InterruptNum);
	}
	else if (Copy_u8InterruptNum < 60)
	{
		Copy_u8InterruptNum -= 32;
		Local_u8Active = GET_BIT(NVIC_IABR1,Copy_u8InterruptNum);
	}
	else{/*					Return ERROR						*/}
	return Local_u8Active;
}
void NVIC_voidSetPriority(u8 Copy_u8InterruptNum , u8 Copy_u8PerPriority)
{
	if(Copy_u8InterruptNum < 60)
	{
		/*		Bits From 4 : 7							*/
		NVIC_IPR[Copy_u8InterruptNum] = (Copy_u8PerPriority<<4);
	}
	else{/*					Return ERROR						*/}
}
