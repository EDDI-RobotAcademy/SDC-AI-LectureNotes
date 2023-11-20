#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random.h"

void random_config(void)
{
    srand(time(NULL));
}

int generate_random_from_min_to_max(const int min, const int max)
{
    return rand() % (max - min + 1) + min;
}