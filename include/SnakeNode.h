// Snake list item
// Note, this definition makes it public, i.e. internal functions are not necessary
//      to modify the internal values.
// No need for a source file to protect contents.

#ifndef SnakeNode_h
#define SnakeNode_h

typedef struct SnakeNode
{
    /* data */
    int node_type;      // 0 = tail, 1 = head, 2 = bend
    int x;              // x coord of entity
    int y;              // y coord of entity
    int direction;      // 1 - Up, 2 - Left, 3 - Down, 4 - Right
    SnakeNode *next;    // 

} SnakeNode;

#endif