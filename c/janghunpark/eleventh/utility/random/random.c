#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

void random_config(void)
{
    srand((unsigned)time(NULL));
}

int generate_random_integer(const int min, const int max)
{
    return rand() % (max - min + 1) + min;
}

float generate_random_realnumber(const int min, const int max)
{
    return rand() % (max - min + 1) + min + 
        ((double)((rand() % 10000))) / 10000;
}
