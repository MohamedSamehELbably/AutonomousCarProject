/*
 * Ultrasonic.c
 *
 * Created: 4/5/2023 8:10:20 AM
 *  Author: MS_el
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "STDMACROS.h"

#include "ultrasonic.h"
#include "Timer0.h"
volatile long timerovf=0;

ISR(TIMER0_OVF_vect)
{
	timerovf++;
	
}

void ultrasonic_init()   // initializes timer 0 normal mode and ultrasonic trigger and echo pins
{
	Timer0_INIT_Normal();
	setbit(DDRD,trig);
	clearbit(DDRB,echo);
}

void ultrasonic_distance(int *distance) //reads the distance from the ultrasonic sensor
{
	
	_delay_us(2);
	setbit(PORTD,trig); // send a 10us pulse to the trig pin of the ultrasonic sensor and the clear the pin
	_delay_us(10);
	clearbit(PORTD,trig);
	while(readbit(PINB,echo)==0)  //wait for echo pin to become high
	{
		;
	}
	while(readbit(PINB,echo)==1) //start the timer when echo pin is high
	{
		setbit(TCCR0,CS00);
		
	}
	clearbit(TCCR0,CS00); //stop the timer when echo pin is low
	
	*distance=(0.0625*TCNT0+0.0625*255*timerovf)/58; //calculate the distance using the time took the sound waves to be emitted and received by the sensor using timer0 overflow, the remaining value in TCNT0,and the speed of sound
	_delay_ms(60); 
	TCNT0=0;      // reset timer0 parameters
	timerovf=0;
	
}