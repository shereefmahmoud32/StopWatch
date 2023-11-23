/*
 * main.c
 *
 *  Created on: Aug 7, 2023
 *      Author: ahmed saeed
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "KYEPAD.h"
#include "LCD.h"
#include "util/delay.h"


uint8 u8CursorPos=0;
uint8 u8arrClk[3];
uint8 arr[8]={'0','0',':','0','0',':','0','0'};
sint8 HR,MN,SC;
void print_lcd()
{
	uint8 i=0;
	LCD_voidMoveCourser(0,1,0);
	for(i=0;i<8;i++)
	{
		if(i==2 || i==5)
		{
			/* donothing*/
		}
		else
		{
			arr[i]='0';

		}
		LCD_voidSendChar(0,arr[i]);
	}
	u8CursorPos=0;

	LCD_voidMoveCourser(0,1,u8CursorPos);

}

void scan(uint8 arr[])
{
	u8arrClk[0]=((arr[0]-'0')*10)+(arr[1]-'0');
	u8arrClk[1]=((arr[3]-'0')*10)+(arr[4]-'0');
	u8arrClk[2]=((arr[6]-'0')*10)+(arr[7]-'0');
	HR=u8arrClk[0];
	MN=u8arrClk[1];
	SC=u8arrClk[2];

}


void startStopWatch()
{
	uint8 CounterLoc=0;


	for(HR;HR>=0;HR--)
	{
		LCD_voidMoveCourser(0,1,0);
		LCD_sendNumber(HR);
		for(MN;MN>=0;MN--)
		{
			if(MN>59)
				MN=59;
			LCD_voidMoveCourser(0,1,3);
			LCD_sendNumber(MN);

			for(SC;SC>=0;SC--)
			{
				if(SC>59)
					SC=59;
				_delay_ms(1000);
				LCD_voidMoveCourser(0,1,6);
				LCD_sendNumber(SC);
			}
			if((SC<0) && (MN>0 || HR>0))  //Seconds Reset
				SC=59;
		}
		if((MN<0) && (HR>0))  //Minutes Reset
				MN=59;
	}
	LCD_voidMoveCourser(0,0,0);
	LCD_voidSendString(0,"its The Time :D");

}

void main (void)
{

	DIO_voidInit();
	LCD_voidInit();
	KPD_voidInit();
	uint8 u8key=0xff;
	LCD_voidSendString(0,"HR:MN:SC");
	LCD_voidMoveCourser(0,1,u8CursorPos);
	print_lcd(arr);


	while(1)
	{


		u8key=KPD_u8GetPressedKey();

		if(u8key=='+')
		{

			if(u8CursorPos==7)
			{
				//do nothing
			}
			else
			{
				u8CursorPos++;
			}
			LCD_voidMoveCourser(0,1,u8CursorPos);

		}
		else if(u8key=='-')
		{
			if(u8CursorPos==0)
			{
				//do nothing
			}
			else
			{
				u8CursorPos--;
			}

			LCD_voidMoveCourser(0,1,u8CursorPos);

		}
		else if(u8key=='/')
		{
			if(arr[u8CursorPos]=='0' || arr[u8CursorPos]==':')
			{
				//do nothing
			}
			else
			{
				arr[u8CursorPos]--;

			}

			LCD_voidSendChar(0,arr[u8CursorPos]);
			LCD_voidMoveCourser(0,1,u8CursorPos);



		}

		else if(u8key=='*')
				{
					if(arr[u8CursorPos]=='9' || arr[u8CursorPos]==':')
					{
						//do nothing
					}
					else
					{
						arr[u8CursorPos]++;

					}
					LCD_voidSendChar(0,arr[u8CursorPos]);
					LCD_voidMoveCourser(0,1,u8CursorPos);


				}
		else if(u8key=='C')
		{
			print_lcd();
		}
		else if (u8key=='=')
		{
			scan(arr);
			startStopWatch();
		}


	}


}
