/*
 * Motor2Controller.c
 *
 * Created: 4/13/2023 7:12:14 AM
 *  Author: MS_el
 */ 

#include <avr/io.h>
#include "STDMACROS.h"
#include "Timer2.h"
#include "Motor2Controller.h"

void Motor2Controller_init() //initializes timer2 fast PWM and servo signal pin
{
	timer2_init_fastpwm();
	setbit(DDRD,servoSignalPin);
}
void Motor2Controller_servoRight() // moves the servo with the ultrasonic sensor to face the right position
{
	timer2_setDC(0.05);   //duty cycle of 5% is for right position(0 degrees)
}
void Motor2Controller_servoFront() // moves the servo with the ultrasonic sensor to face the front position
{
	timer2_setDC(0.1);   //duty cycle of 10% is for front position(90 degrees)
}
void Motor2Controller_servoLeft() // moves the servo with the ultrasonic sensor to face the left position
{
	timer2_setDC(0.15);  //duty cycle of 15% is for left position(180 degrees)
} 