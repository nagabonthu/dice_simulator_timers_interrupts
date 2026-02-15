/**********************************************
* Project: Dice Random number Generator
* MCU: lpc2129 Processor ARM7TDMI
***********************************************/
#include <lpc21xx.h>
#include "lcdh.h"
#include "lcd.c"

/*Global variable*/
unsigned char num=1;
unsigned char count=0;

#define SW 16 //P0.16 connected to a switch

/* ISR for External Interrupt 0*/
void dice_randomnumber(void) __irq
{
	EXTINT=0x01;  	       //clear EINT0 flag
	num=(T1PC%6)+1;        //Generate random number(1-6)
	VICIntEnClr=(1<<14);   //Disable EINT0 flag(debouncing)
	delay_millisec(50);
	VICIntEnable|=(1<<14); //Enable EINT0 again
    VICVectAddr=0;        //End of Isr
}
int main()
{
	/* Configure EINT0 on p0.16*/
	PINSEL1|=0x01;
	
	/*Timer1 configuration*/
	T1PR=6-1;      //Prescaler
	T1TCR=0x02;    //Reset Timer1
	T1TCR=0x01;    //Start Timer1
	
/* Interrupt configuration */
	VICIntSelect=0;         //IRQ
	VICVectCntl0=(0x20)|14; //Slot0 assigned to EINT0
	VICVectAddr0=(unsigned long)dice_randomnumber;
	EXTMODE=0x01;          //Edge sensitive
	EXTPOLAR=0x01;         //Rising edge
	VICIntEnable=1<<14;    // Enable EINT0
	
/* lcd initialization */
	lcd_init(); 
	lcd_cmd(0x80);
	lcd_string("Rolling dice");
	
	while(1)
	{
	lcd_cmd(0xc0);
	lcd_string("Dice:");
	lcd_data(num+48);// converting the number to ASCII value	
		
		if(((IOPIN0>>SW)&1)==0)
		{
			count++;
			lcd_cmd(0x8E);
			lcd_data((count/10)+48);
			lcd_data((count%10)+48);
			while(((IOPIN0>>SW)&1)==0);  //wait for release 
			delay_millisec(50);         //Extra bounce
		}		
	}
}

