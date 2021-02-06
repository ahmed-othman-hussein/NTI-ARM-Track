/*
 * LED_Animation.c
 *
 *  Created on: Feb 6, 2021
 *      Author: ahmed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"



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
	u32 i,j,k;

	RCC_voidInit();
    RCC_voidEnablePeripheralClock(RCC_APB2, RCC_GPIOB_ID);
	DIO_voidSetPortDirection(DIO_U8_PORTB, DIO_OUTPUT_2MHZ_PP);

	/* Loop forever */
	for(;;)
	{


		/* LED Animation:walking LED Animation */

			for(i=DIO_U8_PIN5 ; i <= DIO_U8_PIN12 ; i++)
		{
			DIO_voidSetPinValue(DIO_U8_PORTB,i,DIO_U8_HIGH);
			delay_us(200);
			DIO_voidSetPinValue(DIO_U8_PORTB,i,DIO_U8_LOW);
		}

		for(i=DIO_U8_PIN12 ; i >= DIO_U8_PIN5 ; i--)
		{
			DIO_voidSetPinValue(DIO_U8_PORTB,i,DIO_U8_HIGH);
			delay_us(200);
			DIO_voidSetPinValue(DIO_U8_PORTB,i,DIO_U8_LOW);

		}



		/* LED Animation:Closing and Opening flower LED Animation */

		for(i=DIO_U8_PIN5,j=12 ; i < 9 ; i++,j--)
		{
			DIO_voidSetPinValue(DIO_U8_PORTB,i,DIO_U8_HIGH);
			DIO_voidSetPinValue(DIO_U8_PORTB,j,DIO_U8_HIGH);

			delay_us(300);
			DIO_voidSetPinValue(DIO_U8_PORTB,i,DIO_U8_LOW);
			DIO_voidSetPinValue(DIO_U8_PORTB,j,DIO_U8_LOW);

		}

		for(i=DIO_U8_PIN8,j=9 ; j <13 ; i--,j++)
		{
			DIO_voidSetPinValue(DIO_U8_PORTB,i,DIO_U8_HIGH);
			DIO_voidSetPinValue(DIO_U8_PORTB,j,DIO_U8_HIGH);

			delay_us(300);
			DIO_voidSetPinValue(DIO_U8_PORTB,i,DIO_U8_LOW);
			DIO_voidSetPinValue(DIO_U8_PORTB,j,DIO_U8_LOW);

		}




		/* LED Animation:Snake Motion LED Animation */

			for(i=DIO_U8_PIN5,j=6,k=7 ; i < 12 ; i+=3,j+=3,k+=3)
		{

			DIO_voidSetPinValue(DIO_U8_PORTB,i,DIO_U8_HIGH);
			DIO_voidSetPinValue(DIO_U8_PORTB,j,DIO_U8_HIGH);
			DIO_voidSetPinValue(DIO_U8_PORTB,k,DIO_U8_HIGH);

			delay_us(400);
			DIO_voidSetPinValue(DIO_U8_PORTB,i,DIO_U8_LOW);
			DIO_voidSetPinValue(DIO_U8_PORTB,j,DIO_U8_LOW);
			DIO_voidSetPinValue(DIO_U8_PORTB,k,DIO_U8_LOW);

		}

		for(i=DIO_U8_PIN13,j=12,k=11 ; i > 3 ; i-=3,j-=3,k-=3)
		{
			DIO_voidSetPinValue(DIO_U8_PORTB,i,DIO_U8_HIGH);
			DIO_voidSetPinValue(DIO_U8_PORTB,j,DIO_U8_HIGH);
			DIO_voidSetPinValue(DIO_U8_PORTB,k,DIO_U8_HIGH);

			delay_us(400);
			DIO_voidSetPinValue(DIO_U8_PORTB,i,DIO_U8_LOW);
			DIO_voidSetPinValue(DIO_U8_PORTB,j,DIO_U8_LOW);
			DIO_voidSetPinValue(DIO_U8_PORTB,k,DIO_U8_LOW);

		}


	}
}
