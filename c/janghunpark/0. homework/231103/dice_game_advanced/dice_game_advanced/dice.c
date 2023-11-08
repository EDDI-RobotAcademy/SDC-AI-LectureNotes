#include <stdio.h>
#include "player.h"
#include "dice.h"
#include "random_generator.h"

#define FIRST_ROLL			0
#define SECOND_ROLL			1

const int min = 1;
const int max = 6;

int player_each_dice_number[MAX_PLAYER_NUMBER][MAX_ROLL_NUMBER];
int final_dice_number[MAX_PLAYER_NUMBER];
int current_player_index;

void roll_dice(void)
{
	for (current_player_index = 0; current_player_index < MAX_PLAYER_NUMBER; current_player_index++)
	{
		player_each_dice_number[current_player_index][FIRST_ROLL] = generate_random(min, max);
		print_first_dice_number();
		check_even_dice_number();
	}
}

void print_first_dice_number(void)
{
	printf("%d 번 플레이어의 첫 번째 주사위 눈금은 %d\n", current_player_index, player_each_dice_number[current_player_index][FIRST_ROLL]);
}

void check_even_dice_number(void)
{
	if (player_each_dice_number[current_player_index][FIRST_ROLL] % 2 == 0)
	{
		printf("%d번 플레이어님 짝수가 나오셨군요! 한 번 더 굴릴 기회를 드립니다.\n", current_player_index);
		second_roll_dice();
	}
	else
	{
		printf("홀수군요! 아쉽지만 %d번 플레이어님은 여기서 끝입니다.\n", current_player_index);
	}
}

void second_roll_dice(void)
{
	player_each_dice_number[current_player_index][SECOND_ROLL] = generate_random(min, max);
	printf("%d 번 플레이어의 두 번째 주사위 눈금은 %d\n", current_player_index, player_each_dice_number[current_player_index][SECOND_ROLL]);
	apply_skill();
}

void apply_skill(void)
{
	int target_player_index;
	
	if (player_each_dice_number[current_player_index][SECOND_ROLL] == 2)
	{
		player_each_dice_number[current_player_index][SECOND_ROLL] += 5;
		printf("추가로 3을 더합니다!\n");
	}
	else if (player_each_dice_number[current_player_index][SECOND_ROLL] == 4)
	{
		player_each_dice_number[current_player_index][SECOND_ROLL] -= 1000;
		printf("BAAAM! 뒤지셨습니다!\n");
	}
	else if (player_each_dice_number[current_player_index][SECOND_ROLL] == 3)
	{
		target_player_index = find_target_player(current_player_index);
		player_each_dice_number[target_player_index][SECOND_ROLL] -= 4;
		printf("상대방에게 -4 공격을 합니다!\n");
	}
	else
	{
		printf("스킬은 따로 없습니다!\n");
	}
}

int find_target_player(int current_player_index)
{
	return current_player_index ? 0 : 1;
}

void check_winner(void)
{
	int index;
	for (index = 0; index < MAX_PLAYER_NUMBER; index++)
	{
		final_dice_number[index] = player_each_dice_number[index][FIRST_ROLL] + player_each_dice_number[index][SECOND_ROLL];
	}
	
	if (final_dice_number[0] > final_dice_number[1])
	{
		printf("%d번 플레이어가 승리하셨습니다!\n", 0);
	}
	else if (final_dice_number[0] < final_dice_number[1])
	{
		printf("%d번 플레이어가 승리하셨습니다!\n", 1);
	}
	else
	{
		printf("무승부입니다!");
	}
	
}