/*
 * Timer1_interface.h
 *
 *  Created on: Feb 5, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

/**********************************************************/

void vid_Timer1_vid_InitializePWM (void) ;
/* Timer_1 Initialization :
 * mode 1 : PWM, Phase Correct, 8-bit
 * Clear OC1A/OC1B on compare match when up-counting.
 * Set OC1A/OC1B on compare match when downcounting
 * i/p clk / 64   from prescaler
 *
 */

/**********************************************************/



void Timer1_adjustPWM (void) ;

void Timer0_Initialize (void) ;

#endif /* TIMER1_INTERFACE_H_ */
