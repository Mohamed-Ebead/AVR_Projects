/*
 * main.c
 *
 *  Created on: Feb 10, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "DIO_int.h"
#include <util/delay.h>
#include "ADC_Interface.h"
#include "LCD_int.h"


void main (void) {

	u8 u8_ADC_Read = 0 ;
	u16 volt = 0 ;
	u16 temp = 0 ;
	u8 string1[10] ="Analog = ";
	u8 string2[7] ="TMP = ";

	DIO_SetPinDirection (PORTA_DIO, PIN0, INPUT);
	//DIO_SetPinValue(PORTA_DIO , PIN0, HIGH);
	DIO_SetPortDirection (PORTC_DIO,0xff);
	DIO_SetPortDirection (PORTD_DIO,0xff);

	LCD_vidInitialize();
	vid_ADC_vid_Initialize () ;


	while(1) {

		u8_ADC_Read = U8_ADC_U8_Read(0) ;


		volt =  (( ( (u32)u8_ADC_Read *  1500UL) ) / 256UL )  ;
		temp = volt/10 ;

		Gotoxy(1,1) ;
		LCD_vidWriteString(string1,10) ;
		Gotoxy(9,1) ;
		LCDWriteInteger(u8_ADC_Read,4) ;

		Gotoxy(1,2) ;
		LCD_vidWriteString(string2,7) ;
		Gotoxy(6,2) ;
		LCDWriteInteger(temp,4) ;

		//_delay_ms(100) ;

		//LCD_vidClear() ;


		// temp = (((u32)u8_ADC_Read * 50UL)/1023UL);
		// temp=u8_ADC_Read/1.75 ;
		// temp = (((u32)u8_ADC_Read * 150UL)/1023UL) ;
		// volt =(  (u8_ADC_Read *  5000) ) / 1024 ;




	}


}



