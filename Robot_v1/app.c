/*
 * app.c
 *
 *  Created on: Feb 16, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"


void main (void) {

	vid_DIO_vid_SetDioDirections() ;
	vid_Timer0_vid_InitializePWM();
	vid_Timer2_vid_InitializePWM() ;
	vid_ExtInt0_vid_InitializeExtInt();

	vid_DIO_vid_RobotForward();

	while (1)
	{

	}




}
