#include "dice_game.h"
#include "random_generator.h"

#define MIN			1
#define MAX			6

int dice_number = 0;

int dice_roll(void)
{
	return dice_number = generate_random(MIN, MAX);
}

void print_dice_number(void)
{
	printf("주사위 숫자는 : %d\n", dice_number);
}