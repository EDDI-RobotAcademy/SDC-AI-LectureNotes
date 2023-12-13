#include "practice15.h"
#include <stdio.h>

int add_Print(integer_result result)
{
    result.a = 3;
    result.b = 7.7; 
    int sum = result.a + (int)result.b;

    printf("3과 7.7을 더하면: %d\n", sum);
    //return sum;

}