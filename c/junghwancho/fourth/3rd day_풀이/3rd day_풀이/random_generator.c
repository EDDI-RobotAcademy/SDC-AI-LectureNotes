#include <time.h> // time 함수
#include <stdio.h>
#include <stdlib.h>

#include "random_generator.h"

void random_config(void)
{
	//stdlib.h 이용
	srand(time(NULL)); //< 무작위 난수
}

int generate_random(const int min, const int max)
{
	return rand() % (max - min + 1) + min;
}