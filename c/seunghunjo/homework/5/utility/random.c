#include "random.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void random_seed_config(void)
{
    srand(time(NULL));
}

int generate_random_form_min_to_max(const int min, const int max)
{
    return rand() % (max - min +1) + min;
}