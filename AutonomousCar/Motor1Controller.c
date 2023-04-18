/*
 * Motor1Controller.c
 *
 * Created: 4/13/2023 4:02:16 AM
 *  Author: MS_el
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "Motor1Controller.h"
#include "STDMACROS.h"
#include "Timer1.h"


void Motor1Controller_init() // initialize the rear motor and steer motor pins and the fast PWM 
{
	Timer1_init_Fastpwm();
	setbit(DDRC,rearMotorIn1);
	setbit(DDRC,rearMotorIn2);
	setbit(DDRC,steerMotorIn1);
	setbit(DDRC,steerMotorIn2);
}

void Motor1ControllerRearmotors_move() //moves the rear motors with a duty cycle of 60%(moves the car)
{
	setbit(PORTC,rearMotorIn1);
	clearbit(PORTC,rearMotorIn2);
	Timer1_set_DC_A(0.6);
	
}

void Motor1ControllerRearmotors_stop() //stops the rear motor(stops the car)
{
	clearbit(PORTC,rearMotorIn1);
	clearbit(PORTC,rearMotorIn2);
}


void Motor1ControllerSteerMotor_TurnLeft() //makes the car steer to the left
{
	LCD_send_command_4bit(0x01);
	setbit(PORTC,steerMotorIn1);
	clearbit(PORTC,steerMotorIn2);
	Timer1_set_DC_B(1);
	LCD_sendString_4bit(" Moving Left");
}
void Motor1ControllerSteerMotor_TurnRight() // makes the car steer to the right
{
	LCD_send_command_4bit(0x01);
	clearbit(PORTC,steerMotorIn1);
	setbit(PORTC,steerMotorIn2);
	Timer1_set_DC_B(1);
	LCD_sendString_4bit(" Moving Right");
}
void Motor1ControllerSteerMotor_moveForward() // makes the car move forward
{
	LCD_send_command_4bit(0x01);
	clearbit(PORTC,steerMotorIn1);
	clearbit(PORTC,steerMotorIn2);
	LCD_sendString_4bit(" moving forward");
	
}



