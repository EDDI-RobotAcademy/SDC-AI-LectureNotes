#include "i_wanna_return_float_random.h"
#include "../utility/random.h"

#include <stdio.h>

void print_float_random(void)
{
    printf("실수형 랜덤: %5.2f\n", 
        generate_float_random(REAL_MIN, REAL_MAX, SIGNIFICANT));

    printf("개선된 실수형 랜덤: %5.3f\n", 
        generate_float_random_advanced(REAL_MIN, REAL_MAX, SIGNIFICANT));
}