#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "random_generator.h"
#include "random_dice.h"

void random_dice(const int count)
{
	int loop;
	
	const int min = 1;
	const int max = 6;

	//srand(time(NULL))은 무자구이 랜덤을 만드려면 항상 들어가야 합니다
	srand(time(NULL));

	printf("주사위 값 %d번 랜덤 출력: \n",count);
	for (loop = 0; loop < count; loop++)
	{
		// x % (MAX - MIN +1) + MIN
		printf("%3d", generate_random(min, max));

	}

}