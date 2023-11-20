#include <stdio.h>

#include "remainder_one.h"

void remainder_one(int limit_number, int a, int b)
{
    int remainder_one = 1;
    int sum_of_numbers_by_a = 0;
    int sum_of_numbers_by_b = 0;
    int i, j;
    
    for (i = 0; i <= (limit_number / a); i++)
    {
        sum_of_numbers_by_a += (a * i + remainder_one);
    }
    
    for (j = 0; j <= (limit_number / b); j++)
    {
        sum_of_numbers_by_b += (b * j + remainder_one);
    }
    
    printf("%d이하의 양수 중 %d로 나눴을 때 나머지가 1인 수의 합 = %d\n", limit_number, a, sum_of_numbers_by_a);
    printf("%d이하의 양수 중 %d로 나눴을 때 나머지가 1인 수의 합 = %d\n", limit_number, b, sum_of_numbers_by_b);
    printf("최종 결과 = %d\n", sum_of_numbers_by_a + sum_of_numbers_by_b);
}