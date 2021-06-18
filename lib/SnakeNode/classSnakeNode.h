// Snake list item
// Note, this definition makes it public, i.e. internal functions are not necessary
//      to modify the internal values.
// No need for a source file to protect contents.

#ifndef SnakeNode_h
#define SnakeNode_h

#include <Arduino.h>

class SnakeNode
{
    public:
        SnakeNode(uint8_t node_type, uint8_t x, uint8_t y, uint8_t direction);
        uint8_t node_type;      // 0 = tail, 1 = head, 2 = bend
        uint8_t x;              // x coord of entity
        uint8_t y;              // y coord of entity
        uint8_t direction;      // 1 - Up, 2 - Left, 3 - Down, 4 - Right
        SnakeNode *next;        // Pointer to the next node in the list

        // Functions        
};

#endif