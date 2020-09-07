/*
 * EXT_INT_ISR.c
 *
 *  Created on: Apr 19, 2020
 *      Author: Mohamed  Ebead
 */


#include <avr/interrupt.h>
#include <util/delay.h>
#include "STD_Types.h"
#include "STP_int.h"

#include "DIO_int.h"
#include "Configuration.h"


extern u8 u8PeopleInside ;



/**************************************************************************/


ISR(INT0_vect) {      // entering




	for(int i = 0 ; i<100 ; i++)
	{
	vid_Stepper_Set() ;
	_delay_ms (5) ;
	vid_Stepper_Reset() ;
	_delay_ms (5) ;

	}

	u8PeopleInside ++ ;

}

/**************************************************************************/

ISR(INT1_vect) {       // exit



	for(int i = 0 ; i<100 ; i++)
		{
		vid_Stepper_Set() ;
		_delay_ms (5) ;
		vid_Stepper_Reset() ;
		_delay_ms (5) ;

		}



	if (u8PeopleInside!=0) {
	u8PeopleInside -- ;
	}

	else {
		u8PeopleInside = 0 ;
	}

}




/************************************************************/

