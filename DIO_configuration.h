/*********************************************************************/
/*  Description    :  DIO configuration file                         */                                 
/*  Author         :  Ahmed Saeed                                    */
/*  Version        :  0.1 V                                          */
/*  Date           :  2 Aug 2023                                     */
/*  History        :  initial creation                               */                                   
/*********************************************************************/
#ifndef    DIO_CONGIGURATION_H
#define    DIO_CONGIGURATION_H

 
/* PORT A*/
#define DIO_PIN_NUM_A0_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_A1_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_A2_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_A3_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_A4_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_A5_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_A6_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_A7_DIR        DIO_OUTPUT
/* PORT B*/                      

#define DIO_PIN_NUM_B0_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_B1_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_B2_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_B3_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_B4_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_B5_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_B6_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_B7_DIR        DIO_OUTPUT

/* PORT C*/

#define DIO_PIN_NUM_C0_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_C1_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_C2_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_C3_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_C4_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_C5_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_C6_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_C7_DIR        DIO_OUTPUT

/* PORT D*/
#define DIO_PIN_NUM_D0_DIR        DIO_INPUT
#define DIO_PIN_NUM_D1_DIR        DIO_INPUT
#define DIO_PIN_NUM_D2_DIR        DIO_INPUT
#define DIO_PIN_NUM_D3_DIR        DIO_INPUT
#define DIO_PIN_NUM_D4_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_D5_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_D6_DIR        DIO_OUTPUT
#define DIO_PIN_NUM_D7_DIR        DIO_OUTPUT



/* default value for pin 0 port A  to be out */
#ifndef DIO_PIN_NUM_A0_DIR 
#define DIO_PIN_NUM_A0_DIR    DIO_OUTPUT
#endif 





#endif 
