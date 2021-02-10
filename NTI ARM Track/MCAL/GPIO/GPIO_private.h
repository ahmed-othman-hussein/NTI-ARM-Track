/*
 * GPIO_private.h
 *
 *  Created on: Feb 3, 2021
 *      Author: ahmed
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define     GPIOA_BASE_ADD      (0x40010800)
#define     GPIOB_BASE_ADD      (0x40010C00)
#define     GPIOC_BASE_ADD      (0x40011000)

 /*        PORTA REGISTERS         */
#define     GPIOA_CRL      *((u32*)(GPIOA_BASE_ADD + 0x00))
#define     GPIOA_CRH      *((u32*)(GPIOA_BASE_ADD + 0x04))
#define     GPIOA_IDR      *((u32*)(GPIOA_BASE_ADD + 0x08))
#define     GPIOA_ODR      *((u32*)(GPIOA_BASE_ADD + 0x0C))
#define     GPIOA_BSR      *((u32*)(GPIOA_BASE_ADD + 0x10))
#define     GPIOA_BRR      *((u32*)(GPIOA_BASE_ADD + 0x14))
#define     GPIOA_LCK      *((u32*)(GPIOA_BASE_ADD + 0x18))

 /*        PORTA REGISTERS         */
#define     GPIOB_CRL      *((u32*)(GPIOB_BASE_ADD + 0x00))
#define     GPIOB_CRH      *((u32*)(GPIOB_BASE_ADD + 0x04))
#define     GPIOB_IDR      *((u32*)(GPIOB_BASE_ADD + 0x08))
#define     GPIOB_ODR      *((u32*)(GPIOB_BASE_ADD + 0x0C))
#define     GPIOB_BSR      *((u32*)(GPIOB_BASE_ADD + 0x10))
#define     GPIOB_BRR      *((u32*)(GPIOB_BASE_ADD + 0x14))
#define     GPIOB_LCK      *((u32*)(GPIOB_BASE_ADD + 0x18))

 /*        PORTA REGISTERS         */
#define     GPIOC_CRL      *((u32*)(GPIOC_BASE_ADD + 0x00))
#define     GPIOC_CRH      *((u32*)(GPIOC_BASE_ADD + 0x04))
#define     GPIOC_IDR      *((u32*)(GPIOC_BASE_ADD + 0x08))
#define     GPIOC_ODR      *((u32*)(GPIOC_BASE_ADD + 0x0C))
#define     GPIOC_BSR      *((u32*)(GPIOC_BASE_ADD + 0x10))
#define     GPIOC_BRR      *((u32*)(GPIOC_BASE_ADD + 0x14))
#define     GPIOC_LCK      *((u32*)(GPIOC_BASE_ADD + 0x18))
#endif /* GPIO_PRIVATE_H_ */
