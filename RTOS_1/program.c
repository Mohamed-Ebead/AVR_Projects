/*
 * program.c
 *
 *  Created on: Apr 13, 2020
 *      Author: Mohamed  Ebead
 */



#include "STD_TYPES.h"
#include "DIO_int.h"
#include "config.h"

/***--------------------------------------------------------------***/

void vid_SystemInit (void)
{
	DIO_SetPinDirection (PORTA_DIO, RED_LED, OUTPUT);
	DIO_SetPinDirection (PORTA_DIO, GREEN_LED, OUTPUT);
}

/***--------------------------------------------------------------***/

void RedLed_ON (void)
{
	DIO_SetPinValue (PORTA_DIO, RED_LED, HIGH);
}

/***--------------------------------------------------------------***/

void RedLed_OFF (void)
{
	DIO_SetPinValue (PORTA_DIO, RED_LED, LOW);
}

/***--------------------------------------------------------------***/


/***--------------------------------------------------------------***/

void GreenLed_ON (void)
{
	DIO_SetPinValue (PORTA_DIO, GREEN_LED, HIGH);
}

/***--------------------------------------------------------------***/

void GreenLed_OFF (void)
{
	DIO_SetPinValue (PORTA_DIO, GREEN_LED, LOW);
}

/***--------------------------------------------------------------***/












