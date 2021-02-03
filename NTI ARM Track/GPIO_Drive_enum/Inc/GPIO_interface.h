/*
 * GPIO_interface.h
 *
 *  Created on: Feb 3, 2021
 *      Author: ahmed
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*void	DIO_voidSetPinDirection(port,pin,mode);*/
void	DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Mode);
/*		if Pin is Output (High or Low)	*/
void	DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Value);
/*		if Pin is Input (Return High or Low)	*/
u8		DIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);

/*		SET PORT DIRECTION											*/
void	DIO_voidSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8Mode);
/*		SET PORT VALUE												*/
void	DIO_voidSetPortValue(u8 Copy_u8PortID,u8 Copy_u8Value);

typedef enum
{
	DIO_U8_PORTA=0,
	DIO_U8_PORTB,
	DIO_U8_PORTC

}Port_t;




typedef enum {
	DIO_U8_PIN0	=0,
	DIO_U8_PIN1	,
	DIO_U8_PIN2	,
	DIO_U8_PIN3	,
	DIO_U8_PIN4	,
	DIO_U8_PIN5	,
	DIO_U8_PIN6	,
	DIO_U8_PIN7	,
	DIO_U8_PIN8	,
	DIO_U8_PIN9	,
	DIO_U8_PIN10,
	DIO_U8_PIN11,
	DIO_U8_PIN12,
	DIO_U8_PIN13,
	DIO_U8_PIN14,
	DIO_U8_PIN15

}Dio_Pin_t;


typedef enum
{
	DIO_U8_HIGH=0,
	DIO_U8_LOW

}Dio_pinState_t;




/*				INPUT Options					*/
#define			DIO_INPUT_ANALOG		0b0000
#define			DIO_INPUT_FLOATING		0b0100
#define			DIO_INPUT_PULL_UP_DOWN	0b1000

/*				OUTPUT 2 MHz Options			*/
#define			DIO_OUTPUT_2MHZ_PP		0b0010
#define			DIO_OUTPUT_2MHZ_OD		0b0110
#define			DIO_OUTPUT_2MHZ_AF_PP	0b1010
#define			DIO_OUTPUT_2MHZ_AF_OD	0b1110

/*				OUTPUT 10 MHz Options			*/
#define			DIO_OUTPUT_10MHZ_PP		0b0001
#define			DIO_OUTPUT_10MHZ_OD		0b0101
#define			DIO_OUTPUT_10MHZ_AF_PP	0b1001
#define			DIO_OUTPUT_10MHZ_AF_OD	0b1101

/*				OUTPUT 50 MHz Options			*/
#define			DIO_OUTPUT_50MHZ_PP		0b0011
#define			DIO_OUTPUT_50MHZ_OD		0b0111
#define			DIO_OUTPUT_50MHZ_AF_PP	0b1011
#define			DIO_OUTPUT_50MHZ_AF_OD	0b1111

#endif /* GPIO_INTERFACE_H_ */
