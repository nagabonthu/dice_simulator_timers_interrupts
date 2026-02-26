# Embedded Dice Simulator 

##  Abstract
This project implements a dice roll simulator using an ARM7 (LPC2129) microcontroller.  
A hardware timer is used to generate a pseudo-random number between 1 and 6 when a push button is pressed, and the result is displayed on a 16×2 LCD.

The project focuses on core embedded system concepts such as timers, interrupts, GPIO handling, and LCD interfacing.

##  Hardware Components
- LPC2129 ARM7TDMI Development Board 
- 16×2 Alphanumeric LCD 
- Push button switch

## Software Tools
- Embedded C 
- Keil µVision IDE 
- Flash Magic 

##  Working Principle
1. A hardware timer runs continuously on the LPC2129.
2. When the push button is pressed, an external interrupt is triggered.
3. The current timer value is captured.
4. The captured value is mapped to a number between 1 and 6 using a modulo operation.
5. The dice value is displayed on the 16×2 LCD.

##  Skills Demonstrated
- Timer configuration for pseudo-random number generation
- External interrupt handling
- GPIO input handling with push button interface
- 16×2 LCD driver development
- Bare-metal Embedded C programming
- Firmware debugging and validation using Keil µVision
