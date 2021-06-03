# ArduinoSnake
A basic Arduino Snake game using an 8x8 LED Matrix display and a single shift register.

## Initial Display Design and Implementation
### Overview
- Initial design makes use of a single 8-bit shift-register and reloading the full shift register byte for each column. 
- 8 digital pins control the rows.

### Observations
- Visible light-spill due to slow switching

- This initial configuration should be reversed - currently the digital pin corresponding to the row changes once for every 8-reloads of the shift register whihc is loaded serially.
- Switching the two would increase speed and possibly prevent the visible light spill.

N.B. The system would benefit from a second shift register cutting down on pins

### Observations after Switching
- Resolution is much sharper, no longer get "light spill" from LED's turning on out of sync.
- Noticeable refresh from left to right as bits are written to shift register
    -   Possible Solution: Shift register manually rather than loading full byte each time
    -   This resulted in noticeable improvement but still noticeable, unpleasant refresh flicker
    -   Need to switch to other hardware implementation.

## Notes

- Current hardware implementation limits snake's size. 
- Polling is too slow
    - Temporarily switch to two arduino design with Arduino's communicating through i2c
    - Or switch to SPI, less software involved

## Using SPI
- Shift reg Max clock speed - 25 MHz - Use 20 MHz for Arduino
- Using default SPI mode

# Solution - Obviously
- Turn on everything in column
    - Implementation greatly increased the refresh rate.