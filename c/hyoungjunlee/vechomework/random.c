#include "random.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void random_seed_config(void)
{
    srand(time(NULL));
}
int generate_random_from_min_to_max(int min, int max)
{
    return rand()%(max-min+1) +min;
}