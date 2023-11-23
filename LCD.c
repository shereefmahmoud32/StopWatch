/**************************************/
/* Description : LCD c File           */
/* Author      : ahmed saeed          */
/* Version     : 0.1V                 */
/* Date        : 12:59:55  06 Aug 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/


#include "util/delay.h"
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include "LCD_priv.h"


void LCD_voidInit(void)
{
	uint8 u8CntLoc;
	uint8 u8commnad=0;
	for (u8CntLoc =0  ; u8CntLoc <MAX_NUM ; u8CntLoc++)
	{
		/*inilize 8 bit */
		if(lcdarr[u8CntLoc].lcdswconfig.u8mode ==LCD_8_BIT_MODE)
		{
			/*step 1*/
			_delay_ms(30);

			u8commnad=0b00110000 |lcdarr[u8CntLoc].lcdswconfig.u8font <<2
					|lcdarr[u8CntLoc].lcdswconfig.u8line<<3 ;
			/* send command */
			voidWriteCmd(u8CntLoc,u8commnad);
			/*more than 39 micro*/
			_delay_ms(1);
			u8commnad=0b00001000 |lcdarr[u8CntLoc].lcdswconfig.u8display<<2 |
									lcdarr[u8CntLoc].lcdswconfig.u8coursorstate<<1 |
									lcdarr[u8CntLoc].lcdswconfig.u8coursorblink<<0 ;

			voidWriteCmd(u8CntLoc,u8commnad);
			_delay_ms(1);
			voidWriteCmd(u8CntLoc,0x01);
			_delay_ms(3);
			u8commnad=0b00000100 | lcdarr[u8CntLoc].lcdswconfig.u8direction<<1 |

								lcdarr[u8CntLoc].lcdswconfig.u8shift<<0;


			voidWriteCmd(u8CntLoc,u8commnad);
			/*extra delay*/
			_delay_ms(3);


		}
		else
		{
			/*step 1*/
			_delay_ms(30);
			voidWriteCmd(u8CntLoc,0b00100000);

			voidWriteCmd(u8CntLoc,0b00100000);

			u8commnad=0b00000000 |lcdarr[u8CntLoc].lcdswconfig.u8line<<7 |
			lcdarr[u8CntLoc].lcdswconfig.u8font <<6 ;

			voidWriteCmd(u8CntLoc,u8commnad);
			_delay_ms(1);

			voidWriteCmd(u8CntLoc,0b00000000);

			u8commnad=0b10000000 |lcdarr[u8CntLoc].lcdswconfig.u8display<<6|
			lcdarr[u8CntLoc].lcdswconfig.u8coursorstate<<5 |
			lcdarr[u8CntLoc].lcdswconfig.u8coursorblink<<4 ;
			voidWriteCmd(u8CntLoc,u8commnad);
			_delay_ms(1);
			voidWriteCmd(u8CntLoc,0b00000000);
			voidWriteCmd(u8CntLoc,0b00010000);
			_delay_ms(3);
			voidWriteCmd(u8CntLoc,0b00000000);

			u8commnad= 0b01000000 | lcdarr[u8CntLoc].lcdswconfig.u8direction<<5 |
					   lcdarr[u8CntLoc].lcdswconfig.u8shift<<4 ;


			voidWriteCmd(u8CntLoc,u8commnad);
			/*extra delay*/
			_delay_ms(3);



		}


	}



}


static void voidWriteCmd(uint8 u8Index , uint8 u8CmdCPy)
 {

	/*RS   0*/
	DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.u8RS , DIO_LOW);

	/*help*/
	LCDHelp(u8Index,u8CmdCPy);

 }

static void  LCDHelp(uint8 u8Index , uint8 u8dataCmdCPy)
	{
		uint8 u8CntLoc=0;
		/*set to write to lCD */
		DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.u8RW , DIO_LOW);

		DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.u8E , DIO_HIGH);

		if (lcdarr[u8Index].lcdswconfig.u8mode==LCD_8_BIT_MODE)
		{
			for (u8CntLoc =0 ;u8CntLoc<8;u8CntLoc++)
			{
				DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.au8data[u8CntLoc],GET_BIT(u8dataCmdCPy,u8CntLoc));
			}

		}

		else
		{
			for (u8CntLoc =4 ;u8CntLoc<8;u8CntLoc++)
			{
				DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.au8data[u8CntLoc],GET_BIT(u8dataCmdCPy,u8CntLoc));
			}
		}
			/* latch */
		_delay_ms(10);
		DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.u8E , DIO_LOW);
		/*extra delay*/
		_delay_ms(10);
	}

void LCD_voidSendChar(uint8 u8IndexCpy, uint8 u8CharCpy)

{
	/*RS  1*/
	DIO_enuWritePin(lcdarr[u8IndexCpy].lcdhwconfig.u8RS , DIO_HIGH);


	if (lcdarr[u8IndexCpy].lcdswconfig.u8mode==LCD_8_BIT_MODE)
	{
		LCDHelp(u8IndexCpy,u8CharCpy);
		_delay_ms(1);

	}
	else
	{
		LCDHelp(u8IndexCpy,u8CharCpy);
		_delay_ms(1);
		LCDHelp(u8IndexCpy,u8CharCpy<<4);
		_delay_ms(1);

	}

	}



void LCD_voidSendCommand(uint8 u8IndexCpy, uint8 u8CommandCpy)
{
	if (lcdarr[u8IndexCpy].lcdswconfig.u8mode==LCD_8_BIT_MODE)
		{
			voidWriteCmd(u8IndexCpy,u8CommandCpy);
			_delay_ms(1);

		}
		else
		{
			voidWriteCmd(u8IndexCpy,u8CommandCpy);
			_delay_ms(1);
			voidWriteCmd(u8IndexCpy,u8CommandCpy<<4);
			_delay_ms(1);
		}

}



void LCD_voidSendString(uint8 u8IndexCpy, uint8* pau8CharCpy)
{
	uint8 u8CntLoc=0;
	while(pau8CharCpy[u8CntLoc]!= '\0')
			{
				LCD_voidSendChar(u8IndexCpy,pau8CharCpy[u8CntLoc])	;
				u8CntLoc++;
			}
}

void LCD_voidClrScr(uint8 u8IndexCpy)
	{
		LCD_voidSendCommand(u8IndexCpy,0x01);
	}

void LCD_sendNumber(uint32 u32NumberCpy)
{
	sint8 CounterLoc=0;
	uint8 number [10];

	if(u32NumberCpy==0)
	{
		LCD_voidSendChar(0,'0');
		LCD_voidSendChar(0,'0');
	}
	else
	{
		while(u32NumberCpy)
		{
			number[CounterLoc] = (u32NumberCpy%10)+'0'  ;
			u32NumberCpy/=10;
			CounterLoc++;
		}

		if(CounterLoc==1)
		{
			LCD_voidSendChar(0,'0');
			LCD_voidSendChar(0,number[0]);

		}
		else
		{
			for (CounterLoc--;CounterLoc>=0;CounterLoc--)
			{
				LCD_voidSendChar(0,number[CounterLoc]);

			}
		}
	}
}


void LCD_voidDisplayHex(uint8 u8IndexCpy,uint16 u16HexNumberCpy )
{}
void LCD_voidMoveCourser(uint8 u8IndexCpy,uint8 u8RowCPy,uint8 u8ColmCpy)
{

		uint8 Local_u8Address;
		Local_u8Address = (u8RowCPy * 0x40) + u8ColmCpy;
		SET_BIT(Local_u8Address, 7);
		LCD_voidSendCommand(u8IndexCpy, Local_u8Address);
}
