// and, or, xorm, not 동작 방식에 대해 기수롸고 예를 들어서 각각 연산
#include "func_var_tenth.h"

int and_data(int num1, int num2)
{
    return num1 & num2;
}

int or_data(int num1, int num2)
{
    return num1 | num2;
}

int xor_data(int num1, int num2)
{
    return num1 ^ num2;
}

int not_data(int num)
{
    return ~num;
}