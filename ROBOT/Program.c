/*
 * Program.c
 *
 *   Created on: 20 January 2020
 *      Author: Mohamed Ebead
 */


#include "STD_TYPES.h"
#include "Configuration.h"
#include "interface.h"
#include "registers.h"
#include "BIT_MATH.h"
#include "interface.h"

#include "DIO_int.h"



/************************************************************/


void vid_DIO_vid_SetDioDirections (void) {


	DIO_SetPortDirection (L298PORT , 0XFF) ;
	DIO_SetPortValue(L298PORT , 0XFF) ;



	// IR SENSORS : INPUT PULLED UP
	DIO_SetPinDirection (PORTD_DIO,IR_F,OUTPUT);
	DIO_SetPinValue(PORTD_DIO,IR_F,HIGH);

	DIO_SetPinDirection (IR_PORT,IR_R,OUTPUT);
	DIO_SetPinValue(IR_PORT,IR_R,HIGH);

	DIO_SetPinDirection (IR_PORT,IR_L,OUTPUT);
	DIO_SetPinValue(IR_PORT,IR_L,HIGH);

	DIO_SetPinDirection (IR_PORT,IR_B,OUTPUT);
	DIO_SetPinValue(IR_PORT,IR_B,HIGH);



	DIO_SetPinDirection(PORTD_DIO,EN_A,OUTPUT) ;    // PWM ENABLE A TO L298
	DIO_SetPinDirection(PORTD_DIO,EN_B,OUTPUT) ;    // PWM ENABLE B TO L298


}

/************************************************************/
void vid_DIO_vid_RobotForward (void)
{
	DIO_SetPinValue(L298PORT,IN1,HIGH);
	DIO_SetPinValue(L298PORT,IN2,LOW);
	DIO_SetPinValue(L298PORT,IN3,HIGH);
    DIO_SetPinValue(L298PORT,IN4,LOW);
}

/************************************************************/
void vid_DIO_vid_RobotBackward (void)
{
	DIO_SetPinValue(L298PORT,IN1,LOW);
	DIO_SetPinValue(L298PORT,IN2,HIGH);
	DIO_SetPinValue(L298PORT,IN3,LOW);
	DIO_SetPinValue(L298PORT,IN4,HIGH);

}
/************************************************************/
void vid_DIO_vid_RobotLeft (void)
{
	DIO_SetPinValue(L298PORT,IN1,HIGH);
	DIO_SetPinValue(L298PORT,IN2,LOW);
	DIO_SetPinValue(L298PORT,IN3,LOW);
	DIO_SetPinValue(L298PORT,IN4,LOW);
}

/************************************************************/
void vid_DIO_vid_RobotRight (void)
{
	DIO_SetPinValue(L298PORT,IN1,LOW);
	DIO_SetPinValue(L298PORT,IN2,LOW);
	DIO_SetPinValue(L298PORT,IN3,HIGH);
	DIO_SetPinValue(L298PORT,IN4,LOW);
}

/************************************************************/


void vid_DIO_vid_RobotStop (void)
{
	DIO_SetPinValue(L298PORT,IN1,LOW);
	DIO_SetPinValue(L298PORT,IN2,LOW);
	DIO_SetPinValue(L298PORT,IN3,LOW);
    DIO_SetPinValue(L298PORT,IN4,LOW);
}
