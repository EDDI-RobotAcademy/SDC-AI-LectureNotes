#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "dice_game.h"
#include "player.h"	

#include "random_generator.h"

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
	printf("%d 번 플레이어의 점수는 %d\n", index, player_score_array[index]);
}

void roll_dice_second(const int index)
{
	int dice_number = generate_random(min, max);
	printf("두번째 주사위는 %d\n", dice_number);



	player_score_array[index] = player_score_array[index] + dice_number;


}