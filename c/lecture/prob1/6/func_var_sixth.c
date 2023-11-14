// x & ~(2의 y승 - 1)의 의미에 대해 서술하시오.
#include "func_var_sixth.h"
#include <math.h>

int number_align_with_parameter(int base, int target_number)
{
    return target_number & ~((int)(pow(2, base)) - 1);
}