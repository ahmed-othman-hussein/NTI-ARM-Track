/*
 * keypad1_prog.c
 *
 *  Created on: Feb 7, 2021
 *      Author: ahmed
 */

#include "STD_Types.h"
#include "Bit_Math.h"

#include "GPIO_interface.h"

#include "KEYPAD_int.h"
#include "KEYPAD_config.h"
#include "KEYPAD_priv.h"

u8 LOC_u8preesed = 0X00;

static const u8 KEYPAD_Au8keys[4][3]={ 		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'},
		{'*','0','#'} };


void KEYPAD_voidInit(){
	DIO_voidSetPinValue(DIO_U8_PORTB,KEYPAD_U8_ROW_1 ,DIO_U8_LOW );
	DIO_voidSetPinValue(DIO_U8_PORTB,KEYPAD_U8_ROW_2 ,DIO_U8_LOW);
	DIO_voidSetPinValue(DIO_U8_PORTB,KEYPAD_U8_ROW_3 ,DIO_U8_LOW);
	DIO_voidSetPinValue(DIO_U8_PORTB,KEYPAD_U8_ROW_4 ,DIO_U8_LOW);
}


u8 KEYPAD_u8GetPressedKey(void)
{


	/* ROW 1 check all COLUMNS */
	DIO_voidSetPinValue(DIO_U8_PORTB,KEYPAD_U8_ROW_1,DIO_U8_HIGH);
	if (DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_1 ))
	{
		LOC_u8preesed =KEYPAD_Au8keys[0][0];
		while(DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_1 )==0);
	}
	else if (DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_2))
	{
		LOC_u8preesed =KEYPAD_Au8keys[0][1];
		while(DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_2)==0);
	}
	else if (DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_3))
	{
		LOC_u8preesed =KEYPAD_Au8keys[0][2];
		while(DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_3)==0);
	}

	DIO_voidSetPinValue(DIO_U8_PORTB,KEYPAD_U8_ROW_1 ,DIO_U8_LOW );



	/* ROW 2 check all COLUMNS */
	DIO_voidSetPinValue(DIO_U8_PORTB,KEYPAD_U8_ROW_2,DIO_U8_HIGH);
	if (DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_1 ))
	{
		LOC_u8preesed =KEYPAD_Au8keys[1][0];
		while(DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_1 )==0);
	}
	else if (DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_2))
	{
		LOC_u8preesed =KEYPAD_Au8keys[1][1];
		while(DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_2)==0);
	}
	else if (DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_3))
	{
		LOC_u8preesed =KEYPAD_Au8keys[1][2];
		while(DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_3)==0);
	}
	DIO_voidSetPinValue(DIO_U8_PORTB,KEYPAD_U8_ROW_2 ,DIO_U8_LOW );




	/* ROW 3 check all COLUMNS */
	DIO_voidSetPinValue(DIO_U8_PORTB,KEYPAD_U8_ROW_3,DIO_U8_HIGH);
	if (DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_1 ))
	{
		LOC_u8preesed =KEYPAD_Au8keys[2][0];
		while(DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_1 )==0);
	}
	else if (DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_2))
	{
		LOC_u8preesed =KEYPAD_Au8keys[2][1];
		while(DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_2)==0);
	}
	else if (DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_3))
	{
		LOC_u8preesed =KEYPAD_Au8keys[2][2];
		while(DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_3)==0);
	}
	DIO_voidSetPinValue(DIO_U8_PORTB,KEYPAD_U8_ROW_3 ,DIO_U8_LOW);


	/* ROW 4 check all COLUMNS */
	DIO_voidSetPinValue(DIO_U8_PORTB,KEYPAD_U8_ROW_4,DIO_U8_HIGH);
	if (DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_1 ))
	{
		LOC_u8preesed =KEYPAD_Au8keys[3][0];
		while(DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_1 )==0);
	}
	else if (DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_2))
	{
		LOC_u8preesed =KEYPAD_Au8keys[3][1];
		while(DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_2)==0);
	}
	else if (DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_3))
	{
		LOC_u8preesed =KEYPAD_Au8keys[3][2];
		while(DIO_u8GetPinValue(DIO_U8_PORTB,KEYPAD_U8_COLUMN_3)==0);
	}
	DIO_voidSetPinValue(DIO_U8_PORTB,KEYPAD_U8_ROW_4 ,DIO_U8_LOW );




	return LOC_u8preesed ;
}
