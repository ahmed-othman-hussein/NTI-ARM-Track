/******************************************************/
/* Author  : Ahmed othman                         */
/* Date    : 4 FEB 2021                             */
/* Version : 1V                                       */
/******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "SEV_int.h"
#include "SEV_config.h"
#include "SEV_priv.h"


void SEV_voidEnable7Segment(u8 Copy_u8SevenSegmentNumber){

	switch(Copy_u8SevenSegmentNumber){
	case SEV_LEFT:SET_BIT_BSRR(GPIOC_BSR  , DIO_U8_PIN14);break;
	case SEV_RIGHT:SET_BIT_BSRR(GPIOC_BSR  , DIO_U8_PIN15);break;
	}
}
void SEV_voidDisable7Segment(u8 Copy_u8SevenSegmentNumber){
	switch(Copy_u8SevenSegmentNumber){
	case SEV_LEFT:CLR_BIT_BRR(GPIOC_BRR  , DIO_U8_PIN14);break;
	case SEV_RIGHT:CLR_BIT_BRR(GPIOC_BRR  , DIO_U8_PIN15);break;
	}
}


#if(SEV_TYPE==SEV_TYPE_Decoder)
void SEV_voidSet7SegmentValue(u8 Copy_u8SevenSegmentNumber , u8 Copy_u8SevenSegmentValue )
{



	u8 seg [10]= {0x0 , 0x1 , 0x2 , 0x3 , 0x4, 0x5 , 0x6,0x7, 0x8,0x9};
	u8 LOC_u8Loop=SEV_START;
	if (Copy_u8SevenSegmentNumber ==SEV_LEFT )
	{
		//	SEV_voidEnable7Segment(SEV_LEFT);

		DIO_voidSetPinValue (DIO_U8_PORTB,SEV_0_u8_A ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTB,SEV_0_u8_B ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTB,SEV_0_u8_C ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTC,SEV_0_u8_D ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		//DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_C ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		/*DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_F ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_G ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_H ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));*/
	}
	else if (Copy_u8SevenSegmentNumber ==SEV_RIGHT)
	{
		//SEV_voidEnable7Segment(SEV_RIGHT);

		LOC_u8Loop=SEV_START;
		DIO_voidSetPinValue (DIO_U8_PORTB,SEV_0_u8_A ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTB,SEV_0_u8_B ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTB,SEV_0_u8_C ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTC,SEV_0_u8_D ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		//	DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_C ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		/*	DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_F ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_G ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_H ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));*/
	}		

}

#endif

#if(SEV_TYPE==SEV_TYPE_Anode)


void SEV_voidSet7SegmentValue(u8 Copy_u8SevenSegmentNumber , u8 Copy_u8SevenSegmentValue )
{



	u8 seg [10]= {0xC0 , 0xF9 , 0xA4 , 0xB0 , 0x99 , 0x92 , 0x82,0xf8, 0x80,0x90};
	u8 LOC_u8Loop=SEV_START;
	if (Copy_u8SevenSegmentNumber ==SEV_LEFT )
	{
		//	SEV_voidEnable7Segment(SEV_LEFT);

		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_A ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_B ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_C ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_D ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_E ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_F ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_G ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_H ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
	}
	else if (Copy_u8SevenSegmentNumber ==SEV_RIGHT)
	{
		//SEV_voidEnable7Segment(SEV_RIGHT);

		LOC_u8Loop=SEV_START;
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_A ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_B ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_C ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_D ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_E ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_F ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_G ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_H ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
	}

}

#endif

#if(SEV_TYPE==SEV_TYPE_Cathode)

void SEV_voidSet7SegmentValue(u8 Copy_u8SevenSegmentNumber , u8 Copy_u8SevenSegmentValue )
{



	u8 seg [10]= {0xBF , 0x86 , 0xDB , 0xCF , 0xE6, 0xED ,0xFD,0x87, 0xFF,0xEF};
	u8 LOC_u8Loop=SEV_START;
	if (Copy_u8SevenSegmentNumber ==SEV_LEFT )
	{
		//	SEV_voidEnable7Segment(SEV_LEFT);

		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_A ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_B ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_C ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_D ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_E ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_F ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_G ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_0_u8_H ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
	}
	else if (Copy_u8SevenSegmentNumber ==SEV_RIGHT)
	{
		//SEV_voidEnable7Segment(SEV_RIGHT);

		LOC_u8Loop=SEV_START;
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_A ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_B ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_C ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_D ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_E ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_F ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_G ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (DIO_U8_PORTA,SEV_1_u8_H ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
	}

}


#endif

