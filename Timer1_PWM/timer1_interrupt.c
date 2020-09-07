/*
 * timer1_interrupt.c
 *
 *  Created on: Feb 7, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_Types.h"
#include <AVR/interrupt.h>
#include"BIT_MATH.h"
#include "registers.h"
/*
ISR(TIMER1_COMPA_vect){

	TOG_BIT(PORTD_REG,4) ;

}


ISR(TIMER1_COMPB_vect) {

	TOG_BIT(PORTD_REG,5) ;

}
*/


ISR(TIMER1_OVF_vect){
	TOG_BIT(PORTD_REG,6) ;

}
