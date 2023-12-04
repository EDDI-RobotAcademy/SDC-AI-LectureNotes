#include <stdlib.h>
#include "random.h"
#include <time.h>

// 랜덤
void random_config(void)
{
	srand(time(NULL));
}

int generate_random(const int min, const int max)
{
	return rand() % (max - min + 1) + min;
}