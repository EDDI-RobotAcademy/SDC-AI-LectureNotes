#include <time.h>
#include <stdlib.h>

#include "random.h"


void random_seed_config(void)
{
    srand(time(NULL));
}

int random_int(void)
{
    return rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
}
double random_double(void)
{
    return (double)(rand() % 100)/10;

}
