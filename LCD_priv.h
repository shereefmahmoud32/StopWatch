/**************************************/
/* Description : LCD private c File   */
/* Author      : ahmed saeed          */
/* Version     : 0.1V                 */
/* Date        : 12:59:55  06 Aug 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef LCD_PRIV_H
#define LCD_PRIV_H

#define LCD_8_BIT_MODE   1
#define LCD_4_BIT_MODE   0

#define LCD_ONE_LINE     0
#define LCD_TWO_LINE     1

#define LCD_FONT_5X11    1
#define LCD_FONT_5X7     0

#define LCD_COURSOR_ON   1
#define LCD_COURSOR_OFF  0

#define LCD_COURSOR_BLINK_ON   1
#define LCD_COURSOR_BLINK_OFF  0

#define LCD_SHIFT_ON           1
#define LCD_SHIFT_OFF          0

#define LCD_DISPLAY_ON         1
#define LCD_DISPLAY_OFF        0


#define LCD_RTL                0
#define LCD_LTR                1



typedef struct
{
	uint8 u8mode         :1 ;
	uint8 u8line         :1 ;
	uint8 u8font         :1 ;
	uint8 u8coursorstate :1 ;
	uint8 u8coursorblink :1 ;
	uint8 u8shift        :1 ;
	uint8 u8display      :1 ;
	uint8 u8direction    :1 ;


}tstrlcdswconfig;


typedef struct
{
	uint8 u8RS ;
	uint8 u8E ;
	uint8 u8RW ;
	uint8 au8data[8];
}tstrlcdhwconfig;



typedef struct
{
	tstrlcdswconfig  lcdswconfig ;
	tstrlcdhwconfig  lcdhwconfig;

}lcdconfig;

extern lcdconfig lcdarr[MAX_NUM];
static void voidWriteCmd(uint8 u8Index , uint8 u8CmdCPy);
static void  LCDHelp (uint8 u8Index , uint8 u8dataCmdCPy);


#endif
