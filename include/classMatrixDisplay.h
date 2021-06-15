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
#include <structSnakeNode.h>

class MatrixDisplay
{
    public:
        MatrixDisplay(int row_pins[8], int latchPin);       // Class constructor
        void updateDisplayArray(int displayArray[8][8]);    // Updates array by copying in another complete array
        void updateDisplayList(SnakeNode *tail);            // Updates array using a list passed
        void refreshDisplay();                              // Refreshs display column by column
    private:
        int _latch_pin;                                     // Latch pin for shift reg
        int _row_pins[8];                                   // 8 pins for rows
        int _display_array[8][8];                           // internal display array that represents LED matrix
};

#endif