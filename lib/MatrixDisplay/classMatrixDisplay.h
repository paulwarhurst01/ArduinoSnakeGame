/*
    MatrixDisplay.h - Library for 8x8 Matrix display
    Created by Paul Warhurst, June 3rd, 2021.
    MIT license
    Options for one 1 shift register as well as two
*/

#ifndef Display_h
#define Display_h

#include <Arduino.h>
#include <SPI.h>

#include "classSnakeNode.h"

class MatrixDisplay
{
    public:
        MatrixDisplay(uint8_t row_pins[8], uint8_t latchPin);       // Class constructor
        void updateDisplayArray(uint8_t displayArray[8][8]);        // Updates array by copying in another complete array
        void setPixel(uint8_t x, uint8_t y, uint8_t val);           // Set individual Pixel in display array
        void updateDisplayList(SnakeNode *tail);                    // Updates array using a list passed
        void refreshDisplay();                                      // Refreshs display column by column
        uint8_t getPixelValue(uint8_t x, uint8_t y);                                    // Returns the vlaue of a pixel in _display_array
    private:
        uint8_t _latch_pin;                                         // Latch pin for shift reg
        uint8_t _row_pins[8];                                       // 8 pins for rows
        uint8_t _display_array[8][8];                               // internal display array that represents LED matrix
};

#endif