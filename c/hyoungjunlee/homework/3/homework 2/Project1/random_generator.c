#include <stdlib.h>
#include "random_generator.h"

int generate_random(int min,  int max)
{
	
	return rand() % (max - min + 1) + min;
	
	
}