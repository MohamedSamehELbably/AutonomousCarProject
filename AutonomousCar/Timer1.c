/*
 * Timer1.c
 *
 * Created: 4/4/2023 7:17:04 PM
 *  Author: MS_el
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "STDMACROS.h"
#include "Timer1.h"



void Timer1_init_Fastpwm() //initialize fast PWM 
{
	setbit(TCCR1A,COM1A1); //clear OCR1A on compare match
	setbit(TCCR1A,COM1B1); //clear OCR1B on compare match
	setbit(TCCR1A,WGM10);  // set PWM resolution to 10 bits
	setbit(TCCR1A,WGM11);
	setbit(TCCR1B,WGM12);
	setbit(TCCR1B,CS12);   // prescaler of 256 
	setbit(DDRD,5);       //Set OCR1A 
	setbit(DDRD,4);       //set OCR1B  
} 

void Timer1_set_DC_A(float DC) //set duty cycle and write in reg OCR1A
{
	int x = (int)(DC*1024);
	OCR1A=x-1;
}
void Timer1_set_DC_B(float DC) //set duty cycle and write in reg OCR1B
{
	int x = (int)(DC*1024);
	OCR1B=x-1;
}