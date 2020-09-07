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


/************************************************************/

void vid_DIO_vid_SetDioDirections (void) {

	DIO_SetPortDirection(KPD_PORT,0X0F) ; // ROW:INPUT , COLOUMN :OUTPUT
	DIO_SetPortValue(KPD_PORT,0XFF) ;

	DIO_SetPortDirection(LCD_PORT,0XFF) ;
	DIO_SetPortDirection(LCD_CTRL,0XF0) ;

	DIO_SetPortDirection(PORTD_DIO,0XFF) ;
	DIO_SetPortValue(PORTD_DIO,0X00) ;

}

/************************************************************/

void vid_WelcomeMsg(void){

	u8 u8_KPD_NB = 0 ;
/*
	u8 String_WLCM [11] = ("Welcome...") ;
	u8 String_ID [9] = ("Enter ID") ;


	Gotoxy(1,1) ;
	LCD_vidWriteString(String_WLCM,10) ;
	_delay_ms(1000) ;

	LCD_vidClear();

	Gotoxy(1,1) ;
	LCD_vidWriteString(String_ID,8) ;
*/
	u8_KPD_NB = KPD_u8GetPressedKey();

	Gotoxy(1,2) ;

	LCDWriteInteger(u8_KPD_NB,1);

	//_delay_ms(100) ;





	Gotoxy(1,2) ;









}

/************************************************************/

