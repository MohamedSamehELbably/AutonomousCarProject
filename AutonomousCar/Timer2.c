/*
 * Timer2.c
 *
 * Created: 4/7/2023 8:34:41 PM
 *  Author: MS_el
 */ 
#include <avr/io.h>
#include "STDMACROS.h"
#include "Timer2.h"


void timer2_init_fastpwm() 
{
	setbit(TCCR2,WGM21);  // enable fast PWM mode
	setbit(TCCR2,WGM20);
	setbit(TCCR2,COM21);  // clear OCR2 on compare match
	setbit(TCCR2,CS20);   // set prescaler to 1024 for servo motor
	setbit(TCCR2,CS21);
	setbit(TCCR2,CS22);
	
}


void timer2_setDC(float DC) //set duty cycle and write it in OCR2 pin
{
	int x=(int) (DC*256);
	OCR2=x-1;
}