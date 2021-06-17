#include <Arduino.h>
#include <unity.h>

#include "classSnake.h"
#include "structSnakeNode.h"

void setUp(void){
}

void tearDown(void){
    
}

void test_snake_constructor(){
    Snake testSnake;
    //uint8_t x1 = 1, x2 = 2, y1 = 1, y2 = 2;
    //TEST_ASSERT_NULL(testSnake.food->next);
    testSnake.enqueueFood(2, 2);
    TEST_ASSERT_EQUAL_UINT8(2, (testSnake.food->x));
    /*TEST_ASSERT_EQUAL(0, testSnake.food->y);
    TEST_ASSERT_EQUAL(5, testSnake.food->direction);
    TEST_ASSERT_EQUAL(0, testSnake.food->node_type);*/
}

void test_enqueue_dequeque(){
/*    Snake testSnake;
    testSnake.enqueueFood(0, 0);
    testSnake.enqueueFood(1, 1);
    SnakeNode *temp = testSnake.food->next;
    TEST_ASSERT_EQUAL_UINT8(1, temp->x);
    TEST_ASSERT_EQUAL_UINT8(1, temp->y);
    testSnake.dequeueFood();
    TEST_ASSERT_EQUAL_UINT8(1, testSnake.food->x);
    TEST_ASSERT_EQUAL(1, testSnake.food->y);
*/}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(test_snake_constructor);
    RUN_TEST(test_enqueue_dequeque);
    UNITY_END();

    return 0;
}
