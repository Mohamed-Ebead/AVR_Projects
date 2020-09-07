/*
 * Timer1_prog.c
 *
 *  Created on: Jul 2, 2020
 *      Author: Mohamed  Ebead
 */
// shared libraries
#include "Shared_Lib/STD_TYPES.h"
#include "Shared_Lib/BIT_MATH.h"

// MCAL
#include "Timer1_Reg.h"


//
static void(*Global_pFn)(void) ;


void __vector_7(void)   __attribute__((signal));




void Timer1_Init (void)
{
	 // CTC mode , Enable compare match interrupt
	TCCR1A_REG = 0X00 ;
	OCR1A_REG = 1000 ;    // tick time 1 ms

	TCNT1L_REG = 0 ;

	SET_BIT(TIMSK_REG,4) ;   // enable c,p match int channel A

	SET_BIT (SREG_REG,7);   // Enable global  interrupt

	TCCR1B_REG = 0b00001010 ;  // last step start timer

}


 void Timer_SetCallBack (void (*local_pFn)(void))
{
	Global_pFn = local_pFn ;

}


 void __vector_7(void)
 {
 	Global_pFn () ;

 }

 // calling RTO layer  from MCAL layer opposes layerd arch.
 // soln : callback fn

/*
void __vector_7(void)
{
	RTO_vid_StartSchedular () ;

}
*/




