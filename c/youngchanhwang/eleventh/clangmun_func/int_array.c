#include "int_array.h"
#include <stdio.h>


void print_array(int *array, int arraylength)
{
    int i;
    for(i = 0 ; i < arraylength ; i++)
    {
        printf("arrayf[%d] = %d\n", i , array[i*2]);
    }
}

int array_sum(void)
{
    int i, sum;
    sum = 0;
    int array[5];
    for(i = 0 ; i < 5 ;i ++)
    {
        array[i] = i; 
    }
    for(i = 0 ; i < 5 ; i ++)
    {
        sum += array[i];
    }
    return sum;
}