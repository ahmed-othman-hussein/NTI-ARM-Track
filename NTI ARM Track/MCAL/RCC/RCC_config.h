/*
 * RCC_config.h
 *
 *  Created on: Feb 2, 2021
 *      Author: ahmed
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_
/*  CLOCK_TYPE can be:
 * 1-RCC_HSI
 * 2-RCC_HSE
 * 3-RCC_PPL
 *
 */
#define CLOCK_TYPE      RCC_PLL
#if     CLOCK_TYPE  ==  RCC_HSE
/*   can be RCC_CRYSTAL OR RCC_RC*/
#define RCC_HSE_SOURCE  RCC_CRYSTAL

#endif
#if CLOCK_TYPE    ==  RCC_HSE
/* PLL Multiplication factor 1:16   */
#define RCC_PLL_MUL   1

/* PLL SOURCE(HSI/HSE)  */
#define RCC_PLL_SOURCE   RCC_HSI

/*  PLL ENTRY SOURCE IS HSE DIVISON/2 OR NOT  */
#define RCC_PLL_SOURCE_HSE   HSE_DEVIDE_TWO

#endif

#endif /* RCC_CONFIG_H_ */
