# Embedded Dice Simulator

## Overview
A simple embedded system that simulates dice rolls using a hardware timer on an ARM7 based microcontroller. When a push button is pressed, the timer value is captured to generate a pseudo‑random number between 1 and 6, which is displayed on a 16x2 LCD. This project demonstrates fundamental embedded system concepts such as timer configuration, GPIO handling, and LCD interfacing.

## Hardware Components
- LPC2129 ARM7TDMI Development Board (with inbuilt 12 MHz crystal oscillator)
- Alphanumeric LCD (16x2)
- Push button switch

## Software Components 
- Embedded C - bare-metal firmware development
- Keil µVision IDE - for compilation, debugging, and simulation
- Flash Magic - uploading firmware to LPC2129 via UART bootloader
- GitHub – version control and documentation

## Skills Demonstrated
- Timer configuration for pseudo-random number generation
- Interrupt handling for responsive event capture
- GPIO input handling with push button interface
- LCD driver implementation
- Firmware debugging and validation in Keil µVision
- Board programming via Flash Magic
  
## Working Principle
1. Hardware timer runs continuously on LPC2129.
2. Push button press captures the current timer value.
3. Captured value is mapped to a dice number (1–6).
4. Result is displayed on the 16x2 LCD.

## Author
Naga Viswanth  
Junior Embedded Systems Engineer
