/*
 * App.c
 *
 *  Created on: 20 January 2020
 *      Author: Mohamed Ebead
 */


#include "STD_TYPES.h"

#include "DIO_int.h"
#include <util/delay.h>

u8 String_TEMP [4] = ("TMP") ;
u8 String_LUMEN [4] = ("LUM") ;
u8 String_DOOR [2] = ("D") ;



u8  u8Temp = 0 ;
u16 u16Lumen = 0 ;              // each Lamp lumen = 1020 lumen
u8  u8DoorStatus = 0 ;




void main (void) {


	vid_DIO_vid_SetDioDirections() ;
	LCD_vidInitialize() ;



	vid_WelcomeMsg();











	while(1){

		vid_WelcomeMsg();


/*
		u8 u8_KPD_NB = 0 ;

			u8_KPD_NB = KPD_u8GetPressedKey();

			if(u8_KPD_NB == 1 ){
				DIO_SetPortValue(PORTD_DIO,0XFF) ;
				_delay_ms(1000) ;
			}
			else{
				DIO_SetPortValue(PORTD_DIO,0X00) ;


			}
*/



	}
}

