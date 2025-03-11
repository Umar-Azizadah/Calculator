#include "unity.h"
#include "calculator.h"

//optional but needs to be defined (runs BEFORE each test)
void setUp(void) {
    //initialize any recourses needed for the test here
    //for example, might reset a global value, dynamically alocate memory, etc
    //in this example, nothing is needed here
}

//optional but needs to be defined (runs AFTER each test)
void tearDown(void) {
    //clean up resources after each test
    //for example, free dynamically allocated memory, reset global values,etc
    //in this example, nothing is needed here
}

void test_add_positive_numbers(void){
    TEST_ASSERT_EQUAL(5, add(2,3)); //we expect 2+3=5
}

int main (void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_positive_numbers);// run the rest function
    return UNITY_END();
}