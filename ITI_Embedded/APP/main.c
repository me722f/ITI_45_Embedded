
#include"DIO_interface.h"
#include "std_types.h"
#include <util/delay.h>
//#define RS PIN0
//#define E PIN1
//PIN2 R/W


//void LCD_write_command(uint8 command){
//DIO_writepin(RS,LOW);
//DIO_writeport (PB,command);
//DIO_writepin(E,HIGH);
//_delay_ms(1);
//DIO_writepin(E,LOW);
//}
//
//void LCD_write_data(uint8 character){
//DIO_writepin(RS,HIGH);
//DIO_writeport (PB,character);
//DIO_writepin(E,HIGH);
//_delay_ms(1);
//DIO_writepin(E,LOW);
//}
//
//void LCD_init(void){
//	_delay_ms(30);
//	LCD_write_command(0x38);
//	_delay_ms(1);
//	LCD_write_command(0x0c);
//	_delay_ms(1);
//	LCD_write_command(0x01);
//	_delay_ms(3);
//
//}
//void LCD_write_string(uint8 *str){
//	uint8 i=0;
//
//	while(str[i] != '\0'){
//		LCD_write_data(str[i]);
//		i++;
//	}
//
//}
//void LCD_goto(uint8 row, uint8 col)
//{
//	if (row ==  0)
//	{
//		LCD_write_command(0x80 + 0x00 + col);
//	}
//	else if (row == 1)
//	{
//		LCD_write_command(0x80 + 0x40 + col);
//	}
//}
//
//
///*
// OUTPUT,//	PC0
//OUTPUT,	//	PC1
//OUTPUT,	//	PC2
//OUTPUT,	//	PC3
//INPUT_PULLUP,	//	PC4
//INPUT_PULLUP,	//	PC5
//INPUT_PULLUP,	//	PC6
//INPUT_PULLUP,	//	PC7 */
//void Keypad_init (){
//
//	DIO_writepin(PIN16,HIGH);
//	DIO_writepin(PIN17,HIGH);
//	DIO_writepin(PIN18,HIGH);
//	DIO_writepin(PIN19,HIGH);
//
//}
//
//#define ROW1 16
//#define COL1 20
//
///*uint8 array[4][4] = {
//    {'1',  2,  3,  4},
//    {5,  6,  7,  8},
//    {9, 10, 11, 12},
//    {13,14, 15, 16}
//};
//
//
//*/
//
//char array[4][4] = {
//    {'1', '2', '3', 'A'},
//    {'4', '5', '6', 'B'},
//    {'7', '8', '9', 'C'},
//    {'*', '0', '#', 'D'}
//};
//
//
//uint8 Keypad_getkey(){
//
//
//	for(uint8 ROW=0 ;ROW<4;ROW++)
//	{
//		DIO_writepin(ROW1+ROW,LOW);
//		for(uint8 COL=0 ;COL<4;COL++)
//		{
//
//			if (DIO_readpin(COL1+COL) == 0)
//
//			{	while(DIO_readpin(COL1+COL) == 0);
//				DIO_writepin(ROW1+ROW,HIGH);
//				return array[ROW][COL];
//			}
//
//		}
//		DIO_writepin(ROW1+ROW,HIGH);
//	}
//	return '!';
//}

int main(){


//LCD_init();
//
//
//	char array[]="Mohamed";
//	LCD_write_string(array);
//	LCD_goto(0, 7);
//	LCD_write_data('A');

}
