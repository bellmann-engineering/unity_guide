#include "unity.h"

// The function to test
int add(int a, int b) {
    return a + b;
}

// This function will be called before each test case
void setUp(void) {
    a = 10;
    b = 5;
}

// This function will be called after each test case
void tearDown(void) {
    // You can add teardown logic here if needed
}

// Define a test case
void test_simple_addition() {
    int expected = 15;

    result = add(a, b);

    TEST_ASSERT_EQUAL_INT(expected, result);
}

int main() {
    UNITY_BEGIN();

    // Run the test case
    RUN_TEST(test_simple_addition);

    return UNITY_END();
}
