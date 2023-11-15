#include "int_random_generate.h"

#include <stdlib.h>
#include <time.h>

void int_config_random_seed(void)
{
    srand(time(NULL));
}

int int_generate_random(const int int_min, const int int_max)
{
    return rand() % (int_max - int_min + 1) + int_min;
}