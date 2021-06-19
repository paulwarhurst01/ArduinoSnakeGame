#include <Arduino.h>

#include "classGame.h"
#include "classSnake.h"
#include "classSnakeNode.h"
#include "classMatrixDisplay.h"
#include "classFood.h"

Game::Game(){
}

Game::newFood(){
    this->food.newLocation();
    // Check food isn't colliding with snake
    if(this->x )
}
