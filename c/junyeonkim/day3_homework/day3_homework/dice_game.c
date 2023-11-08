#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include "dice_game.h"
#include "random_generator.h"

#define MAX			6
#define MIN			1

int dice_number = 0;
int dice_number2 = 0;

void roll_dice(void)
{
	dice_number = generate_random(MIN, MAX);
	dice_number2 = generate_random(MIN, MAX);
}

void print_dice_number(void)
{
	printf("\n");
	printf("굴려서 나온 주사위 숫자 = %d\n", dice_number);
}