#include <Arduino.h>

#include "classSnakeNode.h"

SnakeNode::SnakeNode(uint8_t node_type, uint8_t x, uint8_t y, uint8_t direction)
{
    this->node_type = node_type;
    this->x = x;
    this->y = y;
    this->direction = direction;
}