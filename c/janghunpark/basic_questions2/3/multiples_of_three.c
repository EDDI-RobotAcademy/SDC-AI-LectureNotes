#include <stdio.h>

#include "multiples_of_three.h"

void addition_of_multiples_of_three(int limit_number)
{
    int index;
    int count = limit_number / 3;
    int final_number = 0;

    for (index = 1; index <= count; index++)
    {
        final_number += index * 3;
    }

    printf("%d 이하 3의 배수의 합은 %d 입니다!\n", limit_number, final_number);
}