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
    //testSnake.init();
    testSnake.enqueueFood(0, 0);
    TEST_ASSERT_EQUAL(0, testSnake.food->x);
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(test_snake_constructor);
    UNITY_END();

    return 0;
}
