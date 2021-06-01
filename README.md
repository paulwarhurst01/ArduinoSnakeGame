# ArduinoSnake
A basic Arduino Snake game using an 8x8 LED Matrix display and a single shift register.

## Ver 0 - Initial Design
### Overview
- Initial design makes use of a single 8-bit shift-register and reloading the full shift register byte for each column. 
- 8 digital pins control the rows.

### Observations
- Visible light-spill due to slow switching

- This initial configuration should be reversed - currently the digital pin corresponding to the row changes once for every 8-reloads of the shift register whihc is loaded serially.
- Switching the two would increase speed and possibly prevent the visible light spill.

N.B. The system would benefit from a second shift register cutting down on pins
