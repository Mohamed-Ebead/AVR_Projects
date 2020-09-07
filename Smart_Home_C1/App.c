/*
 * App.c
 *
 *  Created on: 20 January 2020
 *      Author: Mohamed Ebead
 */



#include "STD_Types.h"
#include <util/delay.h>

/****************************************************************/



u16 u16Temp = 0 ;
u8 u8Lumen = 0 ;   // each Lamp lumen = 255 lumen


u8 u8PeopleEnter = 0;
u8 u8PeopleExit = 0;
u8 u8PeopleInside = 0 ;




/****************************************************************/




void main (void) {



	vid_DIO_vid_SetDioDirections () ;

	vid_ADC_vid_Initialize () ;

	vid_Timer0_vid_InitializePWM () ;

	vid_Timer2_vid_InitializePWM () ;

	vid_ExtInt0_vid_InitializeExtInt () ;

	vid_ExtInt1_vid_InitializeExtInt () ;

	vid_UART_vid_Initialize();



	while (1) {



    UpdateFanSpeed () ;
    UpdateLightIlluminance () ;


	u8PeopleInside = u8PeopleEnter - u8PeopleExit ;


    asm ("CLI") ;


    vid_UART_vid_SendChar('a') ;
    _delay_ms(100) ;
    vid_UART_vid_SendChar((u8)u16Temp);
    _delay_ms(100) ;


    vid_UART_vid_SendChar('b') ;
    _delay_ms(100) ;
    vid_UART_vid_SendChar(u8Lumen);
    _delay_ms(100) ;


   vid_UART_vid_SendChar('c') ;
   _delay_ms(100) ;
   vid_UART_vid_SendChar(u8PeopleInside);
   _delay_ms(100) ;




    asm ("SEI") ;


	}


}






