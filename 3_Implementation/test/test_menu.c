#include "../inc/menu.h"
#include "../unity/unity.h"
//#include "../../menu.c"
/* Name of the header file of your project */

/* These two lines are need to be set according to project name */
// #include <function.h>
#define PROJECT_NAME "Menu"

float getDiscount(float total, float discountPercent)
{
    float discount = ((100 - discountPercent) / 100) * total;
    return discount;
}

/* Prototype / Function Declaration */
// Write all the function defined in the program.

void test_getDiscount();
void test_getDiscountNotEqual();

/* Required by the unity test framework */

void setUp() {}

/* Required by the unity test framework */

void tearDown() {}

/* Start of the application test */

// Write the code for testing.

int main()
{
    /* Initiate the Unity Test Framework (Initiation) */

    UNITY_BEGIN();

    /*Now Run the Test function*/
    /* Means write the fucntion name for testing */

    RUN_TEST(test_getDiscount);
    RUN_TEST(test_getDiscountNotEqual);

    /* Close the Unity Test Framework */
    return UNITY_END();
}

/* Write all the test functions. */
/* Here we have to write all the test cases means values for the program input that program is taking proper input and giving the desired result or not! */

void test_getDiscount()
{
    float total = 100;
    float discountPercent = 10;
    float discount = getDiscount(total, discountPercent);
    float expectedAfterDiscount = 90.0;
    TEST_ASSERT_EQUAL(discount, expectedAfterDiscount);
}

void test_getDiscountNotEqual()
{
    float total = 100;
    float discountPercent = 10;
    float discount = getDiscount(total, discountPercent);
    float expectedAfterDiscount = 80.0;
    TEST_ASSERT_FALSE(discount == expectedAfterDiscount);
}