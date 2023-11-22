#include <stdio.h>

#include "third_prob.h"

void seperate_integer_and_decimals(float num)
{
    printf("입력받은 실수는 %.2f입니다.\n", num);

    int index = -101;
    int integral_part;
    while ((num - index) > 1)
    {
        index++;
    }

    integral_part = index + 1;

    printf("정수부분 = %d\n", integral_part);
    printf("소수부분 = %.2f\n", num-integral_part);
}