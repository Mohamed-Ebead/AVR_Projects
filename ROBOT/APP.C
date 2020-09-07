/*
 * APP.C
 *
 *  Created on: Feb 16, 2020
 *      Author: Mohamed  Ebead
 */






#include "STD_TYPES.h"
#include "Configuration.h"
#include "interface.h"
#include "registers.h"
#include "BIT_MATH.h"
#include "interface.h"

#include "DIO_int.h"
#include "EXT_INT_INTERFACE.h"
#include "Timer0_interface.h"
#include "Timer2_interface.h"


void main (void)
{

	vid_DIO_vid_SetDioDirections() ;
	vid_Timer0_vid_InitializePWM() ;
	vid_Timer2_vid_InitializePWM () ;
	vid_ExtInt0_vid_InitializeExtInt () ;


	vid_DIO_vid_RobotForward () ;



	while(1)
	{




	}


}
