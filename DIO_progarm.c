/*********************************************************************/
/*  Description    :  DIO program file                               */
/*  Author         :  Ahmed Saeed                                    */
/*  Version        :  0.1 V                                          */
/*  Date           :  2 Aug 2023                                     */
/*  History        :  initial creation                               */
/*********************************************************************/
#include"STD_Types.h"
#include"BIT_Math.h"
#include"DIO_interface.h"
#include"DIO_configuration.h"
#include"DIO_private.h"

void DIO_voidInit(void)
{
	
	DDRA=CONC(DIO_PIN_NUM_A7_DIR,DIO_PIN_NUM_A6_DIR,DIO_PIN_NUM_A5_DIR,DIO_PIN_NUM_A4_DIR,DIO_PIN_NUM_A3_DIR,DIO_PIN_NUM_A2_DIR,DIO_PIN_NUM_A1_DIR,DIO_PIN_NUM_A0_DIR);
	DDRB=CONC(DIO_PIN_NUM_B7_DIR,DIO_PIN_NUM_B6_DIR,DIO_PIN_NUM_B5_DIR,DIO_PIN_NUM_B4_DIR,DIO_PIN_NUM_B3_DIR,DIO_PIN_NUM_B2_DIR,DIO_PIN_NUM_B1_DIR,DIO_PIN_NUM_B0_DIR);
	DDRC =CONC(DIO_PIN_NUM_C7_DIR,DIO_PIN_NUM_C6_DIR,DIO_PIN_NUM_C5_DIR,DIO_PIN_NUM_C4_DIR,DIO_PIN_NUM_C3_DIR,DIO_PIN_NUM_C2_DIR,DIO_PIN_NUM_C1_DIR,DIO_PIN_NUM_C0_DIR);
	DDRD=CONC(DIO_PIN_NUM_D7_DIR,DIO_PIN_NUM_D6_DIR,DIO_PIN_NUM_D5_DIR,DIO_PIN_NUM_D4_DIR,DIO_PIN_NUM_D3_DIR,DIO_PIN_NUM_D2_DIR,DIO_PIN_NUM_D1_DIR,DIO_PIN_NUM_D0_DIR);
}   


tenuErrrorStatus DIO_enuWritePin(uint8 u8PinNumCpy , uint8 u8PinValueCpy)
{
	tenuErrrorStatus enuReturnStateLoc =EOK ;
	
	
	if (u8PinNumCpy>=DIO_PIN_NUM_A0  && u8PinNumCpy<= DIO_PIN_NUM_A7)
	{
		switch(u8PinValueCpy)
		{
			case DIO_HIGH :
			SET_BIT(PORTA ,u8PinNumCpy);
			break;
			case DIO_LOW :
			CLR_BIT(PORTA,u8PinNumCpy);
			break;
			default :
			enuReturnStateLoc = PARAMRETER_OUT_RANGE;
			break;
			
		}		
	}	
	else if (u8PinNumCpy>=DIO_PIN_NUM_B0 && u8PinNumCpy<=DIO_PIN_NUM_B7)
	{
		switch(u8PinValueCpy)
		{
			case DIO_HIGH :
			SET_BIT(PORTB ,u8PinNumCpy%8);
			break;
			case DIO_LOW :
			CLR_BIT(PORTB,u8PinNumCpy%8);  //-8
			break;
			default :
			enuReturnStateLoc = PARAMRETER_OUT_RANGE;
			break;
			
		}	
		
	}
	else if (u8PinNumCpy>=DIO_PIN_NUM_C0 && u8PinNumCpy<=DIO_PIN_NUM_C7)
	{
		
		switch(u8PinValueCpy)
		{
			case DIO_HIGH :
			SET_BIT(PORTC ,u8PinNumCpy%8);  //-16
			break;
			case DIO_LOW :
			CLR_BIT(PORTC,u8PinNumCpy%8);
			break;
			default :
			enuReturnStateLoc = PARAMRETER_OUT_RANGE;
			break;
			
		}	
		
		
	}
	else if (u8PinNumCpy>=DIO_PIN_NUM_D0 && u8PinNumCpy<=DIO_PIN_NUM_D7)
	{
		
		switch(u8PinValueCpy)
		{
			case DIO_HIGH :
			SET_BIT(PORTD ,(u8PinNumCpy%8));  //-16
			break;
			case DIO_LOW :
			CLR_BIT(PORTD,(u8PinNumCpy%8));
			break;
			default :
			enuReturnStateLoc = PARAMRETER_OUT_RANGE;
			break;
			
		}	
		
		
	}
	else 
	{
		enuReturnStateLoc=PARAMRETER_OUT_RANGE;
	}
	
	
	return enuReturnStateLoc;
	
	
}
 
tenuErrrorStatus DIO_enuReadPin(uint8 u8PinNumCpy , uint8* pu8PinValue)
{
	tenuErrrorStatus enuReturnStateLoc =EOK ;
	
	
	if (pu8PinValue!= NULL_PTR)
	{
		if (u8PinNumCpy>=DIO_PIN_NUM_A0  && u8PinNumCpy<= DIO_PIN_NUM_A7)
		{
			
			*pu8PinValue=GET_BIT(PINA,u8PinNumCpy);
		}
		else if (u8PinNumCpy>=DIO_PIN_NUM_B0 && u8PinNumCpy<=DIO_PIN_NUM_B7)
		{
			*pu8PinValue=GET_BIT(PINB,u8PinNumCpy%8);
		}
		else if (u8PinNumCpy>=DIO_PIN_NUM_C0 && u8PinNumCpy<=DIO_PIN_NUM_C7)
		{
			*pu8PinValue=GET_BIT(PINC,u8PinNumCpy%8);
		}
		else if (u8PinNumCpy>=DIO_PIN_NUM_D0 && u8PinNumCpy<=DIO_PIN_NUM_D7)
		{
			*pu8PinValue=GET_BIT(PIND,u8PinNumCpy%8);
		}
		else
		{
			enuReturnStateLoc= PARAMRETER_OUT_RANGE;
		}
	}
	else
	{
		enuReturnStateLoc=PARAMERTE_NULL_PTR;
	}
	return enuReturnStateLoc;
	
}

tenuErrrorStatus DIO_enuStatePullup(uint8 u8PinNumCpy , uint8 u8StateCpy)
{
	
	return DIO_enuWritePin(u8PinNumCpy,u8StateCpy);
	
}


tenuErrrorStatus DIO_enuWriteGroup(uint8* pau8PinNumCpy , uint8* pau8PinValueCpy,uint8 u8Sizecpy)
{
	tenuErrrorStatus enuReturnStateLoc =EOK;
	
	uint8 u8CounterLoc=0;
	
	for ( u8CounterLoc=0 ;   u8CounterLoc< u8Sizecpy ;u8CounterLoc++)
	{
		enuReturnStateLoc=DIO_enuWritePin(pau8PinNumCpy[u8CounterLoc],pau8PinValueCpy[u8CounterLoc]);
		
		if (enuReturnStateLoc !=EOK)
		{
			break;
		}
	}
	
	return enuReturnStateLoc;
}








