#ifndef Snake_h
#define SNake_h

#include <Arduino.h>

#include "classSnake.h"
#include "classSnakeNode.h"
#include "classMatrixDisplay.h"
#include "classFood.h"

class Game
{
    public:
        Food food;
        Snake snake;
        MatrixDisplay matrixDisp(uint8_t rowPinArray, uint8_t latch_pin);

        Game();
        void newFood();
};

#endif