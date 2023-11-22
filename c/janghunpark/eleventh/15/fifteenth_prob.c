#include <stdio.h>

#include "fifteenth_prob.h"

float add(float a, float b)
{
    return a + b;
}

void print_integer_part(float number)
{
    int integer_part_index = 0;
    while (number > integer_part_index)
    {
        integer_part_index++;
    }
    int integer_part = integer_part_index - 1;
    printf("integer_part = %d\n", integer_part);
}