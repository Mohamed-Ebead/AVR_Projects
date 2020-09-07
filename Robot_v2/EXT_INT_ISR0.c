/*
 * EXT_INT_ISR.c
 *
 *  Created on: Feb 11, 2020
 *      Author: Mohamed  Ebead
 */


#include <avr/interrupt.h>
#include <util/delay.h>
#include "STD_Types.h"

#include "DIO_int.h"
#include "Configuration.h"
#include "interface.h"



/**************************************************************************/


ISR(INT0_vect)
{

	vid_DIO_vid_RobotStop () ;
	_delay_ms(1000) ;

	vid_DIO_vid_RobotBackward ();
	_delay_ms(1000) ;


	if(!(DIO_GetPinValue(PORTD_DIO,IR_R)))
	{
		vid_DIO_vid_RobotRight () ;
	}
	else if (!(DIO_GetPinValue(PORTB_DIO,IR_L)))
	{
		vid_DIO_vid_RobotLeft() ;
	}

	else
	{
		vid_DIO_vid_RobotStop () ;
	} ;

	/*

if(!(DIO_GetPinValue(IR_PORT,IR_R)))
{
	vid_DIO_vid_RobotRight () ;
}
else if (!(DIO_GetPinValue(IR_PORT,IR_L)))
{
	vid_DIO_vid_RobotLeft() ;
}

else if (!(DIO_GetPinValue(IR_PORT,IR_B)))
{
	vid_DIO_vid_RobotBackward() ;
}

else
{
	vid_DIO_vid_RobotStop () ;
}

*/

}

/**************************************************************************/

