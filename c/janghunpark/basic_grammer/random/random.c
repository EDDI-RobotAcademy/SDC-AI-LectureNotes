#include <stdio.h>
#include <time.h>

#include "random.h"

void random_config(void)
{
    srand(time(NULL));
}

int generate_random_number(int a, int b)
{
    return rand() % (b - a + 1) + a;
}