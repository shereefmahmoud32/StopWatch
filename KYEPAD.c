/**************************************/
/* Description : KYEPAD c File        */
/* Author      : ahmed saeed          */
/* Version     : 0.1V                 */
/* Date        : 02:24:17  07 Aug 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/

#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "KYEPAD.h"
#include "KYEPAD_cfg.h"
#include "KYEPAD_priv.h"



void KPD_voidInit(void)
{
	DIO_enuWritePin(KPD_COL0,DIO_HIGH);
	DIO_enuWritePin(KPD_COL1,DIO_HIGH);
	DIO_enuWritePin(KPD_COL2,DIO_HIGH);
	DIO_enuWritePin(KPD_COL3,DIO_HIGH);

	DIO_enuStatePullup(KPD_ROW0,DIO_ACTIVATE_PULLUP);
	DIO_enuStatePullup(KPD_ROW1,DIO_ACTIVATE_PULLUP);
	DIO_enuStatePullup(KPD_ROW2,DIO_ACTIVATE_PULLUP);
	DIO_enuStatePullup(KPD_ROW3,DIO_ACTIVATE_PULLUP);

}
uint8 KPD_u8GetPressedKey(void)
{
	static uint8 u8KpdColArr[4]={KPD_COL0,KPD_COL1,KPD_COL2,KPD_COL3};
	static uint8 u8KpdRowArr[4]={KPD_ROW0,KPD_ROW1,KPD_ROW2,KPD_ROW3};
	static uint8 u8KpdColIdx;
	static uint8 u8KpdRowIdx;
	static uint8 u8KpdPinState;
	uint8 u8KpdPressedKeyLoc=NOT_KEY_PRESSED;

	static uint8 au8KpdArrLoc[4][4]= KPD_PUTTONS;


	for (u8KpdColIdx=0 ;u8KpdColIdx<4 ;u8KpdColIdx++)
	{
		DIO_enuWritePin(u8KpdColArr[u8KpdColIdx],DIO_LOW);


		for(u8KpdRowIdx=0;u8KpdRowIdx<4;u8KpdRowIdx++)
		{
			DIO_enuReadPin(u8KpdRowArr[u8KpdRowIdx],&u8KpdPinState);
			if (u8KpdPinState==DIO_LOW)
			{
				u8KpdPressedKeyLoc=au8KpdArrLoc[u8KpdRowIdx][u8KpdColIdx];

				while(u8KpdPinState==DIO_LOW)
				{
					DIO_enuReadPin(u8KpdRowArr[u8KpdRowIdx],&u8KpdPinState);
				}
				DIO_enuWritePin(u8KpdColArr[u8KpdColIdx],DIO_HIGH);

				return u8KpdPressedKeyLoc;
			}

		}
		DIO_enuWritePin(u8KpdColArr[u8KpdColIdx],DIO_HIGH);

	}
	return u8KpdPressedKeyLoc;


}
