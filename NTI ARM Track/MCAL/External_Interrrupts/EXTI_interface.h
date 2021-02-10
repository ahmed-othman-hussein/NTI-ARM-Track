/*
 * EXTI_interface.h
 *
 *  Created on: Feb 8, 2021
 *      Author: Boon
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
void EXTI_voidInit(void);
void EXTI_voidEnableLine(u8 Copy_u8LineNum);
void EXTI_voidSetSignalLatch(u8 Copy_u8LineNum, u8 Copy_u8EdgeMode);
void EXTI_voidDisableLine(u8 Copy_u8LineNum );
void EXTI0_voidSetCallBack(void (*pf) (void) );
void EXTI1_voidSetCallBack(void (*pf) (void) );
void EXTI_voidSetSoftwareTrigger(u8 Copy_u8LineNum );
#endif /* EXTI_INTERFACE_H_ */
