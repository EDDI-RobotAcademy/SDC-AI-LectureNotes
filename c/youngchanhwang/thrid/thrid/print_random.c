#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "print_random.h"
#include "random_generator.h"

void print_random_number(const int count)
{
	int loop;

	const int min = 10;
	const int max = 20;


	// srand(time(NULL)) 은 무작위 랜덤을 만드려면 항상 들어가야 합니다.
	srand(time(NULL));

	printf("10 ~ 20 사이의 랜덤 번호 출력 : \n");
	for (loop = 0; loop < count; loop++)
	{
		// x % (MAX - MIN + 1) + MIN
		// %3d => 3칸의 자리를 확보하기 위해 /안하면 숫자를 다 붙어있음
		printf("%3d", generate_random(min, max));
	}
	printf("\n");

}