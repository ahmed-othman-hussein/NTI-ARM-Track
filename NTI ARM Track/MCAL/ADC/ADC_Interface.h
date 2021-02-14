/*
 * ADC_Interface.h
 *
 *  Created on: Feb 11, 2021
 *      Author: ahmed
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void 	ADC_voidInit(void);
void    ADC_voidEnable();
void    ADC_voidDisable();
void    ADC_voidMode();
void    ADC_voidResetCalAndCal();



typedef enum
{
	CH0 =0,
	CH1,
	CH2,
	CH3,
	CH4,
	CH5,
	CH6,
	CH7,

}channel_t;

u16	Adc_voidReadADC(channel_t Channel,u8 Copy_u8SampleTime_Cycles);

/*alignment right/left*/
#define    Right   1
#define    Left    2

/* sample time cycles*/
#define    ADC_SampleTime_Cycles_1        0b000
#define    ADC_SampleTime_Cycles_2        0b001
#define    ADC_SampleTime_Cycles_3        0b010
#define    ADC_SampleTime_Cycles_4        0b011
#define    ADC_SampleTime_Cycles_5        0b100
#define    ADC_SampleTime_Cycles_6        0b101
#define    ADC_SampleTime_Cycles_7        0b110
#define    ADC_SampleTime_Cycles_8        0b111

#endif /* ADC_INTERFACE_H_ */
