#include <stdlib.h>
#include "random_generator.h"
#include "dice_random.h"

void dice_number_indicator(const int count)
{
	int dice_count;
	
	const int dice_minimum = 1;
	const int dice_maximum = 6;

	srand(time(NULL));
	
	printf("주사위를 굴려서 나온 숫자: ");
	for (dice_count = 0; dice_count < count; dice_count++)
	{
		printf("%2d", generate_random(dice_minimum, dice_maximum));
	}
}

void dice_number_indicator(void)
{
}
