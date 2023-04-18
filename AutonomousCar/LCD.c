/*
 * LCD.c
 *
 * Created: 12/23/2022 11:03:40 AM
 *  Author: MS_el
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STDMACROS.h"
#include "LCD.h"

void LCD_send_command(unsigned char cmd)
{
	LCD_data_port = cmd;
	clearbit(LCD_control_port,RS);
	clearbit(LCD_control_port,RW);
	setbit(LCD_control_port,EN);
	_delay_us(1);
	clearbit(LCD_control_port,EN);
	_delay_ms(3);
}
void LCD_send_data(unsigned char data)
{
	LCD_data_port = data;
	setbit(LCD_control_port,RS);
	clearbit(LCD_control_port,RW);
	setbit(LCD_control_port,EN);
	_delay_us(1);
	clearbit(LCD_control_port,EN);
	_delay_ms(3);
}
void LCD_INIT(void)
{
	LCD_data_DIR= 0xff;
	setbit(LCD_control_DIR,EN);
	setbit(LCD_control_DIR,RS);
	setbit(LCD_control_DIR,RW);
	_delay_ms(20);
	LCD_send_command(0x38);
	LCD_send_command(0x0C);
	LCD_send_command(0x06);
	LCD_send_command(0x01);
	LCD_send_command(0x80);
}
void LCD_sendString(char* str)
{	
	int i=0;
	while(str[i]!='\0'){
		
		LCD_send_data(str[i]);
		i++;
		
	}
}


void LCD_send_data_4bit(unsigned char data)
{
	LCD_data_port = (LCD_data_port & 0x0f) |(data & 0xf0);
	setbit(LCD_control_port,RS);
	clearbit(LCD_control_port,RW);
	setbit(LCD_control_port,EN);
	_delay_us(1);
	clearbit(LCD_control_port,EN);
	_delay_us(200);
	LCD_data_port = (LCD_data_port & 0x0f) |(data<<4);
	setbit(LCD_control_port,EN);
	_delay_us(1);
	clearbit(LCD_control_port,EN);
	_delay_ms(1);	
}
void LCD_send_command_4bit(unsigned char cmd)
{
	LCD_data_port = (LCD_data_port & 0x0f) |(cmd & 0xf0);
	clearbit(LCD_control_port,RS);
	clearbit(LCD_control_port,RW);
	setbit(LCD_control_port,EN);
	_delay_us(1);
	clearbit(LCD_control_port,EN);
	_delay_us(200);
	LCD_data_port = (LCD_data_port & 0x0f) |(cmd<<4);
	setbit(LCD_control_port,EN);
	_delay_us(1);
	clearbit(LCD_control_port,EN);
	_delay_ms(1);
	
}
void LCD_INIT_4bit()
{
	LCD_data_DIR |= 0xf0;
	setbit(LCD_control_DIR,EN);
	setbit(LCD_control_DIR,RS);
	setbit(LCD_control_DIR,RW);
	LCD_send_command_4bit(0x02);
	LCD_send_command_4bit(0x28);
	LCD_send_command_4bit(0x0C);
	LCD_send_command_4bit(0x06);
	LCD_send_command_4bit(0x01);
	_delay_ms(20);
}
void LCD_sendString_4bit(char* str)
{
	int i=0;
	while(str[i]!='\0'){
		
		LCD_send_data_4bit(str[i]);
		i++;
		
	}
}