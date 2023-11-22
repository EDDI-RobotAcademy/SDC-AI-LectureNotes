#include <stdio.h>

#include "array_pointer.h"

void print_array_by_pointer(int *array_pointer)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d번 칸에 있는 값 = %d\n", i, array_pointer[i]);
    }
}

void print_sum_in_array_by_pointer(int *array_pointer)
{
    int sum = 0;

    for (int i = 0; i < 3; i++)
    {
        sum += array_pointer[i];
    }
    
    printf("배열 안 숫자 합계 = %d\n", sum);
}