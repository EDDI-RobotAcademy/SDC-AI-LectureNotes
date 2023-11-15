#include <time.h>
#include <stdlib.h>

#include "random.h"

void random_seed_config(void)
{
	srand(time(NULL));
}

int get_random_from_min_to_max(const int min, const int max)
{
	return rand() % (max - min + 1) + min;
}