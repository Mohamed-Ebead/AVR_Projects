/*
 * interface.h
 *
 *   Created on: 20 January 2020
 *      Author: Mohamed Ebead
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
void vid_DIO_vid_RobotForward (void);

/**********************************************************/

void vid_DIO_vid_RobotBackward (void);

/**********************************************************/

void vid_DIO_vid_RobotRight (void);

void vid_DIO_vid_RobotForwardRight (void);

void vid_DIO_vid_RobotBackwardRight (void);



/**********************************************************/

void vid_DIO_vid_RobotLeft (void) ;

void vid_DIO_vid_RobotForwardLeft (void) ;

void vid_DIO_vid_RobotBackwardLeft (void);



/**********************************************************/

void vid_DIO_vid_RobotStop (void) ;


/**********************************************************/




/**********************************************************/


/**********************************************************/







#endif /* INTERFACE_H_ */
