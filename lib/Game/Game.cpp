#include <Arduino.h>

#include "classGame.h"
#include "classSnake.h"
#include "classSnakeNode.h"
#include "classMatrixDisplay.h"
#include "classFood.h"

Game::Game(uint8_t rowPinArray[8], uint8_t latchPin){
    this->loadIntroScreen();
    this->matrixDisp = new MatrixDisplay(rowPinArray, latchPin);
}

void Game::newFood(){
    this->food->newLocation();
    // Check food isn't colliding with snake
}

void Game::loadIntroScreen()
{
    uint8_t intro_display_array[8][8] = {
        // Initial S display array
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

    this->matrixDisp->updateDisplayArray(intro_display_array);

}