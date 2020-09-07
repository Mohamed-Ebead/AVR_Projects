/*
 * STP_Prog.c
 *
 *  Created on: Apr 19, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_Types.h"
#include <util/delay.h>
#include "DIO_int.h"
#include "STP_int.h"
#include "STP_config.h"




void vid_Stepper_Init(void)
{

	DIO_SetPinDirection(STP_PORT,STP_COIL1,OUTPUT) ;
	DIO_SetPinDirection(STP_PORT,STP_COIL2,OUTPUT) ;
	DIO_SetPinDirection(STP_PORT,STP_COIL3,OUTPUT) ;
	DIO_SetPinDirection(STP_PORT,STP_COIL4,OUTPUT) ;

	DIO_SetPinValue(STP_PORT,STP_COIL1,HIGH) ;
	DIO_SetPinValue(STP_PORT,STP_COIL2,LOW) ;
	DIO_SetPinValue(STP_PORT,STP_COIL3,LOW) ;
	DIO_SetPinValue(STP_PORT,STP_COIL4,LOW) ;

}

/**--------------------------------------------------------**/


void vid_Stepper(void) {











			DIO_SetPinValue(STP_PORT,STP_COIL1,LOW) ;
			DIO_SetPinValue(STP_PORT,STP_COIL2,HIGH) ;



		_delay_ms(10);

			DIO_SetPinValue(STP_PORT,STP_COIL2,LOW) ;
			DIO_SetPinValue(STP_PORT,STP_COIL3,HIGH) ;



			_delay_ms(10);

				DIO_SetPinValue(STP_PORT,STP_COIL3,LOW) ;
				DIO_SetPinValue(STP_PORT,STP_COIL4,HIGH) ;


				_delay_ms(10);








}



void vid_Stepper_Set(void)
{
	DIO_SetPinValue(STP_PORT,STP_COIL1,LOW) ;
	DIO_SetPinValue(STP_PORT,STP_COIL2,HIGH) ;
}

/**--------------------------------------------------------**/

void vid_Stepper_Reset(void)
{
	DIO_SetPinValue(STP_PORT,STP_COIL1,HIGH) ;
	DIO_SetPinValue(STP_PORT,STP_COIL2,LOW) ;
}
/**--------------------------------------------------------**/





