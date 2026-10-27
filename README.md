# PIC18F4580 Digital Calculator

## Overview
This project implements a digital calculator using the **PIC18F4580 microcontroller**, a 4×4 matrix keypad, and a 16×2 LCD. It performs basic arithmetic operations and displays the entered numbers and calculated results on the LCD.

## Features
- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`x`)
- Division (`/`)
- 4×4 matrix keypad input
- 16×2 LCD output
- Clear (`C`) and calculate (`=`) functions

## Hardware Requirements
- PIC18F4580 microcontroller
- 4×4 matrix keypad
- 16×2 LCD
- Power supply
- Connecting wires
- Suitable programmer and development board

## Software Requirements
- MPLAB X IDE
- XC8 C Compiler
- PICkit programmer or compatible programming hardware

## Pin Connections

| Component | PIC18F4580 Pin |
|---|---|
| LCD RS | RC0 |
| LCD Enable | RC1 |
| LCD Data (D0–D7) | PORTD |
| Keypad | PORTB |

**Note:** Configure the keypad rows and columns according to the wiring used in your circuit.

## Keypad Layout

| 7 | 4 | 1 | C |
|---|---|---|---|
| 8 | 5 | 2 | 0 |
| 9 | 6 | 3 | = |
| / | x | - | + |

## Working Principle
1. The keypad is scanned to detect the pressed key.
2. Numeric keys are displayed on the LCD and stored as operands.
3. An arithmetic operator selects the required operation.
4. Pressing `=` calculates and displays the result.
5. Pressing `C` clears the current calculation.

## How to Run
1. Open MPLAB X IDE.
2. Create a project for the PIC18F4580.
3. Add the calculator source code.
4. Configure the device settings and oscillator according to your hardware.
5. Compile the program using the XC8 compiler.
6. Program the microcontroller and test the calculator.

## Author
Krunal Wade

## License
This project is available for educational and learning purposes.
