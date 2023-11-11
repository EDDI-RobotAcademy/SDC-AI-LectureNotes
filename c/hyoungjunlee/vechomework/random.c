#include "random.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void random_seed_config(void)
{
    srand(time(NULL));
}