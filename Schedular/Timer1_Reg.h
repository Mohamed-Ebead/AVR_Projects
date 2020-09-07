/*
 * Registers.h
 *
 *  Created on: Jan 30, 2020
 *      Author: Mohamed Ebead
 */

#ifndef TIMER1_REG_H_
#define TIMER1_REG_H_



/*************************** Timer_1 ***************************/

#define TCCR1A_REG   (*((volatile u8*)0x4F))
#define TCCR1B_REG   (*((volatile u8*)0x4E))
#define TCNT1H_REG   (*((volatile u8*)0x4D))
#define TCNT1L_REG   (*((volatile u8*)0x4C))
#define OCR1AH_REG   (*((volatile u8*)0x4B))
#define OCR1AL_REG   (*((volatile u8*)0x4A))

#define OCR1A_REG   (*((volatile u16*)0x4A))

#define OCR1BH_REG   (*((volatile u8*)0x49))
#define OCR1BL_REG   (*((volatile u8*)0x48))
#define ICR1H_REG    (*((volatile u8*)0x47))
#define ICR1L_REG    (*((volatile u8*)0x46))


#define TIMSK_REG    (*((volatile u8*)0x59))
#define TIFR_REG     (*((volatile u8*)0x58))








#define SREG_REG      (*((volatile u8*)0x5F))












#endif /* TIMER1_REG_H_ */
