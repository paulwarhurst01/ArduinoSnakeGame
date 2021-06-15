// Snake Entity List - SEL for short
#ifndef Sel_h
#define Sel_h

#include <SnakeNode.h>

class Sel
{
    public:
        void setupSnake();
        void addSeg();

    private:
        SnakeNode *_head;
        SnakeNode *_tail;
};

#endif