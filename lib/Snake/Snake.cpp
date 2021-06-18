#include <Arduino.h>

#include "classSnake.h"
#include "classSnakeNode.h"

Snake::Snake()
{   // Create the tail
    // Create new SnakeNode on heap
    SnakeNode *tail = new SnakeNode(0, 4, 6, 0);
    // Link snake node to tail
    this->tail = tail;
    this->latest_bend = NULL;
    // Create the head
    SnakeNode *head = new SnakeNode(1, 4, 4, 1);
    head->next = NULL;
    this->head = head;
    // Link the head as the next member to tail, bends will be inserted between the two
    // This allows one linked list to be sent to display
    tail->next = head;
    // Initialise food_queue to NULL
    this->food_queue = NULL;
}

void Snake::changeDirection(uint8_t direction){
    if(this->head->direction != direction){
        this->head->direction = direction;
        this->enqueueBend();
    }
}

void Snake::enqueueBend()
{   
    // Adds coordinates of head turn as a bend snake node
    SnakeNode *bend = new SnakeNode(2, this->head->x, this->head->y, this->head->direction);
    bend->next = this->head;
    if(this->latest_bend == NULL) this->tail->next = bend;
    this->latest_bend = bend;
}

void Snake::dequeueBend(){
    // Remove bend as tail crosses it
    // Delete bend, ensuring it is a bend and not head is not deleted
    if(this->tail->next->next != NULL){
        SnakeNode *temp = this->tail->next->next;
        delete(this->tail->next);
        this->tail->next = temp;
    }
    // Prevents losing head from accidental call
}

void Snake::enqueueFood()
{
    SnakeNode *food = new SnakeNode(3, this->head->x, this->head->y, 0);

    if(food_queue == NULL){
        // If no food items exist, create one
        food->next = NULL;
        this->food_queue = food;
    }
    else{
        food = this->food_queue->next;
        food->next = this->food_queue->next;
        this->food_queue->next = food;
    }
}

void Snake::dequeueFood(){
    SnakeNode *temp = this->food_queue->next->next;
    delete(this->food_queue->next);
    this->food_queue->next = temp;
}