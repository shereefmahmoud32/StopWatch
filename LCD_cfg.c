/***************************************/
/* Description : LCD config header File*/
/* Author      : ahmed saeed           */
/* Version     : 0.1V                  */
/* Date        : 12:59:55  06 Aug 2023 */
/* History     : 0.1V Initial Creation */
/***************************************/
#include "STD_Types.h"
#include"DIO_interface.h"
#include"LCD_cfg.h"
#include"LCD_priv.h"

lcdconfig lcdarr[MAX_NUM]=
{
		{
				{
					LCD_8_BIT_MODE,LCD_TWO_LINE,LCD_FONT_5X7,LCD_COURSOR_ON,
					LCD_COURSOR_BLINK_OFF,LCD_SHIFT_OFF,LCD_DISPLAY_ON,LCD_LTR
				},


				{           /* RS*/         /* E*/      /* RW*/
						DIO_PIN_NUM_A0 ,DIO_PIN_NUM_A1,DIO_PIN_NUM_A2 ,

						{      /*DB0 */              /*DB0 */
								DIO_PIN_NUM_B0 ,DIO_PIN_NUM_B1,DIO_PIN_NUM_B2,
								DIO_PIN_NUM_B3,DIO_PIN_NUM_B4,DIO_PIN_NUM_B5,
								DIO_PIN_NUM_B6,DIO_PIN_NUM_B7


						}


				}
		}

};

