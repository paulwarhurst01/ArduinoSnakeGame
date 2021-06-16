#ifndef Snake_h
#define Snake_h

#include <Arduino.h>
#include <classSel.h>

class Snake
{
    public:
        Snake();
        void moveSnake();
        void changeDirection();
        void updateDisplay();
        struct SnakeNode *tail;
        struct SnakeNode *food;
        uint8_t snake_length;
    private:
        SnakeNode* createNode(uint8_t node_type, uint8_t x, uint8_t y, uint8_t direction);
        void insertBend(uint8_t x, uint8_t y, uint8_t direction);
        void removeNode();
        void enqueue_food(uint8_t x, uint8_t y);
        void dequeue_food();

};

#endif