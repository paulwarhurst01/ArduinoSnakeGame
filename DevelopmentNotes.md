## Snake Game Design and Implementaion
### Initial
- Initial design contains its own array that gets copied into the display array
    - This design is inefficient, future iterations will look into using the same array or only
        modifying the moving parts in the display array rather than the whole array
- Snake class will contain a linked list of the tail, head and any "bends" in the snake
    - This means it is unnecessary to keep track of the entire snake
    - Moving the snake does not involve keeping track of every LED or snake "segment"
- Each snake list item contains the type of snake entity (tail, bend or head), the x and y coordinates of that snake entity, and the direction from that entity to the next.
    - 1 - Up
    - 2 - Left
    - 3 - Down
    - 4 - Right
- Moving the snake using the buttons changes the direction of the head
- The snake moves by adding 1 to the snake head in the head's direction e.g. Move up, heads y coord would increase by 1. Move left would decrement the x coord by one
- Bends remain static until: [coords of the tail] == [coords of bend], bend is removed from linked list
- This could possibly lead to fragmentation of menu given sufficient bends - should this be an issue,
    one large chunk of memory will be initially set aside

## Initial Display Design and Implementation
### Overview
- Initial design makes use of a single 8-bit shift-register and reloading the full shift register byte for each column. 
- 8 digital pins control the rows - these are set active high for the related shift-reg byte.

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
    - Final Implementation used.