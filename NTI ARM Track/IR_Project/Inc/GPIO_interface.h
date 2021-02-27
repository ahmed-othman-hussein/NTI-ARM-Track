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


#define 		DIO_U8_PORTA			0
#define 		DIO_U8_PORTB			1
#define 		DIO_U8_PORTC			2

#define 		DIO_U8_PIN0		    	0
#define 		DIO_U8_PIN1		    	1
#define 		DIO_U8_PIN2		    	2
#define 		DIO_U8_PIN3		    	3
#define 		DIO_U8_PIN4		    	4
#define 		DIO_U8_PIN5		    	5
#define 		DIO_U8_PIN6		    	6
#define 		DIO_U8_PIN7		    	7
#define 		DIO_U8_PIN8		    	8
#define 		DIO_U8_PIN9		    	9
#define 		DIO_U8_PIN10	    	10
#define 		DIO_U8_PIN11	    	11
#define 		DIO_U8_PIN12	    	12
#define 		DIO_U8_PIN13	    	13
#define 		DIO_U8_PIN14	    	14
#define 		DIO_U8_PIN15	    	15

#define 		DIO_U8_HIGH				1
#define 		DIO_U8_LOW				0

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
