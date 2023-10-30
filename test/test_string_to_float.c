//TODO
#include "../include/unity.h"
#include "../include/string_to_float.h"


double test = 0;

void setUp(void)
{
}


void tearDown(void)
{
}


//Our tests

void parse_positive_integers()
{
    double test = 0;
    TEST_ASSERT_TRUE(string_to_float("10", &test));
}

void is_double()
{
    double test = 0;
    string_to_float("10", &test);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(test, 10., "Converted string is not equal to 10");  

    string_to_float("0", &test);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(test, 0., "Converted string is not equal to 0");  

    string_to_float("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999", &test);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(test, 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999., "Converted string is not equal to whatever garbadge it was you entered");
}


void handle_invalid_inputs()
{
    double test = 0;
    TEST_ASSERT_FALSE(string_to_float("abc", &test));
    TEST_ASSERT_FALSE(string_to_float("12a23", &test));
}


void floating_points_0()
{
    TEST_ASSERT_TRUE(string_to_float("12.12", &test));
    test = 12.12;
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(12.12, test, "Converted string is not equal to 12.12"); 
}

void floating_points_1()
{
    TEST_ASSERT_TRUE(string_to_float("0.123", &test));
    test = 0.123;
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.123, test, "Converted string is not equal to 0.123"); 
}

void floating_points_2()
{
    TEST_ASSERT_TRUE(string_to_float("12.123", &test));
    test = 12.123;
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(12.123, test, "Converted string is not equal to 12.123");  
}

void floating_points()
{
    test = 0;
    printf("Adress: %p\n", &test);
    printf("Value: %lf\n", test);

    string_to_float("12.12", &test);
    

    printf("Adress: %p\n", &test);
    printf("Value: %lf\n", test);

    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(12.12, test, "Converted string is not equal to 12.12"); 

    TEST_ASSERT_TRUE(string_to_float("0.123", &test));
    test = 0.123;
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.123, test, "Converted string is not equal to 0.123"); 

    TEST_ASSERT_TRUE(string_to_float("12.123", &test));
    test = 12.123;
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(12.123, test, "Converted string is not equal to 12.123");  
}

void parse_incomplete_floating_point()
{
    TEST_ASSERT_TRUE(string_to_float("12.", &test));
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(test, 12., "Converted string is not equal to 12.");  

    TEST_ASSERT_TRUE(string_to_float(".12", &test));
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(test, 0.12, "Converted string is not equal to 0.12");  
}
/*

void evaluate_signs()
{
    TEST_ASSERT_TRUE(string_to_float());
}
*/

//Our main test
int main()
{
    UNITY_BEGIN();
    //RUN_TEST(parse_positive_integers);
    //RUN_TEST(is_double);
    //RUN_TEST(handle_invalid_inputs);
    RUN_TEST(floating_points_0);
    RUN_TEST(floating_points_1);
    RUN_TEST(floating_points_2);
    RUN_TEST(floating_points);
    //RUN_TEST(parse_incomplete_floating_point);
    return UNITY_END();
}
