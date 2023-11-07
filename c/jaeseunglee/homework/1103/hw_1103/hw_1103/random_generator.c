#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "random_generator.h"

void random_config(void)
{
	// NULL은 stdio.h에 정의되어있음
	srand(time(NULL));
}

int generate_random(int min, int max)
{

	return rand() % (max - min + 1) + min;
}