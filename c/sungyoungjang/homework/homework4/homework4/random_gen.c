#include <time.h>
#include <stdlib.h>

#include "random_gen.h"

void random_config(void)
{
	// NULL이 stdio.h 에 정의 되어 있음
	srand(time(NULL));
}


int generate_random()
{
	return rand() % 6 + 1;
}
