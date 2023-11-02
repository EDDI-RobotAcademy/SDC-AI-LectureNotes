#include <stdio.h>
#include "dice_game.h"
#include "generate_random.h"

#define MIN		1
#define MAX		6

int dice_number = 0;
int roll_time = 0;

void roll_dice(void)
{
	dice_number = generate_random(MIN, MAX);
}

void print_dice_number(void)
{
	for 
	printf("%d\n", dice_number);
}