#include <stdlib.h>
#include <time.h>
#include "generate_random.h"

int generate_random(const int min, const int max)
{
	srand(time(NULL));
	
	return rand() % (max - min + 1) + min;
}