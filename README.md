# ArduinoSnakeGame - Under Development
A basic Arduino Snake game using an 8x8 LED Matrix display and a single shift register.
This build operates on an atmega328 with "new bootloader".
Developed in PlatformIO

## Snake Game operation

## Display Operation
- The shift register is "loaded" using SPI rather than "Shift_out" to reduce the amount of software needed.
  - This allows the shift register to be loaded at 20 MHz clock frequency as the atmega328 has hardware SPI support.

### More detailed Development Notes can be found in development Notes
- Current development underway is also contained in these notes.
