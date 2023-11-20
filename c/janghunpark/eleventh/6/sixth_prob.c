#include <stdio.h>
#include <math.h>

#include "sixth_prob.h"

int number_align_with_parameter(int base, int target_number)
{
    return target_number & ~((int)(pow(2, base)) - 1);
}