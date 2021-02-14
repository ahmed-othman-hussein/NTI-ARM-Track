/*
 * ADC_Private.h
 *
 *  Created on: Feb 11, 2021
 *      Author: ahmed
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

typedef struct
{
	volatile u32 SR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMPR1;
	volatile u32 SMPR2;
	volatile u32 JOFR1;
	volatile u32 JOFR2;
	volatile u32 JOFR3;
	volatile u32 JOFR4;
	volatile u32 HTR;
	volatile u32 LTR;
	volatile u32 SQR1;
	volatile u32 SQR2;
	volatile u32 SQR3;
	volatile u32 JSQR;
	volatile u32 JDR1;
	volatile u32 JDR2;
	volatile u32 JDR3;
	volatile u32 JDR4;
	volatile u32 DR;
}ADC_REG;

#define 	ADC		((ADC_REG *)(0x40012400))
//#define 	ADC_BASE		(0x40012400)
//#define 	ADC_CR2				*((u32 * )(ADC_BASE + 0x08))

#define		RCC_BASE_ADD		(0x40021000)
#define 	RCC_CFGR			*((u32 * )(RCC_BASE_ADD + 0x04))

#define 	PCLK2_divided_by_2     1
#define 	PCLK2_divided_by_4     2
#define 	PCLK2_divided_by_6     3
#define 	PCLK2_divided_by_8     4




#endif /* ADC_PRIVATE_H_ */
