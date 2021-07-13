#ifndef Snake_h
#define Snake_h

#include <Arduino.h>
#include "classSnakeNode.h"

class Snake
{
    public:        
        SnakeNode *tail;                // tail of the snake
        SnakeNode *latest_bend;         // Prevents traversing the whole linked list each time
        SnakeNode *head;                // Head of the snake
        SnakeNode *food_queue;          // Food the snake has eaten    
        uint8_t length;

        Snake();
        void move(uint8_t skip_tail_inc);
        void changeDirection(uint8_t direction);
        void enqueueFood();
    private:
        void enqueueBend();
        void dequeueBend();
        void dequeueFood();
};

#endif