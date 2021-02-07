/*
 * Keypad.c
 *
 *  Created on: Feb 6, 2021
 *      Author: ahmed
 */

/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SEV_int.h"
#include "KEYPAD_int.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


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




int main(void)
{

    u8 x;
	RCC_voidInit();

	RCC_voidEnablePeripheralClock(RCC_APB2, RCC_GPIOB_ID);


	DIO_voidSetPinDirection(DIO_U8_PORTB,DIO_U8_PIN6, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DIO_U8_PORTB,DIO_U8_PIN7, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DIO_U8_PORTB,DIO_U8_PIN8, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DIO_U8_PORTB,DIO_U8_PIN9, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DIO_U8_PORTB,DIO_U8_PIN10, DIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(DIO_U8_PORTB,DIO_U8_PIN11,DIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(DIO_U8_PORTB,DIO_U8_PIN12,DIO_INPUT_PULL_UP_DOWN);

	KEYPAD_voidInit();

 
	SEV_voidEnable7Segment(SEV_LEFT);
	SEV_voidEnable7Segment(SEV_RIGHT);
	


	/* Loop forever */
	for(;;)
	{


	x=KEYPAD_u8GetPressedKey();

		switch(x){
		case '0':x=0; break;
		case '1':x=1; break;
		case '2':x=2; break;
		case '3':x=3; break;
		case '4':x=4; break;
		case '5':x=5; break;
		case '6':x=6; break;
		case '7':x=7; break;
		case '8':x=8; break;
		case '9':x=9; break;
		}

	}
}

