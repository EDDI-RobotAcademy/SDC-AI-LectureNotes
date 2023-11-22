#include "random.h"

#include <stdlib.h>
#include <time.h>
#include <math.h>

void config_random_seed(void)
{
    srand(time(NULL));
}

int generate_random(const int min, const int max)
{
    return rand() % (max - min + 1) + min;
}

float generate_float_random(const int min, const int max, const int significant)
{
    // tmp_random = 1 ~ 100
    int tmp_random = rand() % (max - min + 1) + min;
    // 33, 77 -> 3300, 7700
    tmp_random *= pow(10, significant);

    return tmp_random / pow(10, significant);
}

#define BASE_TEN            10

int process_for_expression_float(const int int_number, const int significant)
{
    return int_number * pow(BASE_TEN, significant);
}

float generate_float_random_advanced(
    const int min, const int max, const int significant)
{
    // 100 ~ 10100
    int tmp_random = rand() % 
        (process_for_expression_float(max, significant) - 
        process_for_expression_float(min, significant) + 1) + 
        process_for_expression_float(min, significant);

    return tmp_random / pow(BASE_TEN, significant);
}