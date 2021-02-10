/*
 * SYSTICK_interface.h
 *
 *  Created on: Feb 9, 2021
 *      Author: ahmed
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

void STK_voidInit(void);
void STK_voidSetBusyWait(u32 Copy_u32Ticks);
void STK_voidIntervalSingle(u32 Copy_u32Ticks,void (*copy_pf)(void));
void STK_voidIntervalPeriodic(u32 Copy_u32Ticks,void (*copy_pf)(void));
void STK_voidStopInterval(void);
u32 STK_u32GetCounts(void);
u32 STK_u32GetRemainingTime(void);

/*
void STK_voidEnableSTK(void);
void STK_voidEnableInterrupt(void);
*/

#endif /* SYSTICK_INTERFACE_H_ */
