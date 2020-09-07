/*
 * App.c
 *
 *  Created on: 20 January 2020
 *      Author: Mohamed Ebead
 */


#include "STD_TYPES.h"
#include "interface.h"
#include "UART_interface.h"
#include "LCD_int.h"



void main (void) {


	u16	u16_ID = 0 ;
	u16 u16_PASS = 0 ;


	u8 u8NBOfTries = 0 ;        // tries until correct password


	vid_DIO_vid_SetDioDirections() ;    // set DIO configuration
	LCD_vidInitialize() ;
	vid_UART_vid_Initialize();



	vid_WelcomeMsg();


/**********************************************************************/

	u16_ID = Check_ID() ;

	switch(u16_ID) {

	case(1234) :         // correct ID
		u16_PASS = Check_Password() ;


/*------------------------------------------------------*/

	switch(u16_PASS) {

	/*------------------------------------*/

	case (5678) : // correct ID && correct password  in first try

		 vid_LCD_vid_DisplayData();     break ;
	/*------------------------------------*/

	default :   // correct ID but Wrong password
		for (u8NBOfTries=1 ; u8NBOfTries<=3 ; u8NBOfTries++ ){
		u16_PASS = Check_Password() ;

		if(u16_PASS==5678){      // correct ID && correct password in 2nd or 3rd try
		  	  vid_LCD_vid_DisplayData();     break ;
			}
		else {

			}

		if ( u8NBOfTries == 2) {
			vid_ErrorLogInMsg() ;   		break ;
			}
		}

	}

	break ;
/*------------------------------------------------------*/


	default :         // error ID
		vid_ErrorLogInMsg() ;   		break ;


	}

/**********************************************************************/















	}

/**********************************************************************/

