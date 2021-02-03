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

//#include <stdint.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	u32 i;
	RCC_voidInit();
	RCC_voidEnablePeripheralClock(RCC_APB2, RCC_GPIOB_ID);
	DIO_voidSetPortDirection(DIO_U8_PORTB, DIO_OUTPUT_2MHZ_PP);
	//DIO_voidSetPinValue(DIO_U8_PORTA, DIO_U8_HIGH);

    /* Loop forever */
	for(;;)
	{
		DIO_voidSetPortValue(DIO_U8_PORTB, DIO_U8_HIGH);
		for (i = 0; i < 50000; i++);
		DIO_voidSetPortValue(DIO_U8_PORTB, DIO_U8_LOW);
		for (i = 0; i < 50000; i++);
	}
}
