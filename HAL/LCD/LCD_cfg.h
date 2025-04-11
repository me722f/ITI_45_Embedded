/*
 * LCD_cfg.h
 *
 *  Created on: Feb 15, 2025
 *      Author: Mohamed-Ibrahim
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_


#define MODE_4_BITS   4
#define MODE_8_BITS   8

#define LCD_MODE MODE_4_BITS

#if(LCD_MODE == MODE_8_BITS)

# define RS_Pin PINA0
# define E_Pin PINA1
# define LCD_Port PB

#elif(LCD_MODE == MODE_4_BITS)

#define LCD_DB4 PINC0
#define LCD_DB5 PINC1
#define LCD_DB6 PINC2
#define LCD_DB7 PINC3

#define RS_Pin PIND0
#define E_Pin  PIND1


#endif







#endif /* HAL_LCD_LCD_CFG_H_ */
