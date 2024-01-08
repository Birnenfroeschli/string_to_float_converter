#include "../include/string_to_float.h"

//Function Prototype
int main()
{
    char your_string[100];

    /*
    //User Input
    printf("Please enter your string: ");
    scanf("%s", your_string);
    printf("Your entered string is: %s\n", your_string);*/
    double test = 0;
    string_to_float("0.123", &test); 
    printf("test: %f\n", test);

    return 0;
}
