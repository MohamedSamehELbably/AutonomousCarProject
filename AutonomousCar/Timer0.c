/*
 * Timer0.c
 *
 * Created: 1/6/2023 8:52:46 PM
 *  Author: AMIT
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "STDMACROS.h"
volatile extern int x;

void Timer0_INIT_Normal()
{
	setbit(TIMSK,TOIE0);// over flow interrupt enable  
	sei(); // global interrupt enable 
}
void Timer0_INIT_Comp(int valuex)
{	
	
	setbit(TCCR0,WGM01);
	setbit(TCCR0,CS00);
	setbit(TIMSK,OCIE0);
	OCR0 = valuex ;
	sei();
}
void delay_ms(float delay)
{	
	float z=0;
	x=0;
	z=5000*(delay/1000);
	while((float)x<=z)
	{
		;
	}
	
}
void Timer0_INIT_FastPWM()
{
	setbit(TCCR0,WGM01);
	setbit(TCCR0,WGM00);
	setbit(TCCR0,COM01);
	setbit(TCCR0,CS00);
	setbit(DDRB,3);
}
void Timer0_Set_DC(float DC)
{
	int x=(int) (DC*256);
	OCR0=x-1;
}
void Timer0_INIT_PhaseCorrectPWM()
{
	setbit(TCCR0,WGM00);
	setbit(TCCR0,COM01);
	setbit(TCCR0,CS00);
	setbit(DDRB,3);
}