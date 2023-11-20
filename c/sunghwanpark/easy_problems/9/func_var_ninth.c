#include "func_var_ninth.h"

// 9. Overflow와 Underflow는 어떤 경우에 나는지 기술하시오.

char test_overflow(char number)
{
    return ++number;
}

char test_underflow(char number)
{
    return --number;
}

