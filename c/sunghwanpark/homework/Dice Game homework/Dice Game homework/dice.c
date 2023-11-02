#include "dice.h"
#include "random.h"
#include <stdio.h>

#define MAX 6
#define MIN 1

int loop; 
int roll;
int dice;

int set_dice_number(const int count) 
{
	srand(time(NULL));
	for (loop = 1; loop <= count; loop++)
	{
		dice = generate_random(MIN, MAX);
	}
}

void print_dice_number(int dice_number)
{
		printf(" %2d  \n", dice_number);
}