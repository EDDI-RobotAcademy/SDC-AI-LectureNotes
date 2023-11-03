#include <stdio.h>

#include "dice_game.h"
#include "player.h"
#include "random_generator.h"

int player_each_dice_number[MAX_PLAYER_NUMBER];
int playerindex_count; 

const int min = 1;
const int max = 6;

void roll_dice(const int index)
{
	player_each_dice_number[playerindex_count++]= generate_random(min,max);
}

void print_dice_number(const int index) 
{
	printf("%d 번 플레이어의 주사위 눈금은 %d\n", index+1, player_each_dice_number[index]);
}