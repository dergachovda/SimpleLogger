#include "unity.h"

void setUp(void) {
    // Set up code here
}

void tearDown(void) {
    // Tear down code here
}

void test_HelloWorld(void) {
    TEST_ASSERT_EQUAL(1, 1);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_HelloWorld);
    return UNITY_END();
}