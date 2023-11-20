#include "func_var_third.h"
//3. 실수 하나를 입력받아 소수점만 분리하고 또 정수 부분만 분리하는 함수를 작성하시오
// (함수 총 2개를 작성하면됨)

float return_float_from_float (float number)
{
    return number - (int)number;
}

int return_int_from_float(float number)
{
    return number;
}