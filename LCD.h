/**************************************/
/* Description : LCD header File      */
/* Author      : ahmed saeed          */
/* Version     : 0.1V                 */
/* Date        : 12:59:55  06 Aug 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef LCD_H
#define LCD_H




void LCD_voidSendChar(uint8 u8IndexCpy, uint8 u8CharCpy);
void LCD_voidSendCommand(uint8 u8IndexCpy, uint8 u8CommandCpy);

void LCD_voidInit(void);


void LCD_voidClrScr(uint8 u8IndexCpy);

void LCD_sendNumber(uint32 u32NumberCpy);

void LCD_voidDisplayHex(uint8 u8IndexCpy,uint16 u16HexNumberCpy );
void LCD_voidMoveCourser(uint8 u8IndexCpy,uint8 u8RowCPy,uint8 u8ColmCpy);

void LCD_voidSendString(uint8 u8IndexCpy, uint8* pau8CharCpy);

#endif
