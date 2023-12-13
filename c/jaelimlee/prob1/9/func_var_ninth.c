// Overflow와 Underflow가 어떤 경우에 나는지 기술

#include "func_var_ninth.h"

char test_overflow(char number)
{
    return ++number;
}

char test_underflow(char number)
{
    return --number;
}