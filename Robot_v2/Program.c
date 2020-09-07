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

#include "LCD_int.h"
#include "DIO_int.h"



/************************************************************/


void vid_DIO_vid_SetDioDirections (void)
 {
	DIO_SetPortDirection (L298PORT , 0XFF) ;
	DIO_SetPortValue(L298PORT , 0X00) ;



	// IR SENSORS : INPUT PULLED UP
	DIO_SetPinDirection (PORTD_DIO,IR_F,INPUT);            // TO INT0
	DIO_SetPinValue(PORTD_DIO,IR_F,HIGH);

	DIO_SetPinDirection (PORTD_DIO,IR_R,INPUT);            // TO INT1
	DIO_SetPinValue(PORTD_DIO,IR_R,HIGH);

	DIO_SetPinDirection (PORTB_DIO,IR_L,INPUT);            // TO INT2
	DIO_SetPinValue(PORTB_DIO,IR_L,HIGH);

	DIO_SetPinDirection (PORTB_DIO,IR_B,INPUT);
	DIO_SetPinValue(PORTB_DIO,IR_B,HIGH);



	DIO_SetPinDirection(PORTD_DIO,EN_A,OUTPUT) ;    // PWM ENABLE A TO L298
	DIO_SetPinDirection(PORTB_DIO,EN_B,OUTPUT) ;    // PWM ENABLE B TO L298


}

/************************************************************/

void vid_DIO_vid_RobotForward (void)
{
	LCD_vidClear() ;
	u8 String_Forward[11] = ("Forward...")  ;

	DIO_SetPinValue(L298PORT,IN1,HIGH);
	DIO_SetPinValue(L298PORT,IN2,LOW);
	DIO_SetPinValue(L298PORT,IN3,HIGH);
    DIO_SetPinValue(L298PORT,IN4,LOW);

	OCR0_REG = 50 ;
	OCR2_REG = 50 ;

	LCD_vidWriteString(String_Forward , 10) ;

}


/************************************************************/

void vid_DIO_vid_RobotBackward (void)
{
	LCD_vidClear() ;
	u8 String_Backward[12] = ("Backward...")  ;

	DIO_SetPinValue(L298PORT,IN1,LOW);
	DIO_SetPinValue(L298PORT,IN2,HIGH);
	DIO_SetPinValue(L298PORT,IN3,LOW);
	DIO_SetPinValue(L298PORT,IN4,HIGH);

	OCR0_REG = 50 ;
	OCR2_REG = 50 ;

	LCD_vidWriteString(String_Backward , 11) ;


}

/************************************************************/

void vid_DIO_vid_RobotLeft (void)
{
	LCD_vidClear() ;
	u8 String_Left[8] = ("Left...")  ;

	DIO_SetPinValue(L298PORT,IN1,HIGH);
	DIO_SetPinValue(L298PORT,IN2,LOW);
	DIO_SetPinValue(L298PORT,IN3,HIGH);
	DIO_SetPinValue(L298PORT,IN4,LOW);

	OCR0_REG = 60 ;
	OCR2_REG = 30 ;

	LCD_vidWriteString(String_Left , 7) ;


}

/************************************************************/

void vid_DIO_vid_RobotRight (void)
{
	LCD_vidClear() ;
	u8 String_Right[9] = ("Right...")  ;

	DIO_SetPinValue(L298PORT,IN1,HIGH);
	DIO_SetPinValue(L298PORT,IN2,LOW);
	DIO_SetPinValue(L298PORT,IN3,HIGH);
	DIO_SetPinValue(L298PORT,IN4,LOW);

	OCR0_REG = 30 ;
	OCR2_REG = 60 ;

	LCD_vidWriteString(String_Right , 7) ;

}

/************************************************************/


void vid_DIO_vid_RobotStop (void)
{

	LCD_vidClear() ;
	u8 String_Stop[8] = ("Stop...")  ;

	DIO_SetPinValue(L298PORT,IN1,LOW);
	DIO_SetPinValue(L298PORT,IN2,LOW);
	DIO_SetPinValue(L298PORT,IN3,LOW);
    DIO_SetPinValue(L298PORT,IN4,LOW);

	LCD_vidWriteString(String_Stop , 7) ;

}

/************************************************************/
