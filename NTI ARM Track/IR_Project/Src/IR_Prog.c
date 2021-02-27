/*
 * IR_Prog.c
 *
 *  Created on: Feb 19, 2021
 *      Author: ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"



#include "IR_Interface.h"
#include "IR_Config.h"
#include "IR_Private.h"

volatile u8   u8StartFlag       = 0;
extern volatile u32  u32FrameData[50]  = {0};
volatile u8   u8EdgeCounter     = 0;
extern volatile u8   u8Data     = 0;



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
	//u8EdgeCounter  = 0;
	if (u8StartFlag == 0)
	{
		/* Start Timer */
		STK_voidIntervalSingle(500000,voidTakeAction);
		u8StartFlag = 1;
	}

	else
	{
		u32FrameData[u8EdgeCounter] = STK_u32GetCounts();
		STK_voidIntervalSingle(500000,voidTakeAction);
		u8EdgeCounter++;
	}
}
