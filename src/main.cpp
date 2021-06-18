#include <Arduino.h>
#include "classMatrixDisplay.h"
#include "classSnake.h"
#include "classSnakeNode.h"

uint8_t display_array[8][8] = {
    // Initial S display array
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

// Instantiate Matrix Display array
uint8_t rowPinArray[8] = {2, 3, 4, 5, 6, 7, 8, 9};
MatrixDisplay matrixDisp(rowPinArray, 10);

// Instantiate snake object
Snake snake;

void setup() {
  // Copy in inital S array
  matrixDisp.updateDisplayArray(display_array);
  //delay(2000);
}

void loop() {
    matrixDisp.refreshDisplay();                    // Constantly refresh display array
}