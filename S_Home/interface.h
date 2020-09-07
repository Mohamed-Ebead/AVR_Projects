/*
 * interface.h
 *
 *  Created on: Apr 19, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_









/**********************************************************/

void vid_DIO_vid_SetDioDirections (void) ;
/* This function handles DIO pins
 * , sets input and output pins
 * and initializes PORTS initial values
 */
/**********************************************************/

void UpdateFanSpeed (void) ;

/**********************************************************/


void UpdateLightIlluminance (void) ;


/**********************************************************/
void UpdateAlertStatus (void) ;


/**********************************************************/
void DIO_SystemSleep (void) ;
/**********************************************************/
void vid_WelcomeMsg(void);

/**********************************************************/
void vid_LCD_vid_DisplayData(void) ;


/**********************************************************/




#endif /* INTERFACE_H_ */
