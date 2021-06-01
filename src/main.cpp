#include <Arduino.h>

const int latchPin = 12;
const int clockPin = 11;
const int dataPin = 10;


// Col is active Low
// Row is active High
const int rowPinArray[] = {2, 3, 4, 5, 6, 7, 8, 9};

/*int initial_display_array[8][8] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 1, 1, 1},
    {1, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
  };*/

int initial_display_array[8][8] = {
    {1, 1, 1, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 1, 1, 1},
    {1, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
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
    shiftOut(dataPin, clockPin, MSBFIRST, 0xFF);
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
    for(int i = 0; i < 8; i++){
        digitalWrite(rowPinArray[i], HIGH);
        for(int j = 0; j < 8; j++){
            byte bits_to_send = 0xff;
            if(initial_display_array[i][j] == 1){
                bitWrite(bits_to_send, j, LOW);
                digitalWrite(latchPin, LOW);
                shiftOut(dataPin, clockPin, MSBFIRST, bits_to_send);
                digitalWrite(latchPin, HIGH);
                delayMicroseconds(50);
            }
        }
        digitalWrite(rowPinArray[i], LOW);
    }

    /*for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(intialDisplayArray[i][j]){
                digitalWrite(rowPinArray[i], HIGH);
                digitalWrite(snakeColPinArray[j], LOW);
                delayMicroseconds(100);
                digitalWrite(rowPinArray[i], LOW);
                digitalWrite(snakeColPinArray[j], HIGH);
            }
        }
    }*/
}