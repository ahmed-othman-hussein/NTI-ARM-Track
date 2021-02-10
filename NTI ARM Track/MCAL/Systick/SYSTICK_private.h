/*
 * SYSTICK_private.h
 *
 *  Created on: Feb 9, 2021
 *      Author: ahmed
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_
#define 		SYSTICK_BASE_ADD	              (0xE000E010)




typedef struct
{
	volatile u32 	CTRL;
	volatile u32	LOAD;
	volatile u32 	VAL	;
	volatile u32	CALIB;


}STK_Type;

#define 	STK 		((STK_Type *)0xE000E010)

#define         STK_AHB_DIV_8         1
#define         STK_AHB_DIV_1         3

#define         STK_SINGLE_INTERVAL    1
#define         STK_PERIODIC_INTERVAL    3

#endif /* SYSTICK_PRIVATE_H_ */
