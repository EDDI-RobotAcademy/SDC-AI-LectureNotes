#include <stdio.h>

#include "dice.h"
#include "random_generator.h"

#define MAX			6
#define MIN			1

int dice_number = 0;


void dice_roll(void)
{
	dice_number = random_generate(MIN, MAX);

}

void print_dice_number(void)
{
	printf("나온 숫자는 = %d 입니다 \n", dice_number);
}