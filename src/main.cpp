#include <Arduino.h>
#include <SPI.h>

// Latch pin for the shift register
const int latchPin = 10;

// Col is active Low
// Row is active High
const int rowPinArray[8] = {2, 3, 4, 5, 6, 7, 8, 9};

/*int initial_display_array[8][8] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 1, 1, 1},
    {1, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}

    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},

    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},

  };*/

int display_array[8][8] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 1, 1, 1},
    {1, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}

    // Various initial arrays to check performance - Comment out all arrays except test

    /*{1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0}*/

    /*{0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},*/
  };

void setup() {
    //set pins to output because they are addressed in the main loop
    pinMode(latchPin, OUTPUT);
    SPI.begin();
    SPI.beginTransaction(SPISettings(20000000, MSBFIRST, SPI_MODE0));
    //pinMode(dataPin, OUTPUT);
    //pinMode(clockPin, OUTPUT);

    for(int i = 0; i < 8; i++){
        pinMode(rowPinArray[i], OUTPUT);
        digitalWrite(rowPinArray[i], LOW);
    }

    // Reset shift register
    digitalWrite(latchPin, LOW);
    //shiftOut(dataPin, clockPin, MSBFIRST, 0xff);
    SPI.transfer(0xff);
    digitalWrite(latchPin, HIGH);

    Serial.begin(9600);
    Serial.println("reset");

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            Serial.print(display_array[i][j]);
            Serial.print("\t");
        }
        Serial.print("\n");
    }
}

void loop() {

   for(int j = 0; j < 8; j++){

        byte bits_to_send = 0xff;
        bitWrite(bits_to_send, j, LOW);

        digitalWrite(latchPin, LOW);
        SPI.transfer(bits_to_send);
        digitalWrite(latchPin, HIGH);

        for(int i = 0; i < 8; i++){
            if(display_array[i][j]){
                digitalWrite(rowPinArray[i], HIGH);
            }
        }
        // Delay to allow LEDs to illimuniate
        delayMicroseconds(2000);

        // Turn all pins Low
        for(int i = 0; i < 8; i++){
            if(display_array[i][j]){
                digitalWrite(rowPinArray[i], LOW);
            }
        }

    }
}