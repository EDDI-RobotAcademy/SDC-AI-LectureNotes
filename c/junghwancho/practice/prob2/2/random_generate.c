#include <time.h>
#include <stdlib.h>
#include "random_generate.h"

void config_random_seed(void)
{
    srand(time(NULL));
}

int random_generate(const int min, const int max)
{
    return rand() % (max - min + 1) + min;
}