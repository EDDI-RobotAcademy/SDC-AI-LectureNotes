#include "rand.h"

#include <time.h>
#include <stdlib.h>

void random_config(void)
{
	srand(time(NULL));
}

int get_random_from_min_to_max(int min, int max)
{
	return max - min;
}