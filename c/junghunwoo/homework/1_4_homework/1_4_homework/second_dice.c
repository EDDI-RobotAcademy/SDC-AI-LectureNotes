#include <stdio.h>
#include "second_dice.h"
#include "dice_game.h"
#include "random_generator.h"

const int min2 = 1;
const int max2 = 6;

void second_dice_player1(index)
{
	player_each_dice_number2[index] = generate_random(min2, max2);
	if (player_each_dice_number2[index] == 2)
	{
		printf("첫 번째 플레이어 두 번째 주사위 눈금은 %d입니다.\n", player_each_dice_number2[index]);
		player_each_dice_score1 = player_each_dice_score1 + player_each_dice_number2[index] + 3;
	}
	else if (player_each_dice_number2[index] == 3)
	{
		printf("첫 번째 플레이어 두 번째 주사위 눈금은 %d입니다.\n", player_each_dice_number2[index]);
		player_each_dice_score1 = player_each_dice_score1 + player_each_dice_number2[index];
		player_each_dice_score2 = player_each_dice_score2 - 4;
	}
	else if (player_each_dice_number2[index] == 4)
	{
		printf("첫 번째 플레이어 두 번째 주사위 눈금은 %d입니다.\n", player_each_dice_number2[index]);
		printf("플레이어 %s는 강제로 점수가 0이 됩니다.\n", player[index]);
		player_each_dice_score1 = 0;
	}
	else
	{
		printf("첫 번째 플레이어 두 번째 주사위 눈금은 %d입니다.\n", player_each_dice_number2[index]);
		player_each_dice_score1 = player_each_dice_score1 + player_each_dice_number2[index];
	}
}

void second_dice_player2(index)
{
	player_each_dice_number2[index] = generate_random(min2, max2);
	if (player_each_dice_number2[index] == 2)
	{
		printf("두 번째 플레이어 두 번째 주사위 눈금은 %d입니다.\n", player_each_dice_number2[index]);
		player_each_dice_score2 = player_each_dice_score2 + player_each_dice_number2[index] + 3;
	}
	else if (player_each_dice_number2[index] == 3)
	{
		printf("두 번째 플레이어 두 번째 주사위 눈금은 %d입니다.\n", player_each_dice_number2[index]);
		player_each_dice_score2 = player_each_dice_score2 + player_each_dice_number2[index];
		player_each_dice_score1 = player_each_dice_score1 - 4;
	}
	else if (player_each_dice_number2[index] == 4)
	{
		printf("두 번째 플레이어 두 번째 주사위 눈금은 %d입니다.\n", player_each_dice_number2[index]);
		printf("플레이어 %s는 강제로 점수가 0이 됩니다.\n", player[1]);
		player_each_dice_score2 = 0;
	}
	else
	{
		printf("두 번째 플레이어 두 번째 주사위 눈금은 %d입니다.\n", player_each_dice_number2[index]);
		player_each_dice_score2 = player_each_dice_score2 + player_each_dice_number2[index];
	}
}
