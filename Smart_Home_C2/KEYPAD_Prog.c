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

		const u8 arr[4][4]= {{7,8,9,0},{4,5,6,0},{1,2,3,0},{0,0,0,0}};   // keypad button's array
		u8 NB =0 	;  //  returned pressed button number
		u8 i =0 ; // row iterator
		u8 j =0 ; // coloumn iterator


	//  output row loop
		for(i = 0 ;i <4 ;i ++){

			DIO_SetPinValue(KPD_PORT , i , LOW);  // shift 0 to row i and search for pressed coloum

	// input coloums loop
			for(j =4 ;j <8 ;j ++){     // search for

				if(!(DIO_GetPinValue(KPD_PORT, j ))){

					NB=arr[i][j - 4 ] ;

					 while (!(DIO_GetPinValue(KPD_PORT, j))) ;
					 _delay_ms(20);         // for bouncing
				}
				else {

				}

			}
			DIO_SetPinValue(KPD_PORT , i , HIGH); 	// toggele 0 to 1 in next loop

		}

		return NB ;
	}

