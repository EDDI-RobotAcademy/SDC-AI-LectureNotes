#include <stdio.h>
#include <stdlib.h>
#include "seperation.h"

// 실수의 정수 부분만 출력
void integer_separation(double num)
{
    printf("정수 부분: %d\n", (int)num);
}

// 실수의 소숫점 부분만 출력
void decimal_point_separation(double num)
{
    printf("소수점 부분: %f\n", num - (int)num);
}