#ifndef Snake_h
#define Snake_h

#include <Arduino.h>
#include "classSnakeNode.h"

class Snake
{
    public:
        Snake();
        void moveSnake();
        void changeDirection(uint8_t direction);
        void enqueueFood(uint8_t x, uint8_t y);
        SnakeNode *tail;                // tail of the snake
        SnakeNode *latest_bend;         // Prevents traversing the whole linked list each time
        SnakeNode *head;                // Head of the snake
        SnakeNode *food_queue;          // Food the snake has eaten    
        uint8_t length;
    private:
        void enqueueBend();
        void dequeueBend();
        void dequeueFood();
};

#endif