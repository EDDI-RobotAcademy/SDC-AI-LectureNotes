#include <stdio.h>
#include <stdbool.h>

#include "game.h"
#include "player.h"
#include "dice.h"
#include "random.h"
#include "common.h"

int player_each_dice_number[MAX_PLAYER_NUMBER][MAX_ROLL_NUMBER];

#define FIRST_DICE_INDEX		0
#define SECOND_DICE_INDEX		1
#define BUFF_NUMBER				3
#define DEBUFF_NUMBER			4
#define PLAYER_DEATH			-4444

void play_game()
{
	int current_player_index;


	char* nickname[MAX_PLAYER_NUMBER] = {
		"탱커",
		"힐러"
	};

	printf("퀴즈 풀이\n");

	for (current_player_index = 0; current_player_index < MAX_PLAYER_NUMBER; current_player_index++)
	{
		init_player_nickname(nickname[current_player_index]);
	}

	print_player_list();

	random_seed_config();

	

	for (current_player_index = 0; current_player_index < MAX_PLAYER_NUMBER; current_player_index++)
	{
		int try_count = 0;
		int firse_dice_number = 
			player_each_dice_number[current_player_index][try_count] = roll_dice();
		printf("첫 번째 주사위 눈금: %d\n", firse_dice_number);

		if (check_even(firse_dice_number))
		{
			
			printf("스킬을 발동합니다!\n");

			apply_dice_skill(current_player_index);
		}
	}

	check_winner();
}


void apply_dice_skill(const int current_player_index)
{

	// 전역변수는 초기값이 0이기에 초기화 할 필요는 없음
	// 재사용이 필요하거나, 지역변수일 경우 초기화 작업을 해줄 필요가 있음
	int second_dice_number = roll_dice();

	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] += second_dice_number;
	printf("두 번째 주사위는 %d\n", second_dice_number);

	int target_player_index;

	switch (second_dice_number)
	{
	case 2:
		buff_to_current_player(current_player_index);
		printf("버프 발동!\n");
		printf("두 번째 주사위 점수는 %d\n", player_each_dice_number[current_player_index][SECOND_DICE_INDEX]);
		break;

	case 3:
		target_player_index = find_target_player(current_player_index);

		printf("디버프 발동!");
		debuff_to_target_player(target_player_index);
		printf("상대 주사위 숫자 변경: %d -> %d \n", player_each_dice_number[target_player_index][SECOND_DICE_INDEX]+DEBUFF_NUMBER, player_each_dice_number[target_player_index][SECOND_DICE_INDEX]);
		break;

	case 4:
		player_death(current_player_index);
		printf("죽었음: %d\n",
			player_each_dice_number[current_player_index][SECOND_DICE_INDEX]);
		break;

	default:
		printf("스킬 사용이 불가능합니다!\n");
		break;
	}
}

void buff_to_current_player(int current_player_index)
{
	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] += BUFF_NUMBER;
}

int find_target_player(int current_player_index)
{
	// 조건 ? 참인경우 : 거짓인경우
	// 위의 형태로 작성합니다.
	return current_player_index ? 0 : 1;
}

void debuff_to_target_player(int target_player_index)
{
	player_each_dice_number[target_player_index][SECOND_DICE_INDEX] -= DEBUFF_NUMBER;
}

void player_death(int current_player_index)
{
	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] = PLAYER_DEATH;
}

void check_winner()
{
	int each_player_dice_sum[MAX_PLAYER_NUMBER];
	int current_player_index;

	int death_count = 0;

	bool does_everyone_lose = false;

	for (current_player_index = 0; current_player_index < MAX_PLAYER_NUMBER; current_player_index++)
	{
		each_player_dice_sum[current_player_index]
			= player_each_dice_number[current_player_index][FIRST_DICE_INDEX] +
			player_each_dice_number[current_player_index][SECOND_DICE_INDEX];
	}

	// 4에 대한 예외 처리
	for (current_player_index = 0; current_player_index < MAX_PLAYER_NUMBER; current_player_index++)
	{
		if (player_each_dice_number[current_player_index][SECOND_DICE_INDEX] == PLAYER_DEATH)
		{
			printf("플레이어%d 님은 패배하셨습니다.\n", current_player_index);
			death_count++;
		}
	}

	if (death_count == 2) { does_everyone_lose = true; }

	if (does_everyone_lose) { return; }

	if (each_player_dice_sum[0] > each_player_dice_sum[1])
	{
		printf("0번 플레이어 승리!");
	}
	else if (each_player_dice_sum[0] < each_player_dice_sum[1])
	{
		printf("1번 플레이어 승리!");
	}
	else
	{
		printf("무승부");
	}
}