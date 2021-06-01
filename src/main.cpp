#include <Arduino.h>

const int latchPin = 11;
const int clockPin = 12;
const int dataPin = 10;


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

  };*/

int initial_display_array[8][8] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
  };

void setup() {
    //set pins to output because they are addressed in the main loop
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);

    for(int i = 0; i < 8; i++){
        pinMode(rowPinArray[i], OUTPUT);
        digitalWrite(rowPinArray[i], LOW);
    }

    // Reset shift register
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0xff);
    digitalWrite(latchPin, HIGH);

    Serial.begin(9600);
    Serial.println("reset");

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            Serial.print(initial_display_array[i][j]);
            Serial.print("\t");
        }
        Serial.print("\n");
    }
}

void loop() {
    digitalWrite(dataPin, LOW);
    digitalWrite(latchPin, LOW);
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
    digitalWrite(latchPin, HIGH);

    for(int j = 0; j < 8; j++){

        //digitalWrite(clockPin, HIGH);
        //digitalWrite(clockPin, LOW);

        //byte bits_to_send = 0xff;
        //bitWrite(bits_to_send, j, LOW);

        //digitalWrite(latchPin, LOW);
        //shiftOut(dataPin, clockPin, MSBFIRST, bits_to_send);
        //digitalWrite(latchPin, HIGH);

        for(int i = 0; i < 8; i++){
            if(initial_display_array[i][j]){
                Serial.print(i);
                Serial.print("\t");
                Serial.print(j);
                Serial.print("\n");
                digitalWrite(rowPinArray[i], HIGH);
                delayMicroseconds(1000);
                digitalWrite(rowPinArray[i], LOW);
            }
        }
        digitalWrite(dataPin, HIGH);
        digitalWrite(latchPin, LOW);
        digitalWrite(clockPin, HIGH);
        digitalWrite(clockPin, LOW);
        digitalWrite(latchPin, HIGH);
    }
}