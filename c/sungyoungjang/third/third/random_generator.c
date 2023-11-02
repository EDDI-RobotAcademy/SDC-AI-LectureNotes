#include <stdlib.h>
#include "random_generator.h"

int generate_random(const int min, const int max)
{
	return rand() % (max - min + 1) + min;
}