#include "tenth.h"
#include <stdio.h>

int integer_array_sum(int array[])
{
    int sum = 0;

    // 배열 크기 임의로 3 지정.
    for (int i = 0; i < COUNT_ARRAY_2; i++)
    {
        sum = sum + array[i];

    }
    return sum;
    
}