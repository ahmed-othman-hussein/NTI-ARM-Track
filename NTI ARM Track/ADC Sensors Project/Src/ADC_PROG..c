/*
 * ADC_PROG..c
 *
 *  Created on: Feb 11, 2021
 *      Author: ahmed
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"ADC_Interface.h"
#include"ADC_Private.h"
#include"ADC_Config.h"


static volatile u16 AD_val ;
void 	ADC_voidInit(void){

#if RCC_ADC_CLKConfig == PCLK2_divided_by_2
	CLR_BIT( RCC_CFGR , 14 );
	CLR_BIT( RCC_CFGR , 15 );

#elif RCC_ADC_CLKConfig == PCLK2_divided_by_4
	SET_BIT( RCC_CFGR , 14 );
	CLR_BIT( RCC_CFGR , 15 );


#elif RCC_ADC_CLKConfig == PCLK2_divided_by_6
	CLR_BIT( RCC_CFGR , 14 );
	SET_BIT( RCC_CFGR , 15 );

#elif RCC_ADC_CLKConfig == PCLK2_divided_by_8
	SET_BIT( RCC_CFGR , 14 );
	SET_BIT( RCC_CFGR , 15 );
#endif

	/*  Data alignment right/left */
#if ADC_DataAlign == Right
	CLR_BIT( ADC->CR2 , 11 );
#elif ADC_DataAlign == Left
	SET_BIT( ADC->CR2 , 11 );
#endif
}

void    ADC_voidEnable(){
	SET_BIT(ADC->CR2,0);
}
void    ADC_voidDisable(){
	CLR_BIT(ADC->CR2,0);
}
/*  mode set to be continuous conversion/clear to be single conversion */
void    ADC_voidMode(){
	CLR_BIT(ADC->CR2,1);
}
void    ADC_voidResetCalAndCal(){
	SET_BIT(ADC->CR2,3);
	while(GET_BIT(ADC->CR2,3));
	SET_BIT(ADC->CR2,2);
		while(GET_BIT(ADC->CR2,2));

		SET_BIT(ADC->CR2,0);  // start conversion
}

u16	Adc_voidReadADC(channel_t Channel,u8 Copy_u8SampleTime_Cycles)

	{
	ADC->SQR1 = 0x00000000;  // Regular channel single conversion
	ADC->SQR2 = 0x00000000; // Clear register
	ADC->SQR3 = (Channel<<0);  // channel seq as 1st conversion

		/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
		ADC->SMPR2 &= ~((u32)(0b111)<<(Channel * 3));
		ADC->SMPR2 |=  ((u32)(Copy_u8SampleTime_Cycles)<<(Channel * 3));

		if (ADC->SR & (1 << 1)) { // If conversion has finished (Check EOC bit)
		AD_val = ADC->DR & 0x0FFF; // Read AD converted value

		SET_BIT(ADC->CR2,0); // Start new conversion
		}
		return AD_val;
	}

