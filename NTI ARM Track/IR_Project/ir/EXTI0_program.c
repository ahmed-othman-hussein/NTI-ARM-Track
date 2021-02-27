/*****************************************/
/* Author  :  Ahmed Assaf                */
/* Version :  V01                        */
/* Date    : 29 August 2020              */
/*****************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"EXTI0_interface.h"
#include"EXTI0_config.h"
#include"EXTI0_private.h"

#define NULL		(void * )0

static void (* EXTI0_CallBack) (void) = NULL ;
static void (* EXTI1_CallBack) (void) = NULL ;

void MEXTI_voidInit(void)
{
	#if		EXTI_LINE == EXTI_LINE0
			SET_BIT(EXTI -> IMR , EXTI_LINE0 );
	#elif	EXTI_LINE == EXTI_LINE1
			SET_BIT(EXTI -> IMR , EXTI_LINE1 );
	#elif	EXTI_LINE == EXTI_LINE2
			SET_BIT(EXTI -> IMR , EXTI_LINE2 );
	#else
		#error ("Wrong Externl Interrupt Line !")
	#endif
	
	
	#if		EXTI_SENSE_MODE == FALLING_EDGE
			SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#elif	EXTI_SENSE_MODE == RISING_EDGE
			SET_BIT(EXTI -> RTSR , EXTI_LINE);
	#elif	EXTI_SENSE_MODE == ON_CHANGE
			SET_BIT(EXTI -> RTSR , EXTI_LINE);
			SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#else
		#error ("Wrong Externl Interrupt Sense Mode !")
	#endif
	
	
}
void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode)
{	
	switch(Copy_u8EXTISenseMode)
	{
		case	RISING_EDGE		:	SET_BIT(EXTI -> RTSR , Copy_u8EXTISenseMode);	break;
		case	FALLING_EDGE	:	SET_BIT(EXTI -> FTSR , Copy_u8EXTISenseMode);	break;
		case	ON_CHANGE		:	SET_BIT(EXTI -> RTSR , Copy_u8EXTISenseMode);
									SET_BIT(EXTI -> FTSR , Copy_u8EXTISenseMode);	break;
	}
	SET_BIT(EXTI -> IMR , Copy_u8EXTILine);
}
void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI -> IMR , Copy_u8EXTILine);
}
void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine)
{
	CLR_BIT(EXTI -> IMR , Copy_u8EXTILine);
	
}
void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine)
{
	
}

void MEXTI_voidSetCallBack(void (*ptr) (void)) // ahmed
{
		EXTI0_CallBack = ptr ; /*ahmed*/
}

void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 0);
	//ahmed();
}
void MEXTI1_voidSetCallBack(void (*ptr) (void)) // ahmed
{
		EXTI1_CallBack = ptr ; /*ahmed*/
}

void	EXTI1_IRQHandler(void)
{
	EXTI1_CallBack();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 1);
	//ahmed();
}
