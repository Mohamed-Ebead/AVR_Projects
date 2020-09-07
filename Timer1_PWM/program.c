/*
 * program.c
 *
 *  Created on: Feb 7, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "registers.h"
#include "interface.h"


void Initialize(void) {


	DDRB_REG = 0xff ;
	PORTB_REG = 0x00;


}

