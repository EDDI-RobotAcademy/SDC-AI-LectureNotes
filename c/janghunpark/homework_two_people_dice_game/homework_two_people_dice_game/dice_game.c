#include <stdio.h>
#include "dice_game.h"
#include "generate_random.h"

#define MIN		1
#define MAX		6

int dice_number1 = 0;
int dice_number2 = 0;

void roll_dice1(void)
{
	dice_number1 = generate_random1(MIN, MAX);
}

void print_dice_number1(void)
{
	printf("%d\n", dice_number1);
}

void roll_dice2(void)
{
	dice_number2 = generate_random2(MIN, MAX);
}

void print_dice_number2(void)
{
	printf("%d\n", dice_number2);
}