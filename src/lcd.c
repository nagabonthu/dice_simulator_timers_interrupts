#include "lcd.h"

/* LCD initialization */
void lcd_init(void)
{
	IODIR0|= LCD|RS|E;
	lcd_cmd(0x01);//Clear display
	lcd_cmd(0x02);// Return home
	lcd_cmd(0x0c);// Display ON, cursor OFF
	lcd_cmd(0x38);//8 bit-mode, 2 lines
}

/* Send command to LCD */
void lcd_cmd(unsigned char cmd)
{
	IOCLR0 = LCD;      //Clear lcd display
	IOSET0 = cmd;
	IOCLR0 = RS;   // Rs=0 (command)
	IOSET0 = E;
	delay_millisec(2);
	IOCLR0 = E;
}

/* Send data to LCD */
void lcd_data(unsigned char data)
{
	IOCLR0 = LCD; //Clear lcd display
	IOSET0 = data;
	IOSET0 = RS;   //RS=1 (data)
	IOSET0 = E;
	delay_millisec(2);
	IOCLR0 = E;
}

/* Millisecond delay using Timer0 */
void delay_millisec(unsigned int ms)
{
	T0PR=15000-1;    // Prescaler for 1 ms
	T0TCR=0x01;       // Start timer
	while(T0TC<ms);
	T0TCR=0x03;        // Reset timer
	T0TCR=0x00;         // Stop timer
}

/* Display string on LCD */
void lcd_string(unsigned char *str)
{
	while(*str)
	lcd_data(*str++);
}
