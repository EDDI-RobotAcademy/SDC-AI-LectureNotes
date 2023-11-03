#include <stdlib.h>
#include <time.h>
#include "generate_random.h"

int generate_random1(const int min, const int max)
{
	srand(time(NULL));
	
	return rand() % (max - min + 1) + min;
}

int generate_random2(const int min, const int max)
{
	srand(time(NULL));

	return rand() % (max - min + 1) + min;
}