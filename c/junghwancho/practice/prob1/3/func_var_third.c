// 실수 하나를 입력받아 소수점만 분리하고 또 정수 부분만 분리하는 함수를 작성하시오 (함수 총 2개를 작성하면됨)
// 1. input = float
// 2. 소숫점 분리 계산
// 3. 정수 분리 계산
#include <stdio.h>
#include "func_var_third.h"

float separate_decimal(float num1)
{
    return num1 - (int)num1; // 어떻게 작동하는 함수 ?
}

int separate_int(float num1)
{
    return num1;
}
