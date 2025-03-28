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

//add test cases
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
void test_add_overflow(void) {
    int result = add(INT_MAX,1); //should wrap arround or cause undefined behavior
    TEST_ASSERT_TRUE(result < 0); //this checks if overflow occured
}

void test_add_underflow(void) {
    int result = add(INT_MIN,-1); 
    TEST_ASSERT_TRUE(result > 0); //this checks if underflow occured
}

//subtract test cases 
void test_subtract_positive_numbers(void){
    TEST_ASSERT_EQUAL(1, subtract(3,2)); //we expect 3-2=1
}
void test_subtract_positive_numbers_and_negative_numbers(void){
    TEST_ASSERT_EQUAL(9, subtract(5,-4)); //expect 5 - -4 = 9
}
void test_subtract_negative_numbers(void) {
    TEST_ASSERT_EQUAL(1, subtract(-3,-4)); //expect -3 - -4 = 1
}
void test_subtract_zero(void) {
    TEST_ASSERT_EQUAL(10,subtract(10, 0)); //expect 10 - 0 = 10
    TEST_ASSERT_EQUAL(0,subtract(0,0)); //expect 0 - 0 = 10
}
void test_subtract_overflow(void) {
    int result = subtract(INT_MAX, -1); 
    TEST_ASSERT_TRUE(result < 0);
}

void test_subtract_underflow(void) {
    int result = subtract(INT_MIN, 1);  
    TEST_ASSERT_TRUE(result > 0); 
}


//multiply test cases 
void test_multiply_positive_numbers(void){
    TEST_ASSERT_EQUAL(6, multiply(3,2)); //we expect 3*2=6
}
void test_multiply_positive_numbers_and_negative_numbers(void){
    TEST_ASSERT_EQUAL(-20, multiply(5,-4)); //expect 5 * -4 = -20
}
void test_multiply_negative_numbers(void) {
    TEST_ASSERT_EQUAL(12, multiply(-3,-4)); //expect -3 * -4 = 12
}
void test_multiply_zero(void) {
    TEST_ASSERT_EQUAL(0,multiply(10, 0)); //expect 10 * 0 = 0
    TEST_ASSERT_EQUAL(0,multiply(0,0)); //expect 0 * 0 = 0
}
void test_multiply_overflow(void) {
    int result = multiply(INT_MAX, 2);
    TEST_ASSERT_TRUE(result < 0); 
}

void test_multiply_underflow(void) {
    int result = multiply(INT_MIN, -1); 
    TEST_ASSERT_TRUE(result < 0); 
}


//divide test cases
void test_divide_positive_numbers(void){
    TEST_ASSERT_EQUAL(2, divide(4,2)); //we expect 4/2=2
}
void test_divide_positive_numbers_and_negative_numbers(void){
    TEST_ASSERT_EQUAL(-4, divide(8,-2)); //expect 8 / -2 = -4
}
void test_divide_negative_numbers(void) {
    TEST_ASSERT_EQUAL(3, divide(-12,-4)); //expect -12 / -4 = 3
}
void test_divide_zero(void) {
    TEST_ASSERT_EQUAL(0,divide(10, 0)); //expect 10 / 0 = 0
    TEST_ASSERT_EQUAL(0,divide(0,0)); //expect 0 / 0 = 0
}
void test_divide_overflow(void) {
    int result = divide(INT_MIN, -1);
    TEST_ASSERT_TRUE(result > 0); 
}


int main (void) {
    UNITY_BEGIN();
    //run add tests
    RUN_TEST(test_add_positive_numbers);
    RUN_TEST(test_add_positive_numbers_and_negative_numbers);
    RUN_TEST(test_add_negative_numbers);
    RUN_TEST(test_add_zero);
    RUN_TEST(test_add_overflow);
    RUN_TEST(test_add_underflow);

    //run subtract tests
    RUN_TEST(test_subtract_positive_numbers);
    RUN_TEST(test_subtract_positive_numbers_and_negative_numbers);
    RUN_TEST(test_subtract_negative_numbers);
    RUN_TEST(test_subtract_zero);
    RUN_TEST(test_subtract_overflow);
    RUN_TEST(test_subtract_underflow);

    //run multiply tests
    RUN_TEST(test_multiply_positive_numbers);
    RUN_TEST(test_multiply_positive_numbers_and_negative_numbers);
    RUN_TEST(test_multiply_negative_numbers);
    RUN_TEST(test_multiply_zero);
    RUN_TEST(test_multiply_overflow);
    RUN_TEST(test_multiply_underflow);

    //run divide tests
    RUN_TEST(test_divide_positive_numbers);
    RUN_TEST(test_divide_negative_numbers);
    RUN_TEST(test_divide_positive_numbers_and_negative_numbers);
    RUN_TEST(test_divide_zero);
    RUN_TEST(test_divide_overflow);

    

    return UNITY_END();
}