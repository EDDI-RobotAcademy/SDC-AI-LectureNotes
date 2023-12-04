#include "func_var_sixth.h"
#include <math.h>

int number_align_with_parameter(int base, int target_number)
{
    return target_number & ~((int)pow(2, base) - 1);
}