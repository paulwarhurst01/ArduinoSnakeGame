#include <Arduino.h>

#include "classFood.h"

void Food::newLocation(){
    this->newXCoord();
    this->newYCoord();
}

void Food::newXCoord(){
    this->x = random(0, 7);
}

void Food::newYCoord(){
    this->y = random(0, 7);
}
