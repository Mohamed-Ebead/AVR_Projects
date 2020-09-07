/*
 * app.c
 *
 *  Created on: Feb 16, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"

void main (void) {

	u8 u8_Direction = 0 ;

	vid_DIO_vid_SetDioDirections() ;
	vid_Timer0_vid_InitializePWM();
	vid_Timer2_vid_InitializePWM() ;
	//vid_ExtInt0_vid_InitializeExtInt();
	//vid_ExtInt1_vid_InitializeExtInt () ;
	//vid_ExtInt2_vid_InitializeExtInt() ;

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




//		switch (u8_Direction)
//		{
//
//		case 'F' :
//
//			vid_DIO_vid_RobotForward () ;
//			return ;
///*--------------------------------------------------------*/
//		case 'B' :
//			vid_DIO_vid_RobotBackward () ;
//
//			return ;
///*--------------------------------------------------------*/
//		case 'L' :
//			vid_DIO_vid_RobotLeft () ;
//
//			return ;
///*--------------------------------------------------------*/
//		case 'R' :
//			vid_DIO_vid_RobotRight  () ;
//
//			return ;
///*--------------------------------------------------------*/
//		case 'G' :
//			vid_DIO_vid_RobotForwardLeft () ;
//
//			return ;
///*--------------------------------------------------------*/
//		case 'I' :
//			vid_DIO_vid_RobotForwardRight () ;
//
//			return ;
///*--------------------------------------------------------*/
//		case 'H' :
//			vid_DIO_vid_RobotBackwardLeft () ;
//
//			return ;
///*--------------------------------------------------------*/
//		case 'J' :
//			vid_DIO_vid_RobotBackwardRight () ;
//
//			return ;
///*--------------------------------------------------------*/
//		case 'S' :
//			vid_DIO_vid_RobotStop () ;
//
//				return ;
///*--------------------------------------------------------*/
//		default :
//			vid_DIO_vid_RobotStop () ;
//
//			return ;
///*--------------------------------------------------------*/


		//}


	//}

//	vid_DIO_vid_RobotStop () ;



	}

}
