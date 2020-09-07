/*
 * app.c
 *
 *  Created on: Feb 16, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "LCD_int.h"

void main (void) {

	vid_DIO_vid_SetDioDirections() ;
	vid_Timer0_vid_InitializePWM();
	vid_Timer2_vid_InitializePWM() ;
	vid_ExtInt0_vid_InitializeExtInt();
	vid_ExtInt1_vid_InitializeExtInt () ;
	vid_ExtInt2_vid_InitializeExtInt() ;

	LCD_vidInitialize() ;

	vid_DIO_vid_RobotForward();

	while (1)
	{

	}




}
