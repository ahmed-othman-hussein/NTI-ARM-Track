/******************************************************/
/* Author  : Ahmed othman                         */
/* Date    : 4 FEB 2021                             */
/* Version : 1V                                       */
/******************************************************/

#ifndef _LCD_INT_H
#define _LCD_INT_H




void LCD_vidInit( void ); 

void LCD_vidSendCmd( u8 u8CmdCpy );

void LCD_vidWriteChar( u8 u8CharCpy );

void LCD_vidClear( void );

void LCD_vidGotoXY( u8 u8LineNbCpy , u8 u8CharNbCpy );

void LCD_vidWriteString( u8 * pu8StringCpy );

#endif 
