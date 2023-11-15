#include "random.h"

#include <stdlib.h>
#include <time.h>

void config_random_seed(void)
{
    srand(time(NULL));
}

int generate_random(const int min, const int max)
{
    return rand() % (max - min + 1) + min;
}
