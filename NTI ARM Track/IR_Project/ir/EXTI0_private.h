/*****************************************/
/* Author  :  Ahmed Assaf                */
/* Version :  V01                        */
/* Date    : 29 August 2020              */
/*****************************************/
#ifndef EXTI0_PRIVATE_H
#define EXTI0_PRIVATE_H


typedef	struct
{
	volatile	u32		IMR;
	volatile	u32		EMR;
	volatile	u32		RTSR;
	volatile	u32		FTSR;
	volatile	u32		SWIER;
	volatile	u32		PR;
	
}EXTI_Type;

#define	EXTI		((volatile EXTI_Type *)0x40010400)



#endif
