/*
 * ADC_Config.h
 *
 *  Created on: Feb 11, 2021
 *      Author: ahmed
 */
#include"ADC_Private.h"


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
/*RCC_ADC_CLKConfig  COULD BE:
 *
 *
PCLK2_divided_by_2
PCLK2_divided_by_4
PCLK2_divided_by_6
PCLK2_divided_by_8
 *
 *
 */
#define    RCC_ADC_CLKConfig        PCLK2_divided_by_2

/*ADC_SampleTime_Cycles COULD BE:
 *
 *
ADC_SampleTime_Cycles_1      1.5 cycles
ADC_SampleTime_Cycles_2      7.5 cycles
ADC_SampleTime_Cycles_3      13.5 cycles
ADC_SampleTime_Cycles_4      28.5 cycles
ADC_SampleTime_Cycles_5      41.5 cycles
ADC_SampleTime_Cycles_6      55.5 cycles
ADC_SampleTime_Cycles_7      71.5 cycles
ADC_SampleTime_Cycles_8      239.5 cycles
 *
 *
 */
#define    ADC_SampleTime_Cycles        ADC_SampleTime_Cycles_5

#define    ADC_DataAlign                Right


#endif /* ADC_CONFIG_H_ */
