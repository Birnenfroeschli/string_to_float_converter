/*
 * Authors:     Deborah Schrag
 *              Lukas Marti
 * 
 * Testing file used to validate string_to_float function
 * Exercis in unit testing
 */
#include "unity.h"
#include "string_to_float.h"


void setUp(void)
{
}


void tearDown(void)
{
}

// Test for number inputs
void parse_positive_integers()
{
    double test = 0;
    TEST_ASSERT_TRUE(string_to_float("10", &test));
    TEST_ASSERT_TRUE(string_to_float("83427", &test));
    TEST_ASSERT_TRUE(string_to_float("2", &test));
}

// Test for simple number conversion, without any additional characters
void is_double()
{
    double test = 0;
    string_to_float("10", &test);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(test, 10., "Converted string is not equal to 10");  

    string_to_float("0", &test);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(test, 0., "Converted string is not equal to 0");  

    string_to_float("999999", &test);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(test, 999999., "Converted string is not equal to 999999");
}

// Test for throwing errors when including unwanted characters or signs in the
// wrong place
void handle_invalid_inputs()
{
    double test = 0;
    TEST_ASSERT_FALSE(string_to_float("abc", &test));
    TEST_ASSERT_FALSE(string_to_float("12a23", &test));
    TEST_ASSERT_FALSE(string_to_float("45+", &test));
    TEST_ASSERT_FALSE(string_to_float(".-4", &test));
}

// Testing numbers with decimal points
void floating_points()
{
    double test = 0;
    TEST_ASSERT_TRUE(string_to_float("12.12", &test));
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(12.12, test, "Converted string is not equal to 12.12"); 

    TEST_ASSERT_TRUE(string_to_float("0.123", &test));
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.123, test, "Converted string is not equal to 0.123"); 

    TEST_ASSERT_TRUE(string_to_float("12.123", &test));
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(12.123, test, "Converted string is not equal to 12.123");  
}

// Testing incomplete numbers with decimal point
void parse_incomplete_floating_point()
{
    double test = 0;
    TEST_ASSERT_TRUE(string_to_float("12.", &test));
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(test, 12., "Converted string is not equal to 12.");  

    TEST_ASSERT_TRUE(string_to_float(".12", &test));
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(test, 0.12, "Converted string is not equal to 0.12");  
}

// Testing numbers with explicit positive signs
void evaluate_positive_signs()
{
    double test = 0;
    TEST_ASSERT_TRUE(string_to_float("+12.12", &test));
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(12.12, test, "Converted string is not equal to +12.12"); 

    TEST_ASSERT_TRUE(string_to_float("+.123", &test));
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.123, test, "Converted string is not equal to +0.123"); 

    TEST_ASSERT_TRUE(string_to_float("+124.123", &test));
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(124.123, test, "Converted string is not equal to +12.123"); 
}

// Testing numbers with negative signs
void evaluate_negative_signs()
{
    double test = 0;
    TEST_ASSERT_TRUE(string_to_float("-12.12", &test));
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(-12.12, test, "Converted string is not equal to -12.12"); 

    TEST_ASSERT_TRUE(string_to_float("-0.123", &test));
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(-0.123, test, "Converted string is not equal to -0.123"); 

    TEST_ASSERT_TRUE(string_to_float("-.123", &test));
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(-0.123, test, "Converted string is not equal to -0.123"); 
}


// main test
int main()
{
    UNITY_BEGIN();
    RUN_TEST(parse_positive_integers);
    RUN_TEST(is_double);
    RUN_TEST(handle_invalid_inputs);
    RUN_TEST(floating_points);
    RUN_TEST(parse_incomplete_floating_point);
    RUN_TEST(evaluate_positive_signs);
    RUN_TEST(evaluate_negative_signs);
    return UNITY_END();
}
