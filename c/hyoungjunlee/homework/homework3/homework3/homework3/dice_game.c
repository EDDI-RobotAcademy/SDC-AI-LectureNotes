#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player_info.h"
#include "dice_game.h"
#include "random_generator.h"




const int min = 1;
const int max = 6;
int player_point[PLAYER_NUMBER];
void roll_dice(int index)
{

	player_point[index] = generate_random(min, max);

	//printf("%d 플레이어 주사위한번 던졌을 때 값 %d\n", index,player_point[index]);
	if (player_point[index] % 2 == 0)
	{
		second_roll_dice(index);
	}

}
void second_roll_dice(int index)
{
	int second_dice_number;
	second_dice_number = generate_random(min, max);
	//printf("2번째 주사위 값%d\n",second_dice_number);
	player_point[index] = player_point[index] + second_dice_number;
	
	if (second_dice_number == 2)
		player_point[index] += 3;
	if (second_dice_number == 4)
		player_point[index] =0;
	if (second_dice_number == 3)
	{
		if(index  == 0)
			player_point[1] -= 4;
		if (index == 1)
			player_point[0] -= 4;
	}
}

