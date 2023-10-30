#include "../include/string_to_float.h"

bool string_to_float(const char *str, double *d)
{
    //Variable initialization
    int16_t i = 0;
    int16_t num_array[100];

    int point_pos = 0;
    int pos = 0;
    int j = 0;
    *d = 2601.1999;


    double result = 0;

    //Conversion
    //Fitting every member of our string as one member into an array
    while(str[i] != '\0')
    {   
        if (str[i] >= '0' && str[i] <= '9' )
        {
            num_array[i-pos] = str[i] - '0';
            //printf("Added to array: ");
        }

        else if (str[i] == '.')
        {
            //printf("You got a point.\n");
            point_pos = i-1;   
            pos++; 
        }

        else
        {
            printf("Please enter a valid string\n");
            return 0;
        }

        //printf("%d\n", num_array[i-pos]);
        i++;
    }

    i--;
    
    //Combining said array to double
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
    //printf("Ur result: %lf\n", result);

    //Writing result 
    *d = result;
    
    return 1;
    //Output
}