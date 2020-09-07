/*
 * KEYPAD_Prog.c
 *
 *  Created on: Aug 30, 2019
 *      Author: Mohamed_Ebead
 */


#include "STD_Types.h"
#include <util/delay.h>


#include "DIO_int.h"
#include "KEYPAD_int.h"


#define KPD_PORT  PORTC_DIO






u8 KPD_u8GetPressedKey(void){

		const u8 arr[4][4]= {{7,8,9,0},{4,5,6,0},{1,2,3,0},{0,0,0,0}};
		u8 NB =0 	;  //  returned pressed button number
		u8 iteration1 , iteration2 ;


	//  input Rows loop
		for(iteration1 = 0 ;iteration1 <4 ;iteration1 ++){

			DIO_SetPinValue(KPD_PORT , iteration1 , LOW);

	// Output coulomns loop
			for(iteration2 =4 ;iteration2 <8 ;iteration2 ++){

				if(!(DIO_GetPinValue(KPD_PORT, iteration2 ))){

					NB=arr[iteration1][iteration2 - 4 ] ;

					 while (!(DIO_GetPinValue(KPD_PORT, iteration2))) ;
					 _delay_ms(20);
				}
				else {

				}

			}

			// toggele 0 to 1 in next loop
			DIO_SetPinValue(KPD_PORT , iteration1 , HIGH);

		}

		return NB ;
	}

