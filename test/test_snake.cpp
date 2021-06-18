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
    TEST_ASSERT_NULL(testSnake.latest_bend);
    // Testing tail construction
    TEST_ASSERT_EQUAL_UINT8(0, testSnake.tail->node_type);
    TEST_ASSERT_EQUAL_UINT8(4, testSnake.tail->x);
    TEST_ASSERT_EQUAL_UINT8(6, testSnake.tail->y);
    TEST_ASSERT_EQUAL_UINT8(0, testSnake.tail->direction);
    // Test head construction
    TEST_ASSERT_EQUAL_UINT8(1, testSnake.head->node_type);
    TEST_ASSERT_EQUAL_UINT8(4, testSnake.head->x);
    TEST_ASSERT_EQUAL_UINT8(4, testSnake.head->y);
    TEST_ASSERT_EQUAL_UINT8(1, testSnake.head->direction);
    TEST_ASSERT_NULL(testSnake.head->next);
    // Confirm head linkage
    SnakeNode *head = testSnake.tail->next;
    TEST_ASSERT_NULL(head->next);
    TEST_ASSERT_EQUAL_UINT8(1, head->node_type);
    TEST_ASSERT_EQUAL_UINT8(4, head->x);
    TEST_ASSERT_EQUAL_UINT8(4, head->y);
    TEST_ASSERT_EQUAL_UINT8(1, head->direction);    
}

void test_enqueue_dequeque(){
    Snake testSnake;
    testSnake.changeDirection(2);
    TEST_ASSERT_EQUAL_UINT8(2, testSnake.head->direction);
    // Confirm latest_bend pointer initialised
    TEST_ASSERT_NOT_NULL(testSnake.latest_bend);
    TEST_ASSERT_EQUAL_UINT8(2, testSnake.tail->next->node_type);
    TEST_ASSERT_NULL(testSnake.head->next);
    TEST_ASSERT_EQUAL_UINT8(1, testSnake.tail->next->next->node_type);
}

int main(int argc, char **argv)
{
    Snake testSnake;
    UNITY_BEGIN();
    RUN_TEST(test_snake_constructor);
    RUN_TEST(test_enqueue_dequeque);
    UNITY_END();

    return 0;
}
