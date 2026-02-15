#ifndef LCD_H
#define LCD_H

#include <lpc21xx.h>

/* LCD pin configuration */
#define LCD  0x000000FF   // P0.0 - P0.7
#define RS   (1 << 8)    // P0.8
#define E    (1 << 9)     // P0.9

/* Function declarations */
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_string(unsigned char*);
void delay_millisec(unsigned int);

#endif
