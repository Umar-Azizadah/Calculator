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

void test_add_positive_numbers_and_negative_numbers(void){
    TEST_ASSERT_EQUAL(1, add(5,-4)); //expect 5 + -4 =1
}

void test_add_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-7,add(-3,-4)); //expect -3 + -4 = -7
}

//NOTE we can do multiple validations in one test
void test_add_zero(void) {
    TEST_ASSERT_EQUAL(10,add(10, 0)); //expect 10 + 0 = 10
    TEST_ASSERT_EQUAL(0,add(0,0)); //expect 0 + 0 = 10
}

int main (void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_positive_numbers);// run the rest function
    RUN_TEST(test_add_positive_numbers_and_negative_numbers);
    RUN_TEST(test_add_negative_numbers);
    RUN_TEST(test_add_zero);
    return UNITY_END();
}