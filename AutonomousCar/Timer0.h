/*
 * Timer0.h
 *
 * Created: 1/6/2023 8:53:02 PM
 *  Author: AMIT
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

void Timer0_INIT_Normal();
void Timer0_INIT_Comp(int valuex);
void delay_ms(float delay);
void Timer0_INIT_FastPWM();
void Timer0_Set_DC(float DC);
void Timer0_INIT_PhaseCorrectPWM();


#endif /* TIMER0_H_ */