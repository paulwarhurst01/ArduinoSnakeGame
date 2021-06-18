#include <Arduino.h>

#include "classSnake.h"
#include "classSnakeNode.h"

Snake::Snake()
{   // Create the tail
    // Create new SnakeNode on heap
    SnakeNode *tail = new SnakeNode(0, 4, 6, 0);
    // Link snake node to tail
    this->tail = tail;
    // Create the head
    SnakeNode *head = new SnakeNode(1, 4, 4, 0);
    head->next = NULL;
    this->head = head;
    // Link the head as the next member to tail, bends will be inserted between the two
    // This allows one linked list to be sent to display
    tail->next = head;
}

/*void Snake::insertBend(uint8_t x, uint8_t y, uint8_t direction){
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
}*/