/*
 * Program.c
 *
 *  Created on: Apr 19, 2020
 *      Author: Mohamed  Ebead
 */

#include <util/delay.h>
#include "STD_TYPES.h"
#include "Configuration.h"
#include "interface.h"
#include "registers.h"
#include "BIT_MATH.h"
#include "interface.h"
#include "APP_Config.h"

#include "DIO_int.h"
#include "ADC_interface.h"
#include  "LCD_int.h"

extern u16 u16Temp ;
extern u8 u8Lumen ;
extern u8 u8_TMP_Read ;
extern u8 u8_LDR_Read ;
extern u8 *Str_LampStatus  ;
extern u8 *Str_FanStatus  ;
extern u8 u8PeopleInside ;

/************************************************************/


void vid_DIO_vid_SetDioDirections (void) {

/*********************** Analog Input *************************/
	DIO_SetPinDirection (PORTA_DIO,TEMP_SENSOR,INPUT) ;
	DIO_SetPinDirection (PORTA_DIO,LDR,INPUT) ;

/******************** Input External Interrupt **********************/
	DIO_SetPinDirection (PORTD_DIO,PIR1,INPUT) ;
	DIO_SetPinDirection (PORTD_DIO,PIR2,INPUT) ;

/*********************** Digital Input *************************/




/********************** Digital Output ************************/
	DIO_SetPinDirection (PORTB_DIO,LIGHT,OUTPUT) ;




/************************ PWM Output *************************/
	DIO_SetPinDirection (PORTB_DIO,FAN,OUTPUT) ;



/************************ PORTS INITIALIZATION *************************/

	DIO_SetPinValue(PORTD_DIO , PIR1 , HIGH);
	DIO_SetPinValue(PORTD_DIO , PIR2 , HIGH);
	DIO_SetPinValue(PORTB_DIO,LIGHT,LOW) ;
	DIO_SetPinValue(PORTB_DIO,FAN,HIGH) ;




	/************************ LCD INITIALIZATION *************************/


	DIO_SetPortDirection(LCD_PORT,0XFF) ;           // lcd data pins
	DIO_SetPortDirection(LCD_CTRL,0XF0) ;           // lcd control pins
}


/************************************************************/

void UpdateFanSpeed (void) {

	u16 u16Volt = 0 ;

	U8_ADC_U8_Read(TEMPERATURE_SENSOR)  ;
	// analog = ((digital * V ref )/2^resolution)
	u16Volt =( ( ( (u32)u8_TMP_Read *  5000UL) ) / 255UL )  ;
	u16Temp = u16Volt/10 ;



if      (u16Temp<20)
{

	OCR0_REG = 0 ;
	Str_FanStatus  = "_OFF" ;
}

else if ((u16Temp>=20)&&(u16Temp<=27))
{
	OCR0_REG = 128 ;
	Str_FanStatus  = "_ON_" ;

}
else
{
	DIO_SetPinValue(PORTB_DIO,3,LOW) ;
	OCR0_REG=255 ;
	Str_FanStatus  = "_ON_" ;
}

}

/************************************************************/

void UpdateLightIlluminance (void) {

	U8_ADC_U8_Read(LDR_SENSOR)  ;

	u8Lumen  = u8_LDR_Read ;


	if (u8_LDR_Read <= 100 )
	{
		DIO_SetPinValue(PORTB_DIO , LIGHT , ON);
		Str_LampStatus = "_ON" ;
	}
	else
	{
		DIO_SetPinValue(PORTB_DIO , LIGHT , OFF);
		Str_LampStatus = "_OFF"  ;
	}


}


/************************************************************/

void DIO_SystemSleep (void)
{


	LCD_vidClear();
	OCR0_REG = 0;
	OCR2_REG = 0 ;
	DIO_SetPinValue(PORTB_DIO,LIGHT,LOW) ;
	DIO_SetPinValue(PORTD_DIO , PIR1 , HIGH);
	DIO_SetPinValue(PORTD_DIO , PIR2 , HIGH);
	DIO_SetPinValue(PORTB_DIO,FAN,HIGH) ; //

}

/************************************************************/

void vid_WelcomeMsg(void){


	u8 String_WLCM [11] = ("Welcome...") ;

	Gotoxy(1,1) ;
	LCD_vidWriteString(String_WLCM,10) ;
	_delay_ms(1000) ;

	LCD_vidClear();


}

/*************************************************************/


void vid_LCD_vid_DisplayData(void) {


	u8 String_TEMP [4] = "TMP" ;
	u8 String_FAN [4] = "FAN" ;
	u8 String_LAMP [5] = "LAMP" ;
	u8 String_NBOfPeople [3] = "NB" ;



			//LCD_vidClear();


			  Gotoxy(1,1) ;
			  LCD_vidWriteString(String_TEMP,3) ;
			  LCDWriteInteger(u16Temp,2) ;

			  LCD_vidWriteString( " ## ",4 ) ;       // SPACE
			  LCD_vidWriteString(String_NBOfPeople,2) ;
			  LCDWriteInteger((u8PeopleInside/2),2) ;

			  Gotoxy(1,2) ;
			  LCD_vidWriteString(String_FAN,4) ;
			  LCD_vidWriteString( Str_FanStatus,3 ) ;

			  LCD_vidWriteString( "#",3 ) ;       // SPACE

			  LCD_vidWriteString(String_LAMP,4) ;
			  LCD_vidWriteString(Str_LampStatus,4) ;







	}

/********************************************************************/


/********************************************************************/




