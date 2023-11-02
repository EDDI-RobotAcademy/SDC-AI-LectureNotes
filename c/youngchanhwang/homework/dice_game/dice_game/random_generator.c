#include <stdlib.h>
#include <time.h>

#include "random_generator.h"

int random_generate(const int min, const int max) 
{
	return rand() % (max - min + 1) + min;
}
