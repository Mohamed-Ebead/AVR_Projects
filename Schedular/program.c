/*
 * program.c
 *
 *  Created on: Apr 13, 2020
 *      Author: Mohamed  Ebead
 */



#include "Shared_Lib/STD_TYPES.h"
#include "Shared_Lib/BIT_MATH.h"

#include "DIO_int.h"
#include "DIO_reg.h"
#include "config.h"

/***--------------------------------------------------------------***/

void vid_SystemInit (void)
{
	DIO_SetPinDirection (PORTA_DIO, RED_LED, OUTPUT);
	DIO_SetPinDirection (PORTA_DIO, GREEN_LED, OUTPUT);
	DIO_SetPinDirection (PORTA_DIO, YELLOW_LED, OUTPUT);

}

/***--------------------------------------------------------------***/

void RedLed_TOG (void)
{
	TOG_BIT(PORTA_Register,RED_LED) ;
}

/***--------------------------------------------------------------***/

void GreenLed_TOG (void)
{
	TOG_BIT(PORTA_Register,GREEN_LED) ;

}

/***--------------------------------------------------------------***/

void YellowLed_TOG (void)
{
	TOG_BIT(PORTA_Register,YELLOW_LED) ;

}

/***--------------------------------------------------------------***/








