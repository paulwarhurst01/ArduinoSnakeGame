#include <Arduino.h>

#include "classSnake.h"
#include "structSnakeNode.h"

Snake::Snake()
{
    // Linked list that defines what snake looks like on display
    //struct SnakeNode 
    tail = createNode(0, 4, 6, 0);
    //tail = createNode(0, 4, 6, 0);
    // Create food linked list
    //struct SnakeNode *food;
    // Initially tail points directly to head, no body pieces in between
    tail->next = createNode(1, 4, 4, 0);
    length = 3;
}

SnakeNode* Snake::createNode(uint8_t node_type, uint8_t x, uint8_t y, uint8_t direction)
{
    struct SnakeNode* snake_node = (struct SnakeNode*) malloc(sizeof(SnakeNode));
    // Create if malloc successful
    if(snake_node != NULL){
        snake_node->node_type = node_type;
        snake_node->x = x;
        snake_node->y = y;
        snake_node->direction = direction;
        return snake_node;
    }
}

void Snake::insertBend(uint8_t x, uint8_t y, uint8_t direction){
    // Preserve address of head
    SnakeNode *head = tail->next;
    // Add bend
    tail->next = createNode(2, x, y, direction);
    // Link bend to head
    tail->next->next = head;
}

void Snake::enqueueFood(uint8_t x, uint8_t y)
{
    if(food == NULL){
        // If no food items exist, create one
        food = createNode(5, x, y, 5);
    }
    else{
        // Find end of queue to add new food item to end of queue
        SnakeNode* temp = food->next;
        while(temp != NULL){
            temp = temp->next;
        }
        temp->next = createNode(5, x, y, 5);
    }
}

void Snake::dequeueFood(){
    // Preserve next in queue before calling free()
    SnakeNode* temp = food->next;
    food = temp;
    free(temp);
}