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


ISR(INT2_vect)
{

	vid_DIO_vid_RobotRight () ;



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

