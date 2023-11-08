#include <stdio.h>
#include "random_generator.h"


int dice()
{
	const int min = 1;
	const int max = 6;

	return generate_random(min, max);

}