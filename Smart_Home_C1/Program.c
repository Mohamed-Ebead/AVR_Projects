/*
 * Program.c
 *
 *   Created on: 20 January 2020
 *      Author: Mohamed Ebead
 */


#include "STD_TYPES.h"
#include "Configuration.h"
#include "interface.h"
#include "registers.h"
#include "BIT_MATH.h"
#include "interface.h"

#include "DIO_int.h"
#include "ADC_interface.h"


extern u16 u16Temp ;
extern u8 u8Lumen ;

/************************************************************/


void vid_DIO_vid_SetDioDirections (void) {

/*********************** Analog Input *************************/
	DIO_SetPinDirection (PORTA_DIO,TEMP_SENSOR,INPUT) ;
	DIO_SetPinDirection (PORTA_DIO,LDR,INPUT) ;

/******************** External Interrupt **********************/
	DIO_SetPinDirection (PORTD_DIO,PIR1,INPUT) ;
	DIO_SetPinDirection (PORTD_DIO,PIR2,INPUT) ;


/********************** Digital Output ************************/
	DIO_SetPinDirection (PORTB_DIO,DOOR1,OUTPUT) ;
	DIO_SetPinDirection (PORTB_DIO,DOOR2,OUTPUT) ;

/************************ PWM Output *************************/
	DIO_SetPinDirection (PORTB_DIO,FAN,OUTPUT) ;
	DIO_SetPinDirection (PORTD_DIO,LIGHT,OUTPUT) ;



/************************ PORTS INITIALIZATION *************************/

	//DIO_SetPinValue(PORTA_DIO , LDR, HIGH);       //connect A1 to pull up resistors
	DIO_SetPinValue(PORTD_DIO , PIR1, HIGH);
	DIO_SetPinValue(PORTD_DIO , PIR2, HIGH);

}


/************************************************************/

void UpdateFanSpeed (void) {

	u8 u8_ADC_Read = 0 ;
	u16 u16Volt = 0 ;


	u8_ADC_Read = U8_ADC_U8_Read(0) + ADC_Correction_Factor ;
	u16Volt =( ( ( (u32)u8_ADC_Read *  5000UL) ) / 1024UL ) + 10 ;  // 1500
	u16Temp = u16Volt/10 ;



if      (u16Temp<=20)                  {OCR0_REG = 0 ; }
else if ((u16Temp>20)&&(u16Temp<=27))  {OCR0_REG = 127 ; }
else if ((u16Temp>27)&&(u16Temp<=30))  {OCR0_REG = 200 ; }
else                                   { OCR0_REG=255 ; }

}

/************************************************************/

void UpdateLightIlluminance (void) {

	u8 u8LDR_Read = U8_ADC_U8_Read(1)  ;

	u8Lumen  = u8LDR_Read ;

	//OCR2_REG = u8LDR_Read ;

	if (u8LDR_Read <= 64 )                      {OCR2_REG = 0 ;}
	else if (u8LDR_Read >64 && u8LDR_Read<128 ) {OCR2_REG = 128  ; }
	else                                        {OCR2_REG = 255 ; }
}


/************************************************************/



