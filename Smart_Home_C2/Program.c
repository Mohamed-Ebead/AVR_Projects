/*
 * Program.c
 *
 *   Created on: 20 January 2020
 *      Author: Mohamed Ebead
 */


#include "STD_TYPES.h"
#include <util/delay.h>
#include "Configuration.h"
#include "interface.h"
#include "registers.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"

#include "UART_interface.h"



/************************************************************/

void vid_DIO_vid_SetDioDirections (void) {

	DIO_SetPortDirection(KPD_PORT,0X0F) ;   // keypad: input :coloumns , out : rows
	DIO_SetPortValue(KPD_PORT,0XFF) ;     // connect coloums to pull up res

	DIO_SetPortDirection(LCD_PORT,0XFF) ;     // lcd data pins
	DIO_SetPortDirection(LCD_CTRL,0XF0) ;          // lcd control pins

	DIO_SetPinDirection(PORTD_DIO , PIN7 , OUTPUT ) ;   // alarm led for gas
	DIO_SetPinValue(PORTD_DIO , PIN7 , LOW ) ;

}

/************************************************************/

void vid_WelcomeMsg(void){


	u8 String_WLCM [11] = ("Welcome...") ;

	Gotoxy(1,1) ;
	LCD_vidWriteString(String_WLCM,10) ;
	_delay_ms(1000) ;

	LCD_vidClear();


}

/************************************************************/



u16 Check_ID (void){

	u8 u8_KPD_NB = 0 ;
	u8 ID[4] = {0,0,0,0} ;
	u16 u16_ID =0 ;
	u8 i = 0 ;
	u8 String_ID [9] = ("Enter ID") ;

	Gotoxy(1,1) ;
	LCD_vidWriteString(String_ID,8) ;

	Gotoxy(1,2) ;


		while (i<4) {         // id : 4 digits

			u8_KPD_NB = KPD_u8GetPressedKey();

			if(u8_KPD_NB!=0) {      // only use numbers from 1 to 9, otherwise: neglected

				ID[i] = u8_KPD_NB ;          // assign pressed key to id array
				LCDWriteInteger(u8_KPD_NB,1);    // display pressed key

				i++ ;

				}
			}

// convert single pressed keys to 4-digit number
		u16_ID =( 1000 * ID[0] ) + ( 100 * ID[1]) + ( 10 * ID[2]) +( ID[3])  ;
		LCDWriteInteger(u16_ID,4);  //display 4-digit id

		_delay_ms(500) ;



return u16_ID ;


}

/*************************************************************/

u16 Check_Password (void) {

	u8 u8_KPD_NB = 0 ;

	u8 PASS[4] = {0,0,0,0} ;
	u16 u16_PASS =0 ;

		u8 j = 0 ;
		u8 String_Pass [15] = ("Enter Password") ;

		LCD_vidClear();
		Gotoxy(1,1) ;
		LCD_vidWriteString(String_Pass,15) ;

		Gotoxy(1,2) ;

		while (j<4) {           // password : 4-digits

			u8_KPD_NB = KPD_u8GetPressedKey();

			if(u8_KPD_NB!=0) {        // only use numbers from 1 to 9, otherwise: neglected

				PASS[j] = u8_KPD_NB ;     // assign pressed key to password array
				LCDWriteInteger(u8_KPD_NB,1);    // display pressed key

				j++ ;
			}
		}

		// convert single pressed keys to 4-digit number
		u16_PASS =( 1000*PASS[0] ) + ( 100*PASS[1]) + ( 10*PASS[2]) +( PASS[3])  ;
		LCDWriteInteger(u16_PASS,4) ;     //display 4-digit password

		_delay_ms(500)  ;

return u16_PASS ;
}



/*************************************************************/


void vid_LCD_vid_DisplayData(void) {

	u8  u8Temp = 0 ;
	u16 u16Lumen = 0 ;              // each Lamp lumen = 1020 lumen
	u8  u8PeopleInside = 0 ;
	u8 u8_AlertStatus = 0 ;

	u8 String_TEMP [4] = ("TMP") ;
	u8 String_LUMEN [4] = ("LUM") ;
	u8 String_NBOfPeople [3] = ("NB") ;
	u8 String_Alert [3] = ("AL") ;

	LCD_vidClear();


	while (1)

	{

	asm ("CLI") ;


		if(u8_UART_u8_GetChar() == 'a'){
			  u8Temp = u8_UART_u8_GetChar() ;

			  Gotoxy(1,1) ;
			  LCD_vidWriteString(String_TEMP,3) ;
			  LCDWriteInteger(u8Temp,2) ;

		}
		else {

		}
/*---------------------------------------------------------------------------------*/
			if (u8_UART_u8_GetChar() == 'b') {
			  u16Lumen = 4*(u16)u8_UART_u8_GetChar() ;  // max lamp lumen  = 1020  (4*255)

			  Gotoxy(1,2) ;
			  LCD_vidWriteString(String_LUMEN,4) ;
			  LCDWriteInteger(u16Lumen,4) ;

		}
		else {

		}
/*---------------------------------------------------------------------------------*/

			if (u8_UART_u8_GetChar() == 'c') {
			  u8PeopleInside = u8_UART_u8_GetChar() ;

			  Gotoxy(10,1) ;
			  LCD_vidWriteString(String_NBOfPeople,2) ;
			  LCDWriteInteger(u8PeopleInside,2) ;
				}
		 else {

		 }
/*---------------------------------------------------------------------------------*/

	    	if (u8_UART_u8_GetChar() == 'd') {

	    		u8_AlertStatus = u8_UART_u8_GetChar() ;

	    		Gotoxy(11,2) ;
	    		LCD_vidWriteString(String_Alert,2) ;

	        if (u8_AlertStatus == 1){
	        	LCD_vidWriteCharacter('1') ;
	        	DIO_SetPinValue(PORTD_DIO , PIN7 , HIGH ) ;
	        }
	        else {
	        	LCD_vidWriteCharacter('0') ;
	    		DIO_SetPinValue(PORTD_DIO , PIN7 , LOW ) ;
	  		}


	    	}
	    	else {
	    	}
/*---------------------------------------------------------------------------------*/





	  asm ("SEI") ;


	}

}


/********************************************************************/

void vid_ErrorLogInMsg(void){


	u8 String_Error [16] = ("Error Log In") ;



	LCD_vidClear();
	Gotoxy(1,1) ;
	LCD_vidWriteString(String_Error,13) ;

}


/********************************************************************/






