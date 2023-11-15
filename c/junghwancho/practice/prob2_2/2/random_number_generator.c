#include "random_number_generator.h"
#include <time.h>

void random_seed_config(void)
{
    srand(time(NULL));
}

int random_generate(const int min, const int max)
{
    return rand() % (max - min + 1) + min;
}
