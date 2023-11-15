#include "random.h"

#include "time.h"
#include "stdlib.h"

void config_random_seed(void)
{
    srand(time(NULL));
}
int generate_random(const int min, const int max)
{
    return rand() % (max - min +1) + min;
}
