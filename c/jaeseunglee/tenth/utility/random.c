#include <stdlib.h>
#include <time.h>

#include "random.h"


void config_random_seed(void)
{
    srand(time(NULL));
}


int generate_random_min_to_max(const int min, const int max)
{
    return rand() % (max - min + 1) + min;
}