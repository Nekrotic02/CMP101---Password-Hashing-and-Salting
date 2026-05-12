# CMP101 Wemos Hardware Integration Project

First-semester university hardware/software integration coursework using a Wemos D1 mini ESP8266.

This project was built for CHAOS / CMP101 during my first semester at university. The assignment was open-ended: use the Wemos kit and available hardware components to build something interactive that demonstrated basic hardware and software concepts.

At the time, I had only recently started programming. I used the components available to create an interactive sketch that accepted serial input, transformed it with a hash function, incorporated simple hardware-derived values, and displayed output across multiple devices.

## What it does

- accepts input over serial
- hashes the input as a demonstration
- reads analogue input from the Wemos
- reads button state from a TM1638 module
- displays values on a 7-segment display
- controls LEDs based on hardware input
- displays text output on an OLED screen
- uses RTC/time output as part of the demo

## What it demonstrates

- Wemos D1 mini / ESP8266 development
- Arduino-style C/C++ sketch structure
- serial communication
- OLED display output
- TM1638 / 7-segment display interaction
- button input
- LED output
- analogue input
- basic hardware/software integration

## Current status

This is historical first-semester coursework and not an active project.

The hashing theme was used as a way to connect multiple hardware inputs and outputs. It should be understood as an early hardware integration exercise, not as a production password-storage or cryptography implementation.
