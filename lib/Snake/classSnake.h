#ifndef Snake_h
#define Snake_h

#include <Arduino.h>
#include "classSnakeNode.h"

class Snake
{
    public:
        Snake();
        void moveSnake();
        void changeDirection();
        void enqueueFood(uint8_t x, uint8_t y);
        void dequeueFood();
        SnakeNode *tail;        // tail of the snake
        SnakeNode *head;        // Head of the snake
        SnakeNode *food_queue;  // Food the snake has eaten    
        uint8_t length;
    private:
        //SnakeNode* createNode(uint8_t node_type, uint8_t x, uint8_t y, uint8_t direction);
        //void insertBend(uint8_t x, uint8_t y, uint8_t direction);
        //void removeNode();
};

#endif