/*****************************************/
/* Author  :  Ahmed Assaf                */
/* Version :  V01                        */
/* Date    : 29 August 2020              */
/*****************************************/
#ifndef EXTI0_INTERFACE_H
#define EXTI0_INTERFACE_H

void MEXTI_voidInit(void);
void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode);
void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine);
void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine);
void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine);

void MEXTI_voidSetCallBack(void (*ptr) (void));
void MEXTI1_voidSetCallBack(void (*ptr) (void));

#define		 FALLING_EDGE		1

#define		 RISING_EDGE		3

#define		 ON_CHANGE			5

#define		 EXTI_LINE0			0

#define		 EXTI_LINE1			1

#define		 EXTI_LINE2			2

#endif
