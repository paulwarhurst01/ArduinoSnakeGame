#include <Arduino.h>
#include <classMatrixDisplay.h>

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

// Instantiate Matrix Display array
int rowPinArray[8] = {2, 3, 4, 5, 6, 7, 8, 9};
MatrixDisplay matrixDisp(rowPinArray, 10);

void setup() {
}

void loop() {
    matrixDisp.updateDisplay(display_array);
    matrixDisp.refreshDisplay();
}