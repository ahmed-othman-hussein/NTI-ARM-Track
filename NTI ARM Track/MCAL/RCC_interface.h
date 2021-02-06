/*
 * RCC_interface.h
 *
 *  Created on: Feb 2, 2021
 *      Author: ahmed
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

void RCC_voidInit(void);
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID);
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID);

#define RCC_AHB      0
#define RCC_APB1     1
#define	RCC_APB2     2


#define 	RCC_GPIOA_ID		2
#define 	RCC_GPIOB_ID		3
#define 	RCC_GPIOC_ID		4

#endif /* RCC_INTERFACE_H_ */
