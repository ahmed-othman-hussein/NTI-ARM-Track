/*
 * RCC_program.c
 *
 *  Created on: Feb 2, 2021
 *      Author: ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInit(void)
{
	u32 LOCAL_u32TIMEOUT =0;
	//u8 SW_CHECK_0 =GET_BIT(RCC_CFGR,2);
	//u8 SW_CHECK_1 =GET_BIT(RCC_CFGR,3);
#if CLOCK_TYPE == RCC_HSI
	/*  HSI ON   */
	SET_BIT(RCC_CR,0);
	/*  HSI READY   */
	while((GET_BIT(RCC_CR,1))==0 && LOCAL_u32TIMEOUT!=10000){
		LOCAL_u32TIMEOUT++;
	}
#elif CLOCK_TYPE == RCC_HSE

	/*  HSE ON   */
	SET_BIT(RCC_CR,16);
	/*  SYSTEM_CLOCK_SWITCH   */
	SET_BIT(RCC_CFGR,0);
	CLR_BIT(RCC_CFGR,1);
	/*  HSE IS CRYSTAL OR RC   */
#if  RCC_HSE_SOURCE == RCC_CRYSTAL
	CLR_BIT(RCC_CR,18);
#elif  RCC_HSE_SOURCE == RCC_RC
	SET_BIT(RCC_R,18);

#endif
	/*  HSE READY   */
	while((GET_BIT(RCC_CR,17))==0 && LOCAL_u32TIMEOUT!=10000){
		LOCAL_u32TIMEOUT++;
	}
	// SW_CHECK_0 =GET_BIT(RCC_CFGR,2);
	 //SW_CHECK_1 =GET_BIT(RCC_CFGR,3);
#elif CLOCK_TYPE == RCC_PLL
	/*  PLL ENTRY SOURCE  HSI/HSE  */
#if  RCC_PLL_SOURCE == RCC_HSI
	CLR_BIT(RCC_CR,24);
	CLR_BIT(RCC_CFGR,16);
#elif  RCC_HSE_SOURCE == RCC_HSE
	CLR_BIT(RCC_CR,24);
	SET_BIT(RCC_CFGR,16);

#endif

	/*  PLL ENTRY SOURCE IS HSE DIVISON/2 OR NOT  */
#if  RCC_PLL_SOURCE_HSE == HSE_DEVIDE_TWO
	CLR_BIT(RCC_CR,24);
	SET_BIT(RCC_CFGR,17);
#elif  RCC_HSE_SOURCE_HSE == HSE
	CLR_BIT(RCC_CR,24);
	CLR_BIT(RCC_CFGR,17);

#endif

	/*  PLL ENTRY SOURCE IS HSE DIVISON/2 OR NOT  */
#if  RCC_PLL_MUL ==  1
	CLR_BIT(RCC_CR,24);
	CLR_BIT(RCC_CFGR,18);
	CLR_BIT(RCC_CFGR,19);
	CLR_BIT(RCC_CFGR,20);
	CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  2
	CLR_BIT(RCC_CR,24);
	SET_BIT(RCC_CFGR,18);
	CLR_BIT(RCC_CFGR,19);
	CLR_BIT(RCC_CFGR,20);
	CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  3
	CLR_BIT(RCC_CR,24);
	CLR_BIT(RCC_CFGR,18);
	SET_BIT(RCC_CFGR,19);
	CLR_BIT(RCC_CFGR,20);
	CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  4
	CLR_BIT(RCC_CR,24);
	SET_BIT(RCC_CFGR,18);
	SET_BIT(RCC_CFGR,19);
	CLR_BIT(RCC_CFGR,20);
	CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  5
	CLR_BIT(RCC_CR,24);
	CLR_BIT(RCC_CFGR,18);
	CLR_BIT(RCC_CFGR,19);
	SET_BIT(RCC_CFGR,20);
	CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  6
	CLR_BIT(RCC_CR,24);
	SET_BIT(RCC_CFGR,18);
	CLR_BIT(RCC_CFGR,19);
	SET_BIT(RCC_CFGR,20);
	CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  7
	CLR_BIT(RCC_CR,24);
	CLR_BIT(RCC_CFGR,18);
	SET_BIT(RCC_CFGR,19);
	SET_BIT(RCC_CFGR,20);
	CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  8
	CLR_BIT(RCC_CR,24);
	SET_BIT(RCC_CFGR,18);
	SET_BIT(RCC_CFGR,19);
	SET_BIT(RCC_CFGR,20);
	CLR_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  9
	CLR_BIT(RCC_CR,24);
	CLR_BIT(RCC_CFGR,18);
	CLR_BIT(RCC_CFGR,19);
	CLR_BIT(RCC_CFGR,20);
	SET_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  10
	CLR_BIT(RCC_CR,24);
	SET_BIT(RCC_CFGR,18);
	CLR_BIT(RCC_CFGR,19);
	CLR_BIT(RCC_CFGR,20);
	SET_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  11
	CLR_BIT(RCC_CR,24);
	CLR_BIT(RCC_CFGR,18);
	SET_BIT(RCC_CFGR,19);
	CLR_BIT(RCC_CFGR,20);
	SET_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  12
	CLR_BIT(RCC_CR,24);
	SET_BIT(RCC_CFGR,18);
	SET_BIT(RCC_CFGR,19);
	CLR_BIT(RCC_CFGR,20);
	SET_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  13
	CLR_BIT(RCC_CR,24);
	CLR_BIT(RCC_CFGR,18);
	CLR_BIT(RCC_CFGR,19);
	SET_BIT(RCC_CFGR,20);
	SET_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  14
	CLR_BIT(RCC_CR,24);
	SET_BIT(RCC_CFGR,18);
	CLR_BIT(RCC_CFGR,19);
	SET_BIT(RCC_CFGR,20);
	SET_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  15
	CLR_BIT(RCC_CR,24);
	CLR_BIT(RCC_CFGR,18);
	SET_BIT(RCC_CFGR,19);
	SET_BIT(RCC_CFGR,20);
	SET_BIT(RCC_CFGR,21);
#elif  RCC_PLL_MUL ==  16
	CLR_BIT(RCC_CR,24);
	SET_BIT(RCC_CFGR,18);
	SET_BIT(RCC_CFGR,19);
	SET_BIT(RCC_CFGR,20);
	SET_BIT(RCC_CFGR,21);

#endif

	/*  PLL ON   */
	SET_BIT(RCC_CR,24);
	/*  SYSTEM_CLOCK_SWITCH   */
	CLR_BIT(RCC_CFGR,0);
	SET_BIT(RCC_CFGR,1);


	/*  PLL READY   */
	while((GET_BIT(RCC_CR,25))==0 && LOCAL_u32TIMEOUT!=10000){
		LOCAL_u32TIMEOUT++;
	}
	/*  SWS BOOLING  */
	// SW_CHECK_0 =GET_BIT(RCC_CFGR,2);
	// SW_CHECK_1 =GET_BIT(RCC_CFGR,3);
#else
	#error "wrong clock system choice!"

#endif

}
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
	/*	Range Check	*/
	if(Copy_u8PeripheralID < 32)
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB:	SET_BIT(RCC_AHBENR,Copy_u8PeripheralID);	break;
		case RCC_APB1:	SET_BIT(RCC_APB1ENR,Copy_u8PeripheralID);	break;
		case RCC_APB2:	SET_BIT(RCC_APB2ENR,Copy_u8PeripheralID);	break;
		}
	}
	else{/*		Return ERROR	*/}
}
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
	/*	Range Check	*/
	if(Copy_u8PeripheralID < 32)
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB:	CLR_BIT(RCC_AHBENR,Copy_u8PeripheralID);	break;
		case RCC_APB1:	CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralID);	break;
		case RCC_APB2:	CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralID);	break;
		}
	}
	else{/*		Return ERROR	*/}
}