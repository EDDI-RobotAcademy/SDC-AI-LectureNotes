#include <stdio.h>

#include "dice.h"
#include "random_generator.h"

int player_each_dice_number[MAX_PLAYER_NUMBER];

const int min = 1;
const int max = 6;

void roll_dice(const int index)
{
	int first_dice_number = 0;
	int second_dice_number = 0;

	first_dice_number = generate_random(min, max);

	player_each_dice_number[index] += first_dice_number;
	printf("%s의 첫번째 주사위 숫자: %d\n", player_name[index], first_dice_number);

	if (first_dice_number % 2 == 0)
	{
		second_dice_number = generate_random(min, max);
		printf("%s의 두번째 주사위 숫자: %d\n", player_name[index], second_dice_number);
		
		if (second_dice_number == 2)
		{
			player_each_dice_number[index] += 3;
		}
		else if (second_dice_number == 3)
		{
			attack_player(index);
		}
		else if(second_dice_number == 4)
		{
			player_each_dice_number[index] = -99999999999;
		}
		else
		{
			player_each_dice_number[index] += second_dice_number;
		}
	}

}

void print_dice_number(const int index)
{
	printf("%s의 주사위 눈금은 %d\n", player_name[index], player_each_dice_number[index]);
}