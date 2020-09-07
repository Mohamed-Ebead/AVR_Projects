/*
 * App.c
 *
 *  Created on: Apr 19, 2020
 *      Author: Mohamed  Ebead
 */


#include <util/delay.h>
#include "STD_Types.h"
#include "ADC_Interface.h"
#include "interface.h"
#include "EXT_INT_INTERFACE.H"
#include "Timer0_interface.h"
#include "STP_int.h"
#include "LCD_int.h"


/****************************************************************/


u8 u8AdcChannel = 0 ;
u8 u8_TMP_Read = 0 ;
u8 u8_LDR_Read = 0 ;
u8 *Str_LampStatus = "OFF";
u8 *Str_FanStatus  = "OFF";

u16 u16Temp = 0 ;
u8 u8Lumen = 0 ;          // each Lamp lumen = 255 lumen


u8 u8PeopleInside = 0 ;



/****************************************************************/




int main (void) {


	vid_DIO_vid_SetDioDirections () ;

	vid_ADC_vid_Initialize () ;

	vid_Timer0_vid_InitializePWM () ;

	vid_ExtInt0_vid_InitializeExtInt () ;
	vid_ExtInt1_vid_InitializeExtInt () ;

	vid_Stepper_Init ();
	LCD_vidInitialize() ;

	vid_WelcomeMsg();





	while (1) {





while (u8PeopleInside != 0 )
{
    UpdateFanSpeed () ;
    UpdateLightIlluminance () ;
    vid_LCD_vid_DisplayData() ;
}
DIO_SystemSleep () ;

	}

return 0 ;
}






