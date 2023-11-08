#include "random.h"
#include <stdlib.h>

int generate_random(const int min, const int max)
{
	return rand() % (max - min + 1) + min;
}