#ifndef Game_h
#define Game_h

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
        uint8_t skipTailInc;

        Game(uint8_t rowPinArray[8], uint8_t latch_pin,
                uint8_t up_pin, uint8_t left_pin,
                uint8_t down_pin, uint8_t right_pin);
        void loadIntroScreen();
        void newFood();         
        void moveSnake();           
        void checkDirection();  // Checks pins and sets new direction if necessary
    private:
        uint8_t _direction_pins[4];
};

#endif