/*
 * main.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "EXTI0_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

volatile u8   u8StartFlag       = 0;
volatile u32  u32FrameData[50]  = {0};
volatile u8   u8EdgeCounter     = 0;
volatile u8   u8Data            = 0;



void voidPlay(void)
{
	switch (u8Data)
	{
		case 220: MGPIO_VidSetPinValue(GPIOA,0,HIGH); break;
		case 218: MGPIO_VidSetPinValue(GPIOA,0,LOW);  break;
	}
}

void voidTakeAction(void)
{
	u8 i;
	u8Data = 0;

	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )
	{
		for (i=0;i<8;i++)
		{
			if (  (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <=2300) )
			{
				SET_BIT(u8Data,i);
			}

			else
			{
				CLR_BIT(u8Data,i);
			}
		}

		voidPlay();
	}

	else
	{
/*		 Invalid Frame*/
	}

	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;
}

void voidGetFrame(void)
{
	if (u8StartFlag == 0)
	{
		/* Start Timer */
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8StartFlag = 1;
	}

	else
	{
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8EdgeCounter++;
	}
}


void main(void)
{
	/* RCC Initialize */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(2,2); /* GPIOA Enable Clock */
	RCC_voidEnableClock(RCC_APB2 , 0);

	/* IO Pins Initialization */
	MGPIO_VidSetPinDirection(GPIOA,0,0b0010); /* A0 Output PP "RED"     */
	MGPIO_VidSetPinDirection(GPIOA,1,0b0100); /* A1 Input Floating      */
	MGPIO_VidSetPinDirection(GPIOA,2,0b0010); /* A1 Output PP "GREEN"     */
	MGPIO_VidSetPinDirection(GPIOA,3,0b0010); /* A1 Output PP "BLUE"      */


	MEXTI1_voidSetCallBack(voidGetFrame);
	MEXTI_voidSetSignalLatch(EXTI_LINE1 , FALLING_EDGE);

	/* EXTI1 Initialization */
//	MEXTI_voidInit(); /* A1 EXTI0 Enabled / Falling Edge */

	/* Enable EXTI0 from NVIC */
	//MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(7); /* EXTI1 */

	/* SysTick Initialization */
	MSTK_voidInit(); /* Enable SysTick AHB/8 = 1MHZ */

	while(1)
	{
		asm("NOP");
	}

}
