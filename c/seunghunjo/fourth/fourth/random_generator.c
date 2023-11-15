#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random_generator.h"

void random_config(void)
{
	// NULL이 stdio.h에 정의되어 있음
	srand(time(NULL));
}
int generate_random(const int min, const int max)
{
	return rand() % (max - min + 1) + min;
}