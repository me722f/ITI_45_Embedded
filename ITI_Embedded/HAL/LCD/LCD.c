/*
 * LCD.c
 *
 *  Created on: Feb 15, 2025
 *      Author: Mohamed-Ibrahim
 */
#include "LCD_interface.h"
#include "LCD_cfg.h"
#include <util/delay.h>

void LCD_write_command(uint8 command)
{

	DIO_writepin(RS_Pin, LOW);
	_delay_ms(1);

#if(LCD_MODE == MODE_8_BITS)

	// R/W to put it to a ground on the hardware

	DIO_writeport (LCD_Port,command);

	DIO_writepin(E_Pin,HIGH);
	_delay_ms(1);
	DIO_writepin(E_Pin,LOW);
	_delay_ms(3);

#elif (LCD_MODE == MODE_4_BITS)

	DIO_writepin(LCD_DB7, GET_BIT(command, 7));
	DIO_writepin(LCD_DB6, GET_BIT(command, 6));
	DIO_writepin(LCD_DB5, GET_BIT(command, 5));
	DIO_writepin(LCD_DB4, GET_BIT(command, 4));


	DIO_writepin(E_Pin, HIGH);
	_delay_ms(1);
	DIO_writepin(E_Pin, LOW);
	_delay_ms(1);

	DIO_writepin(LCD_DB7, GET_BIT(command, 3));
	DIO_writepin(LCD_DB6, GET_BIT(command, 2));
	DIO_writepin(LCD_DB5, GET_BIT(command, 1));
	DIO_writepin(LCD_DB4, GET_BIT(command, 0));

	DIO_writepin(E_Pin, HIGH);
	_delay_ms(1);
	DIO_writepin(E_Pin, LOW);
	_delay_ms(1);

#endif
}

void LCD_write_char(uint8 charachter)
{
	DIO_writepin(RS_Pin, HIGH);

		// R/W to put it to a ground on the hardware

		_delay_ms(1);
#if(LCD_MODE == MODE_8_BITS)


	DIO_writeport (LCD_Port,charachter);

	DIO_writepin(E_Pin,HIGH);
	_delay_ms(1);
	DIO_writepin(E_Pin,LOW);
	_delay_ms(3);

#elif (LCD_MODE == MODE_4_BITS)

	DIO_writepin(LCD_DB7, GET_BIT(charachter, 7));
	DIO_writepin(LCD_DB6, GET_BIT(charachter, 6));
	DIO_writepin(LCD_DB5, GET_BIT(charachter, 5));
	DIO_writepin(LCD_DB4, GET_BIT(charachter, 4));


	DIO_writepin(E_Pin, HIGH);
	_delay_ms(1);
	DIO_writepin(E_Pin, LOW);
	_delay_ms(1);

	DIO_writepin(LCD_DB7, GET_BIT(charachter, 3));
	DIO_writepin(LCD_DB6, GET_BIT(charachter, 2));
	DIO_writepin(LCD_DB5, GET_BIT(charachter, 1));
	DIO_writepin(LCD_DB4, GET_BIT(charachter, 0));

	DIO_writepin(E_Pin, HIGH);
	_delay_ms(1);
	DIO_writepin(E_Pin, LOW);
	_delay_ms(1);
#endif
}


void LCD_write_string(uint8 *str){

	uint8 i = 0;

	while(str[i] != '\0')
	{
		LCD_write_char(str[i]);
		i++;
	}

}

void LCD_write_number(sint32 number)
{
	uint8 num_digit[10];

	uint8 i = 0;

	while(number > 0)
	{
		num_digit[i] = number % 10;
		number = number / 10 ;
		i++;
	}

	while(i != 0)
	{
		i--;
		LCD_write_char( (num_digit[i] + '0') );

	}

}

void LCD_goto(uint8 row , uint8 col)
{
	uint8 address = 0X80;

	if(row == 0)
	{
		LCD_write_command(address + col);
	}
	else if(row == 1)
	{

		LCD_write_command( ( address + col + 0X40 ) );
	}

}

void LCD_write_string_goto(uint8 *str, uint8 row, uint8 col)
{
	LCD_goto(row, col);
	LCD_write_string(str);
}

void LCD_clear_(void)
{
	LCD_write_command(0x01);
}

void LCD_init(void)
{

#if(LCD_MODE == MODE_8_BITS)

	_delay_ms(31);
	LCD_write_command(0X38);
	_delay_ms(1);

	LCD_write_command(0X0C);
	_delay_ms(1);

	LCD_write_command(0X01);
	_delay_ms(2);

#elif(LCD_MODE == MODE_4_BITS)

	_delay_ms(31);
	LCD_write_command(0X33);
	_delay_ms(1);

	LCD_write_command(0X32);
	_delay_ms(1);

	LCD_write_command(0X28);
	_delay_ms(2);

	LCD_write_command(0X01);
	_delay_ms(2);

	LCD_write_command(0X0C);
	_delay_ms(1);


#endif

}
