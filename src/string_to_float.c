#include "string_to_float.h"

bool string_to_float(const char *str, double *d)
{
    int8_t i = 0;
    int8_t num_array[100] = {0};
    int8_t sign = 1;
    int8_t point_pos = 0;
    int8_t pos = 0;
    int8_t j = 0;
    double result = 0;

    if(str[0] == '+')
    {
        i = 1;
    }
    if(str[0] == '-')
    {
        i = 1;
        sign = -1;
    }

    // Writing numerical values into array
    while(str[i] != '\0')
    {   
        if (str[i] >= '0' && str[i] <= '9' )
        {
            num_array[i-pos] = str[i] - '0'; // Subtracting ASCII '0' to get numerical value
        }
        else if (str[i] == '.')
        {
            point_pos = i-1;   
            pos++; 
        }
        else
        {
            printf("Please enter a valid string\n");
            return false;
        }
        i++;
    }
    i--;
    
    // Adding the numerical array to single double
    if(pos == 0)
    {
        j = i;
        while(i >= 0)
        {
            result += num_array[i]*pow(10, j-i);
            i--;
        }
    }
    else if (pos != 0)
    {
        j = point_pos;
        while(i >= 0)
        {
            result += num_array[i]*pow(10, j-i);
            i--;
        }
    }
    else 
    {
        result = 0;
    }
    result *= sign;
    *d = result;
    return true;
}