#include <stdlib.h>
#include "random_generator.h"

int generate_random_player1(int min, int max)
{
	srand(time(NULL));
	return rand() % (max - min + 1) + min;
}

int generate_random_player2(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int generate_random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}