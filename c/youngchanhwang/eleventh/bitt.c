#include "bitt.h"

#include <stdio.h>

int num_bit(int num1, int num2)
{
    return num1 << num2 ;
}

void print_num_bit(int num1, int num2, int num_result)
{
    printf("%d << %d = %d\n", num1, num2 , num_result);
}