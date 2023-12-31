#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "print_random.h"
#include "random_generator.h"


void print_random_number(const int count)
{
	int loop;

	const int min = 13;
	const int max = 211;
	// srand(time(NULL)) 은 무작위 랜덤을 만드려면 항상 들어가야합니다.
	srand(time(NULL));

	printf("10 ~ 20사이의 랜덤 번호 출력 : \n");
	for (loop = 0; loop < count; loop++)
	{

		// x % (MAX - MIN + 1) + MIN
		printf("%5d",generate_random(min,max));
	}
}