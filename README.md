# Embedded Dice Simulator

## Description
This project implements a simple dice simulator on an embedded microcontroller.
A hardware timer is used to generate pseudo-random values between 1 and 6.
When a push button is pressed, the current timer value is captured and the corresponding dice number is displayed on an LCD.

The project demonstrates fundamental embedded system concepts such as timer configuration, GPIO handling, and LCD interfacing.

## Hardware Used
- ARM7-based microcontroller (Philips / NXP)
- Character LCD (16x2)
- Push button switch
- External clock source

## Features
- Timer-based pseudo-random number generation
- Push button input using GPIO
- LCD display output
- Modular embedded C code structure

## Software Concepts
- Embedded C programming
- Timer configuration and usage
- GPIO input handling
- LCD driver implementation
- Polling-based design (with scope for interrupt-based extension)

## How It Works
1. A hardware timer runs continuously and increments a counter.
2. When the push button is pressed, the current timer value is captured.
3. The captured value is mapped to a number between 1 and 6 using a modulo operation.
4. The resulting dice value is displayed on the LCD.

## Future Improvements
- Implement interrupt-based button handling
- Add software debouncing for the push button
- Improve randomness using additional entropy sources
- Port the project to an ARM Cortex-M microcontroller

## Author
Naga Viswanth  
Junior Embedded Systems Engineer
