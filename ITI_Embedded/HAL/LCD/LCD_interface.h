/*
 * LCD_interface.h
 *
 *  Created on: Feb 15, 2025
 *      Author: Mohamed-Ibrahim
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

# include "utils.h"
# include "mem_map.h"
# include "std_types.h"

# include "DIO_interface.h"



void LCD_init(void);

void LCD_write_command(uint8 command);

void LCD_write_char(uint8 character);

void LCD_write_string(uint8 *str);

void LCD_write_number(sint32 number);

void LCD_goto(uint8 row, uint8 col);

void LCD_write_string_goto(uint8 *str, uint8 row, uint8 col);

void LCD_clear_(void);





#endif /* HAL_LCD_LCD_INTERFACE_H_ */
