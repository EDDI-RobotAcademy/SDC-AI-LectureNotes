#include "function_three.h"
#include <stdio.h>


void sum_multiple(int num)
{
    int i;
    int sum = 0;

    for (i = 1; i<=1000; i++)
    {
        if (i % num == 0)
        {
            sum += i;
        }
    }
    printf("1부터 1000까지 %d의 배수의 합은 %d입니다.\n", num, sum);
}