#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "random_generator.h"
#include "random_dice.h"

void random_dice(const int count)
{
	int loop;

	int dice_number;
	int score = 0;

	const int min = 1;
	const int max = 6;

	
	for (loop = 0; loop < count; loop++)
		{
		dice_number = generate_random(min, max);
		score = score + dice_number;
		printf("%d번 째 굴려서 나온 주사위 값은 : %d 이고 합친 값은 %d이다\n", loop + 1, dice_number, score);
		}
	
}