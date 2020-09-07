/*
 * interface.h
 *
 *  Created on: Apr 13, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_



void vid_SystemInit (void) ;


void vTask1_Function ( void *param ) ;
void vTask2_Function ( void *param ) ;

void RedLed_ON (void);
void RedLed_OFF (void);

void GreenLed_ON (void);
void GreenLed_OFF (void);











#endif /* INTERFACE_H_ */
