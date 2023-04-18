/*
 * Motor1Controller.h
 *
 * Created: 4/13/2023 4:02:31 AM
 *  Author: MS_el
 */ 


#ifndef MOTOR1CONTROLLER_H_
#define MOTOR1CONTROLLER_H_

#define steerMotorIn1 3
#define steerMotorIn2 4
#define rearMotorIn1 5
#define rearMotorIn2 6
#define H_EN1 4
#define H_EN2 5


void Motor1Controller_init();

void Motor1ControllerRearmotors_move();
void Motor1ControllerRearmotors_moveSlow();
void Motor1ControllerRearmotors_stop();

void Motor1ControllerSteerMotor_TurnLeft();
void Motor1ControllerSteerMotor_TurnRight();
void Motor1ControllerSteerMotor_moveForward();







#endif /* MOTOR1CONTROLLER_H_ */