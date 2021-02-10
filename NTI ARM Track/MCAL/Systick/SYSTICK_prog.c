/*
 * SYSTICK_prog.c
 *
 *  Created on: Feb 9, 2021
 *      Author: ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"



static void (*STK_pfCallBack)(void) = NULL;
static u8 STK_u8IntervalMode;
void STK_voidInit(void){

	/*      prescaller       */
#if  STK_PRESCALLER == STK_AHB_DIV_8
	/* processor clock divided by 8*/
	STK->CTRL=(1<<2);
	//	CLR_BIT(STK->CTRL,2);
#elif	STK_PRESCALLER == STK_AHB_DIV_1
	/* prescaller == processor clock */
	STK->CTRL=0;
	//SET_BIT(STK->CTRL,2);
#else
#error "wrong choice of clock"
#endif

}

void STK_voidSetBusyWait(u32 Copy_u32Ticks){
	/*		Range check on 24 Bits		*/
		if(Copy_u32Ticks <= 16777216)
		{
			/*		Load Number Of ticks		*/
			STK -> LOAD = Copy_u32Ticks;
			/*		Start Timer					*/
			SET_BIT(STK -> CTRL,0);
			/*		Wait the Flag				*/
			while((GET_BIT(STK -> CTRL , 16)) == 0)
			{
				asm("NOP");
			}
			/*		Stop Timer					*/
			CLR_BIT( STK -> CTRL , 0 );
			STK -> LOAD = 0;
			STK -> VAL = 0;
		}
		else
		{	/*		Return ERROR	*/	}
}
void STK_voidIntervalSingle(u32 Copy_u32Ticks,void (*copy_pf)(void)){
	STK->LOAD=0;
	STK->VAL = 0;
	/*Range Check on 24 bits*/
	if(Copy_u32Ticks<=16777216){
		/* load number of ticks*/
		STK->LOAD = Copy_u32Ticks;
		/* start timer*/
		SET_BIT(STK->CTRL , 0);
		/* save timer*/
		if(copy_pf != NULL)
		{
			STK_pfCallBack = copy_pf ;

		}
		/* mode */
		STK_u8IntervalMode=STK_SINGLE_INTERVAL;
		/* enable systick interrupt */
		SET_BIT(STK->CTRL , 1);

	}
	else
	{ /* return error*/}
}
void STK_voidIntervalPeriodic(u32 Copy_u32Ticks,void (*copy_pf)(void)){

	if(Copy_u32Ticks<=16777216){
		/* load number of ticks*/
		STK->LOAD = Copy_u32Ticks;
		/* start timer*/
		SET_BIT(STK->CTRL , 0);
		/* save timer*/
		if(copy_pf != NULL)
		{
			STK_pfCallBack = copy_pf ;

		}
		/* mode */
		STK_u8IntervalMode=STK_PERIODIC_INTERVAL;

		/* enable systick interrupt */
		SET_BIT(STK->CTRL , 1);

	}
	else
	{ /* return error*/}

}
void STK_voidStopInterval(void){
	/* disable systick interrupt */
	CLR_BIT(STK->CTRL , 1);
	/* stop timer*/
		CLR_BIT(STK->CTRL , 0);
		STK->LOAD=0;
		STK->VAL = 0;
}
u32 STK_u32GetCounts(void){

	return (STK->LOAD - STK->VAL);
}
u32 STK_u32GetRemainingTime(void){
	return STK->VAL;
}

void SysTick_Handler(void)
{
	u8 Local_u8Temp;
if(STK_u8IntervalMode==STK_SINGLE_INTERVAL)

{
	/* disable systick interrupt */
	CLR_BIT(STK->CTRL , 1);
	/* stop timer*/
		CLR_BIT(STK->CTRL , 0);
		STK->LOAD=0;
		STK->VAL = 0;
}
/* do whatever when interrupt fired */
STK_pfCallBack();
/* clear the flag by reading the flag */
Local_u8Temp=GET_BIT(STK->CTRL,16);
}

