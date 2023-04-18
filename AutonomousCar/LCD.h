/*
 * LCD.h
 *
 * Created: 12/23/2022 11:03:55 AM
 *  Author: MS_el
 */ 


#ifndef LCD_H_
#define LCD_H_
#define RS 1
#define RW 2
#define EN 3
#define LCD_control_DIR DDRB
#define LCD_data_DIR DDRA
#define LCD_control_port PORTB
#define LCD_data_port PORTA
void LCD_INIT(void);
void LCD_send_data(unsigned char data);
void LCD_send_command(unsigned char cmd);
void LCD_sendString(char* str);

void LCD_send_data_4bit(unsigned char data);
void LCD_send_command_4bit(unsigned char cmd);
void LCD_INIT_4bit();
void LCD_sendString_4bit(char* str);
#endif /* LCD_H_ */