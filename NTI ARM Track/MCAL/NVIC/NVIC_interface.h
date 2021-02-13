/*
 * NVIC_interface.h
 *
 *  Created on: Feb 7, 2021
 *      Author: ahmed
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

void NVIC_voidInit(void);

void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptNum);
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptNum);

void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptNum);
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptNum);

u8	 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptNum);

void NVIC_voidSetPriority(u8 Copy_u8InterruptNum , u8 Copy_u8PerPriority);

#endif /* NVIC_INTERFACE_H_ */
