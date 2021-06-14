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
        int snake_length;
    private:
        SnakeNode* createNode(int node_type, int x, int y, int direction);
        void insertBend(int x, int y, int direction);
        void removeNode();

};

#endif