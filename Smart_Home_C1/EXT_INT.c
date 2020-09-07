/*
 * EXT_INT0.c
 *
 *  Created on: Feb 8, 2020
 *      Author: Mohamed  Ebead
 */



#include "avr/interrupt.h"
#include "util/delay.h"
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "registers.h"
#include "Configuration.h"
#include "BIT_MATH.h"
#include "EXT_INT_INTERFACE.H"


void vid_ExtInt0_vid_InitializeExtInt (void) {

	SET_BIT(MCUCR_REG,0) ;
	CLR_BIT(MCUCR_REG,1) ;

	 SET_BIT(GICR_REG,6) ;

   // SET_BIT (SREG_REG,7) ;

	 asm ("SEI") ;   //ENABLE GLOBAL INTERRUPT

}


void vid_ExtInt1_vid_InitializeExtInt (void) {

	SET_BIT(MCUCR_REG,2) ;
	CLR_BIT(MCUCR_REG,3) ;

	 SET_BIT(GICR_REG,7) ;


	 asm ("SEI") ;   //ENABLE GLOBAL INTERRUPT

}

