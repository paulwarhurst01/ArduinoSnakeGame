#include <Arduino.h>

#include "classSnakeNode.h"

SnakeNode::SnakeNode(uint8_t node_type, uint8_t x, uint8_t y, uint8_t direction)
{
    // Constructor
    this->node_type = node_type;
    this->x = x;
    this->y = y;
    this->direction = direction;
}

void SnakeNode::increment(){
    // Moves the nodes of the snake according to direction
    switch (this->direction)
    {
    case 1:
        if(this->y < 7){
            this->y += 1;
        }
        else{
            this->y = 0;
        }
        break;
    case 2:
        if(this->x >= 0){
            this->x += 1;
        }
        else{
            this->x = 7;
        }
        break;
    case 3:
        if(this->y <= 0){
            this->y += 1;
        }
        else{
            this->y = 7;
        }
        break;
    case 4:
        if(this->x < 7){
            this->x += 1;
        }
        else{
            this->x = 0;
        }
        break;
    
    default:
        break;
    }
}