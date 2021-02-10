/******************************************************/
/* Author  : Ahmed Othman                         */
/* Date    : 6 FEB 2021                              */
/* Version : 1V                                       */
/******************************************************/

#ifndef _SEV_INT_H
#define _SEV_INT_H
#define SEV_LEFT   0
#define SEV_RIGHT  1

#define SEV_TYPE_Decoder   0
#define SEV_TYPE_Anode     1
#define SEV_TYPE_Cathode   2

#define SEV_TYPE           SEV_TYPE_Decoder

void SEV_voidSet7SegmentValue(u8 Copy_u8SevenSegmentNumber , u8 Copy_u8SevenSegmentValue );
void SEV_voidEnable7Segment(u8 Copy_u8SevenSegmentNumber);
void SEV_voidDisable7Segment(u8 Copy_u8SevenSegmentNumber);
 
#endif 
