#include <Arduino.h>

#include "classGame.h"
#include "classSnake.h"
#include "classSnakeNode.h"
#include "classMatrixDisplay.h"
#include "classFood.h"

Game::Game(uint8_t rowPinArray[8], uint8_t latchPin,
            uint8_t up_pin, uint8_t left_pin,
            uint8_t down_pin, uint8_t right_pin)
{
    // Set pins to be used to change snakes direction
    this->_direction_pins[0] = up_pin;
    this->_direction_pins[1] = left_pin;
    this->_direction_pins[2] = down_pin;
    this->_direction_pins[3] = right_pin;

    // Set pins as inputs - active low
    for(uint8_t i = 0; i < 4; i++){
        pinMode(_direction_pins[i], INPUT_PULLUP);
    }

    this->matrixDisp = new MatrixDisplay(rowPinArray, latchPin);
    this->loadIntroScreen();

    this->skipTailInc = 0;
}

void Game::loadIntroScreen()
{
    // Load the snake intro screen - "S" on  LED matri
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

void Game::newFood(){
    this->food->newLocation();
    do
    {
        this->food->newLocation();
    } while (this->matrixDisp->getPixelValue(this->food->x, this->food->y));
    
    // Check food isn't colliding with snake
}

void Game::moveSnake(){
    // Store location of tail location before incrementing
    // This is necessary to turn off the previous tail pixel moving the snake
    uint8_t temp_x = this->snake->tail->x; 
    uint8_t temp_y = this->snake->tail->y;

    // If tail == food last move, skip tail increment this move
    if(this->skipTailInc){
        this->snake->move(1);
        this->skipTailInc = 0;
    }
    // If tail == food, skip tail increment next move
    else if(this->snake->food_queue->x == this->snake->tail->x
        && this->snake->food_queue->y == this->snake->tail->y){
            this->snake->move(0);
            this->matrixDisp->setPixel(temp_x, temp_y, 0);
            this->skipTailInc = 1;
    }
    // Otherwise just move the snake
    else{
        this->snake->move(0);
        this->matrixDisp->setPixel(temp_x, temp_y, 0);
    }
    this->matrixDisp->setPixel(this->snake->head->x, this->snake->head->y, 1);
    
    // Check to see if Snake just ate
    if(this->snake->head->x == this->food->x
        && this->snake->head->y == this->food->y){
            // If just ate, enqueue food
            this->snake->enqueueFood();
            // Generate new food
            this->food->newLocation();
            // Set new food pixel high on display
            this->matrixDisp->setPixel(this->food->x, this->food->y, 1);
    }
}

void Game::checkDirection(){
    // Check status of control pins
    for(uint8_t i = 0; i < 4; i++){
        if(digitalRead(_direction_pins[i]) == LOW){
            this->snake->head->direction = i;
        }
    }
}