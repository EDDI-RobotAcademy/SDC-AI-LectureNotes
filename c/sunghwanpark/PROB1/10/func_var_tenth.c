#include "func_var_tenth.h"

// 10. and, or, xor, not 동작 방식에 대해 기술하고
//     예를 들어서 각각을 연산해보도록 하자! 

int and_test(int num1,int num2)
{
    return num1 & num2;
}

int or_test(int num1,int num2)
{
    return num1 || num2;
}

int xor_test(int num1,int num2)
{
    return num1 ^ num2;
}

int not_test(int num1)
{
    return ~num1;
}