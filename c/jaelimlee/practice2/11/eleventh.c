// 11번 문제: 아무런 구조체 대충 하나 만들고 내부에 값을 할당하여 출력

#include "eleventh.h"
#include <stdio.h>

int add_Print(integer_result result)
{
    result.a = 3;
    result.b = 7.7; 
    int sum = result.a + (int)result.b;

    printf("3과 7.7을 더하면: %d\n", sum);
    //return sum;

}