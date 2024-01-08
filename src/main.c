#include "string_to_float.h"

//Function Prototype
int main()
{
    double test = 0;
    string_to_float("-8.", &test); 
    printf("test: %f\n", test);

    return 0;
}
