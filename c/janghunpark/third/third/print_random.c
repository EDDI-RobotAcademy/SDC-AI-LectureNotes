#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "print_random.h"
#include "random_generator.h"

void print_random_number(int count)
{
	int loop;
	const int min = 10;
	const int max = 20;
	
	/*
	srand(time(NULL))은 무작위 랜덤을 만드려면 항상 들어가야 한다.
	*/
	srand(time(NULL));

	printf("10-20사이의 랜덤 번호 출력: \n");
	for (loop = 0; loop < count; loop++)
	{
		// x % (Max - Min + 1) + Min
		// %nd에서 n에 들어가는 숫자는 출력값의 스페이스 개수
		printf("%3d", generate_random(min, max));
	}

}