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
        SnakeNode **tail;
        int snake_length;
    private:
        SnakeNode **createNode(int node_type, int x, int y, int direction);
        void insertBend(SnakeNode **tail)
        void removeNode();

};

#endif