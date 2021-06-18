#include <Arduino.h>
#include <unity.h>

#include "classSnake.h"
#include "classSnakeNode.h"

void setUp(void){
}

void tearDown(void){
    
}

void test_snake_constructor(){
    Snake testSnake;
    // Test food is null
    TEST_ASSERT_NULL(testSnake.food_queue);
    TEST_ASSERT_NULL(testSnake.latest_bend)
    // Testing tail construction
    TEST_ASSERT_EQUAL_UINT8(0, testSnake.tail->node_type);
    TEST_ASSERT_EQUAL_UINT8(4, testSnake.tail->x);
    TEST_ASSERT_EQUAL_UINT8(6, testSnake.tail->y);
    TEST_ASSERT_EQUAL_UINT8(0, testSnake.tail->direction);
    // Test head construction
    TEST_ASSERT_EQUAL_UINT8(1, testSnake.head->node_type);
    TEST_ASSERT_EQUAL_UINT8(4, testSnake.head->x);
    TEST_ASSERT_EQUAL_UINT8(4, testSnake.head->y);
    TEST_ASSERT_EQUAL_UINT8(0, testSnake.head->direction);
    // Confirm head linkage
    SnakeNode *head = testSnake.tail->next;
    TEST_ASSERT_EQUAL_UINT8(1, head->node_type);
    TEST_ASSERT_EQUAL_UINT8(4, head->x);
    TEST_ASSERT_EQUAL_UINT8(4, head->y);
    TEST_ASSERT_EQUAL_UINT8(0, head->direction);    
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
