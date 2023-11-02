#include <stdio.h>
#include "diec_game.h"
#include "random_generator.h"

#define MAX			6
#define MIN			1

extern int dice_number = 0;

void roll_dice(void)
{
	dice_number = generate_random(MIN, MAX);
}

void print_dice_number(void)
{
	printf("굴려서 나온 주사위 숫자 = %d\n", dice_number);
}