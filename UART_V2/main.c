/*
 * main.c
 *
 *  Created on: Aug 16, 2019
 *      Author: Ahmed
 */

#include "STD_TYPES.h"

#include <util/delay.h>

#include "DIO_interface.h"
#include "UART_interface.h"
#include "DIO_regs.h"

void main (void)
{


	vid_UART_vid_Initialize();

	while(1)
	{
		vid_UART_vid_SendChar('a');
		_delay_ms(2000);
		vid_UART_vid_SendChar('b');
		_delay_ms(2000);


}
}


