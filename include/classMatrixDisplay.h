/*
    MatrixDisplay.h - Library for 8x8 Matrix display
    Created by Paul Warhurst, June 3rd, 2021.
    MIT license
    Options for one 1 shift register as well as two
*/

#ifndef Display_h
#define Display_h

#include "Arduino.h"
#include "SPI.h"

class MatrixDisplay
{
    public:
        MatrixDisplay(int row_pins[8], int latchPin);
        void updateDisplay(int displayArray[8][8]);
        void refreshDisplay();
    private:
        int _latch_pin;
        int _row_pins[8];
        int _display_array[8][8];
};

#endif