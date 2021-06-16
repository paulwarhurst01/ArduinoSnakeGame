#ifndef Snake_h
#define Snake_h

#include <Arduino.h>
#include "structSnakeNode.h"

class Snake
{
    public:
        Snake();
        void moveSnake();
        void changeDirection();
        void updateDisplay();
        void enqueueFood(uint8_t x, uint8_t y);
        SnakeNode *tail;
        SnakeNode *food;
        uint8_t length;
    private:
        SnakeNode* createNode(uint8_t node_type, uint8_t x, uint8_t y, uint8_t direction);
        void insertBend(uint8_t x, uint8_t y, uint8_t direction);
        void removeNode();
        void dequeueFood();
};

#endif