/**************************************/
/* Description : KYEPAD config c File */
/* Author      : ahmed saeed          */
/* Version     : 0.1V                 */
/* Date        : 02:24:17  07 Aug 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/


#include "DIO_interface.h"

#ifndef KYEPAD_CFG_H
#define KYEPAD_CFG_H



/*output*/
#define KPD_COL0    DIO_PIN_NUM_C0
#define KPD_COL1    DIO_PIN_NUM_C1
#define KPD_COL2    DIO_PIN_NUM_C2
#define KPD_COL3    DIO_PIN_NUM_C3

/*input*/
#define KPD_ROW0    DIO_PIN_NUM_D0
#define KPD_ROW1    DIO_PIN_NUM_D1
#define KPD_ROW2    DIO_PIN_NUM_D2
#define KPD_ROW3    DIO_PIN_NUM_D3


#define KPD_PUTTONS    {\
						{'7' , '8', '9', '/'},\
						{'4' , '5', '6', '*'},\
						{'1', '2','3','-'},\
						{'C', '0','=','+'}\
							}






#endif
