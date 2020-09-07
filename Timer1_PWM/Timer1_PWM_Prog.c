/*
 * Timer1_PWM_Prog.c
 *
 *     Created on: Feb 5, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "registers.h"
#include"BIT_MATH.h"
#include "Timer1_interface.h"


/*
void vid_Timer1_vid_InitializePWM (void)  {

	TCCR1A_REG = 0b10100001 ;
	TCCR1A_REG = 0b00000011 ;

	TIMSK_REG = 0b00011000 ;
	SET_BIT (SREG_REG , 7) ;
}


void Timer1_adjustPWM (void) {

	OCR1AH_REG  = 0xff     ;
	OCR1AL_REG  = 0xff    ;
	OCR1BH_REG  = 0xff    ;
	OCR1BL_REG  = 0xff    ;

} */





void Timer0_Initialize (void) {




	TCCR0_REG=0b01100011 ;

	OCR0_REG = 128 ;

}




