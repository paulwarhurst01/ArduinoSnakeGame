#include <Arduino.h>
#include <classMatrixDisplay.h>

MatrixDisplay::MatrixDisplay(int row_pins[8], int latchPin){
    _latch_pin = latchPin;
    pinMode(latchPin, OUTPUT);
    for(int i = 0; i < 8; i++){
        _row_pins[i] = row_pins[i];
        pinMode(_row_pins[i], OUTPUT);
        // Set all LEDs off intially starting with setting row pins low
        digitalWrite(_row_pins[i], LOW);
    }
    SPI.begin();
    SPI.beginTransaction(SPISettings(20000000, MSBFIRST, SPI_MODE0));

    // Reset shift register to all LEDs off - Active low so set high.
    digitalWrite(latchPin, LOW);
    SPI.transfer(0xff);
    digitalWrite(latchPin, HIGH);
}

void MatrixDisplay::updateDisplay(int displayArray[8][8]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            _display_array[i][j] = displayArray[i][j];
        }
    }
}

void MatrixDisplay::refreshDisplay(){
    // Loop through 2D display array updating hardware LED matrix
    for(int j = 0; j < 8; j++){
        // Set current column being refreshed LOW and rest HIGH
        byte bits_to_send = 0xff;
        bitWrite(bits_to_send, j, LOW);

        // Send byte through SPI to shift-reg
        digitalWrite(_latch_pin, LOW);
        SPI.transfer(bits_to_send);
        digitalWrite(_latch_pin, HIGH);

        // Reflect display array by setting LEDs in that column active HIGH 
        for(int i = 0; i < 8; i++){
            if(_display_array[i][j]){
                digitalWrite(_row_pins[i], HIGH);
            }
        }
        // Delay to allow LEDs to illimuniate
        delayMicroseconds(2000);

        // Turn all pins that were active HIGH, LOW
        for(int i = 0; i < 8; i++){
            if(_display_array[i][j]){
                digitalWrite(_row_pins[i], LOW);
            }
        }
    }
}
    