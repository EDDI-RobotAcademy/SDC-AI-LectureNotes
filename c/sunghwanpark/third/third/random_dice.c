#include <stdio.h>
#include <stdlib.h>
#include "random_dice.h"
#include <time.h>
#include "random_generator.h"


void print_random_dice(const int count)
{
	int loop;
	int roll;
	const int min = 1; 
	const int max = 6;

	srand(time(NULL));

	printf("주사위를 굴리시오:\n");
	for (loop = 1; loop <= count; loop++)
	{
		printf(" %2d  \n", generate_random(min, max));

	}
}