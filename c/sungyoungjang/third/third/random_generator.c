#include <stdlib.h>
#include "random_generator.h"

int generate_random(const int max, const int min)
{
	return rand() % (max - min + 1) + min;
}