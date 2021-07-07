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
        Food *food;
        Snake *snake;
        MatrixDisplay *matrixDisp;

        Game(uint8_t rowPinArray[8], uint8_t latch_pin);
        void loadIntroScreen();
        void newFood();         
        void moveSnake();           
        void checkDirection();  // Checks pins and sets new direction if necessary
};

#endif