#include "random.h"

#include <stdlib.h>
#include <time.h>


void coinfig_random_seed(void)
{
    srand(time(NULL));
}

int generate_random()
{
    return rand();
}