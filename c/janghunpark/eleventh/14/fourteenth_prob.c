#include <stdio.h>

#include "fourteenth_prob.h"

void check_larger_number_and_print_result(int num1, int num2)
{
    printf("num1 = %d, num2 = %d\n", num1, num2);

    if (num1 > num2)
    {
        printf("1번 숫자가 더 큽니다!\n");
    }
    else if (num1 < num2)
    {
        printf("2번 숫자가 더 큽니다!\n");
    }
    else
    {
        printf("두 숫자는 같습니다!\n");
    }
}