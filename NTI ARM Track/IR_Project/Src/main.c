/*
 * main.c
 *
 Created on: Feb 20, 2021
 *      Author: ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "IR_Interface.h"
#include"LCD_int.h"
#include"SEV_int.h"
#include"Delay.h"
#include"LED_Animation.h"


void voidPlay(void);
u8   u8Data;
u32  u32FrameData[50];
int main(void)
{

	/* RCC Initialize */
	RCC_voidInit();

	RCC_voidEnablePeripheralClock(RCC_APB2, 2);/*GPIOA Enable Clock*/
	RCC_voidEnablePeripheralClock(RCC_APB2, RCC_GPIOB_ID);
	RCC_voidEnablePeripheralClock(RCC_APB2, RCC_GPIOC_ID);

	/* IO Pins Initialization */
	DIO_voidSetPortDirection(DIO_U8_PORTA, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DIO_U8_PORTA, DIO_U8_PIN1, DIO_INPUT_FLOATING);

	DIO_voidSetPortDirection(DIO_U8_PORTB, DIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPortDirection(DIO_U8_PORTC, DIO_OUTPUT_2MHZ_PP);
	EXTI1_voidSetCallBack(voidGetFrame);

	/* EXTI1 Initialization */
	EXTI_voidInit();
	EXTI_voidEnableLine(1);
	/* Enable EXTI1 from NVIC */
	NVIC_voidInit();
	NVIC_voidEnableInterrupt(7); /* EXTI1 */
	LCD_vidInit( );
	/* SysTick Initialization */
	STK_voidInit();

	/* Loop forever */
	while(1){

		asm("NOP");
	}


}

void voidPlay(void)
{
	u16 i;
	switch (u8Data)
	{
	case 16:
		voidLedAnimation();
		break;
	case 17:
		LCD_vidGotoXY( 1 , '\0' );
		LCD_vidWriteString(" Welcome!!!!!!!");
		LCD_vidGotoXY( 2 , '\0' );
		LCD_vidWriteString(" IR working :)!");
		break;
	case 18: LCD_vidClear(); break;
	case 19:
		/*      Seven Segment Display Using POV     */
		for(i=0;i<400;i++)
		{
			/*      Seven Segment Display Using POV     */

			SEV_voidDisable7Segment(SEV_LEFT);
			SEV_voidEnable7Segment(SEV_RIGHT);
			SEV_voidSet7SegmentValue( SEV_RIGHT, 5 );
			delay_us(10);
			SEV_voidDisable7Segment(SEV_RIGHT);
			SEV_voidEnable7Segment(SEV_LEFT);
			SEV_voidSet7SegmentValue( SEV_LEFT, 2 );
			delay_us(10);

		}  break;
	case 20:
		for(i=0;i<10;i++)
		{
			/*      Seven Segment Display Count     */

			SEV_voidEnable7Segment(SEV_RIGHT);
			SEV_voidEnable7Segment(SEV_LEFT);
			SEV_voidSet7SegmentValue( SEV_RIGHT, i );
			delay_us(1000);

		} break;
	case 21: DIO_voidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0, DIO_U8_LOW);  break;
	case 22: DIO_voidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0, DIO_U8_HIGH); break;
	case 23: DIO_voidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0, DIO_U8_LOW);  break;
	case 24: DIO_voidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0, DIO_U8_HIGH); break;
	case 25: DIO_voidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0, DIO_U8_HIGH); break;
	case 64: DIO_voidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0, DIO_U8_LOW);  break;
	case 65: DIO_voidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0, DIO_U8_HIGH); break;
	case 6:  DIO_voidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0, DIO_U8_LOW);  break;
	case 7:  DIO_voidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0, DIO_U8_HIGH); break;
	case 68: DIO_voidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0, DIO_U8_LOW);  break;

	}
}


