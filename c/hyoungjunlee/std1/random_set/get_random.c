#include <time.h>
#include "get_random.h"
#include <stdlib.h>

void random_seed(void)
{
    srand(time(NULL));
}
int get_random(void)
{
    return rand() % 10 + 2;
}