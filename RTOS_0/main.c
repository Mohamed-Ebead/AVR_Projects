/*
 * main.c
 *
 *  Created on: Apr 13, 2020
 *      Author: Mohamed  Ebead
 */

#include <util/delay.h>
#include "interface.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"


xTaskHandle xTask1_Handle = NULL ;
xTaskHandle xTask2_Handle = NULL ;



int main (void)
{
	vid_SystemInit() ;



	xTaskCreate( vTask1_Function,"RedLed_ON_",configMINIMAL_STACK_SIZE,NULL, 1,&xTask1_Handle );
	xTaskCreate( vTask2_Function,"RedLed_OFF_",configMINIMAL_STACK_SIZE,NULL, 1,&xTask2_Handle );

	vTaskStartScheduler() ;



while(1) ;


return 0 ;

}


void vTask1_Function ( void *param )
{
	while(1)
	{
		RedLed_ON    ();
		vTaskDelay(1000);
		_delay_ms(1000) ;
	}
	vTaskDelete(NULL) ;
}



void vTask2_Function ( void *param )
{
	while(1)
	{
		GreenLed_ON   ();
		vTaskDelay(1000);
		_delay_ms(1000) ;
	}
	vTaskDelete(NULL) ;
}





