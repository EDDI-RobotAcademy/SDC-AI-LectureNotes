#include "random_number_generator.h"
#include <time.h>

void random_seed_config(void)
{
    srand(time(NULL));
}

int random_generate(const int min, const int max)
{
    return rand() % (max - min + 1) + min;
}

float float_random_generate(const int float_min, const int float_max)
{
    return rand() % (float_max - float_min + 1) + float_min;
}
