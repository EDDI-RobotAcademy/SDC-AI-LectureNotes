#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "dice_game.h"
#include "player.h"	
#include "random_generator.h"
#include "dice_skill.h"
const int min = 1;
const int max = 6;

int* player_score_array;

void create_player_score_array(int count)
{
	player_score_array = (int*)malloc(sizeof(int) * count);
}

void roll_dice(const int index)
{
	player_score_array[index] = generate_random(min, max);
}

void print_dice_number(const int index)
{
	printf("%s의 점수는 %d\n", player[index], player_score_array[index]);
}

void roll_dice_second(const int index)
{
	int dice_number = generate_random(min, max);
	printf("두번째 주사위는 %d\n", dice_number);
	if (dice_number == 2)
	{
		dice_skill_2(index);
	}
	else if (dice_number == 3)
	{
		dice_skill_3(index);
	}
	else if (dice_number == 4)
	{
		dice_skill_4(index);
	}
	else
	{
		player_score_array[index] = player_score_array[index] + dice_number;
	}
}