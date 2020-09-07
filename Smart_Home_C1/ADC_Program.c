/*
 * ADC_Program.c
 *
 *  Created on: Feb 5, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "Configuration.h"
#include "interface.h"
#include "registers.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "ADC_Interface.h"



/************************************************************/


void vid_ADC_vid_Initialize (void) {

	ADMUX_REG =  0b01100000 ;
	ADCSRA_REG = 0b10000111 ;    // disable interrupt

}

/************************************************************/

u8 U8_ADC_U8_Read (u8 channel) {

		channel &= 0x07;       // channel from 0 : 7  ,& to neglect any bit more than 7
		ADMUX_REG &= 0xE0;    // to save higher 3 bits as they are and set the rest to 0
		ADMUX_REG |= channel;           // Take the target channel

		SET_BIT(ADCSRA_REG,ADSC)  ;     // start conversion

		while(!(ADCSRA_REG & (1<<4)));  //POLLING TO WAIT CONVERSION

		return ADCH_REG;

}

/************************************************************/

