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

typedef enum
{
	RCC_AHB= 0,
	RCC_APB1 ,
	RCC_APB2

}RCC_BUS_t;


typedef enum
{
 	RCC_GPIOA_ID=2,
	RCC_GPIOB_ID,
 	RCC_GPIOC_ID

}RCC_GPIO_ID_t;


#endif /* RCC_INTERFACE_H_ */
