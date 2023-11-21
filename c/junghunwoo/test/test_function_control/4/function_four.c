#include "function_four.h"
#include <stdio.h>


void sum_multiple_other(int num1, int num2)
{
    int i;
    int sum = 0;

    for (i = num1; i<=1000; i++)
    {
        if (i % num1 == 1 || i % num2 == 1)
        {
            sum += i;
        }
    }
    printf("1부터 1000까지 %d이나 %d의 나머지가 1인 값의 합은 %d입니다.\n", num1, num2, sum);
}