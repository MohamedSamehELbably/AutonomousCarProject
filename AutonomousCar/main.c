/*
 * AutonomousCar.c
 *
 * Created: 4/14/2023 5:55:02 AM
 * Author : MS_el
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STDMACROS.h"
#include "LCD.h"
#include "Timer0.h"
#include "Timer1.h"
#include "Timer2.h"
#include "ultrasonic.h"
#include "Motor1Controller.h"
#include "Motor2Controller.h"

#define front 1
#define right 2
#define left 3
int main(void)
{
	Motor2Controller_init();
	Motor1Controller_init();
	ultrasonic_init();
	LCD_INIT_4bit();
	int distance=0;
	int servoPos=front;
	Motor1ControllerRearmotors_move();
	Motor1ControllerSteerMotor_moveForward();
	Motor2Controller_servoFront();
    while (1) 
    {
		
		ultrasonic_distance(&distance); //read initial distance
		if(servoPos==front)      //the sensor is looking in front of the car which is by default
		{
			
			if(distance>30)          // check distance if it is more then the required distance move freely otherwise
			{
				Motor1ControllerRearmotors_move(); 
			}
			else if(distance<=30)    // if distance is less than the required distance let the servo check the right area to the car
			{
				Motor1ControllerRearmotors_stop();
				Motor2Controller_servoRight();
				_delay_ms(1000);				// delay to make sure servo is in its position(hardware limitations)
				ultrasonic_distance(&distance); //read distance after switching servo position
				
				servoPos=right;
			}
		}
		if(servoPos==right)      // the servo is updated to the right position
		{
			if(distance>30)     //if there is space then the car will steer to the right for 2.5 sec and update servo position to the front and steer forward
			{
				Motor1ControllerSteerMotor_TurnRight();
				Motor1ControllerRearmotors_move();
				_delay_ms(2500);
				Motor2Controller_servoFront();
				_delay_ms(1000);
				Motor1ControllerSteerMotor_moveForward();
				servoPos=front;
			}
			else if(distance<=30) // if there is no space in the right position we move the servo to the left position and check 
			{
				Motor2Controller_servoLeft();
				_delay_ms(1000);
				ultrasonic_distance(&distance); //read distance after switching servo position
				servoPos=left;
			}
		}
		if(servoPos==left) // the servo is updated to the left position
		{
			if(distance >30) //if there is space then the car will steer to the left for 2.5 sec and update servo position to the front and steer forward
			{
				Motor1ControllerSteerMotor_TurnLeft();
				Motor1ControllerRearmotors_move();
				_delay_ms(2500);
				Motor2Controller_servoFront();
				_delay_ms(1000);
				Motor1ControllerSteerMotor_moveForward();
				servoPos=front;
				
			}
			else if(distance<=30)  // if there is no space to the left then the car stops
			{
				Motor1ControllerRearmotors_stop();
			}
			
		}
		
    }
}

