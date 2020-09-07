/*
 * app.c
 *
 *  Created on: Feb 16, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "interface.h"
#include "Timer0_interface.h"
#include "Timer2_interface.h"
#include "UART_interface.h"


void main (void) {

	u8 u8_Direction = 0 ;

	vid_DIO_vid_SetDioDirections() ;
	vid_Timer0_vid_InitializePWM();
	vid_Timer2_vid_InitializePWM() ;


	vid_UART_vid_Initialize() ;


	vid_DIO_vid_RobotStop () ;


	while (1)
	{

		u8_Direction = u8_UART_u8_GetChar () ;

		if (u8_Direction=='F') {
				vid_DIO_vid_RobotForward () ;

		}
		else if (u8_Direction=='B')
		{
			vid_DIO_vid_RobotBackward () ;
		}
		else if (u8_Direction=='R')
		{
			vid_DIO_vid_RobotRight  () ;
		}
		else if (u8_Direction=='L')
			{
				vid_DIO_vid_RobotLeft  () ;
			}
		else if (u8_Direction=='G')
		{
			vid_DIO_vid_RobotForwardLeft () ;
		}
		else if (u8_Direction=='I')
		{
			vid_DIO_vid_RobotForwardRight () ;
		}
		else if (u8_Direction=='H')
			{
			vid_DIO_vid_RobotBackwardLeft () ;
			}
		else if (u8_Direction=='J')
			{
			vid_DIO_vid_RobotBackwardRight () ;
			}
		else if (u8_Direction=='S')
			{
			vid_DIO_vid_RobotStop () ;
			}


		else {
			vid_DIO_vid_RobotStop () ;
		}


	}

}
