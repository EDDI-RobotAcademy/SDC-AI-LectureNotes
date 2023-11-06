#include "game.h"
#include "player.h"
#include "dice.h"
#include "random.h"
#include "common.h"

#include <stdio.h>
#include <stdbool.h>

#define FIRST_DICE_INDEX						0
#define SECOND_DICE_INDEX						1
#define BUFF_NUMBER								3
#define DEBUFF_NUMBER							4
#define PLAYER_DEATH							-4444

int player_each_dice_number[MAX_PLAYER_NUMBER][MAX_ROLL_NUMBER];

void play_game(void)
{
	int loop;
	int current_player_index;
	char* nickname[MAX_PLAYER_NUMBER] = {
		"입벌려힐들어간다", "주님곁으로"
	};

	printf("사용자 닉네임 생성 \n");
	// 아래 루프에 넣어도 상관없으나 우선을 별도로 분리하겠습니다.
	for (loop = 0; loop < MAX_PLAYER_NUMBER; loop++)
	{
		init_player_nickname_info(nickname[loop]);
	}
	print_player_list();

	random_seed_config();
	for (current_player_index = 0; current_player_index < MAX_PLAYER_NUMBER; current_player_index++)
	{
		int try_count = 0;
		int first_dice_number;

		first_dice_number = 
			player_each_dice_number[current_player_index][try_count] = roll_dice();

		printf("주사위 눈금: %d\n", first_dice_number);

		if (check_even(first_dice_number))
		{
			printf("주사위 스킬을 발동합니다!\n");
			apply_dice_skill(current_player_index);
		}

	}

	check_winner();
}

void apply_dice_skill(int current_player_index)
{
	int tartger_player_index;
	int second_dice_number =
		player_each_dice_number[current_player_index][SECOND_DICE_INDEX] += roll_dice();

	printf("현재 두 번째 주사위 눈금 = %d\n", second_dice_number);

	switch (second_dice_number)
	{
		case 2:
			buff_to_current_player(current_player_index);
			printf("두 번째 주사위 점수는 %d\n", player_each_dice_number[current_player_index][SECOND_DICE_INDEX]);
			break;

		case 3:
			tartger_player_index = find_targer_player(current_player_index);
			printf("스킬 적용 전 눈금 %d\n", player_each_dice_number[tartger_player_index][SECOND_DICE_INDEX]);
			debuff_to_target_player(tartger_player_index);
			printf("스킬 적용 후 눈금 %d\n", player_each_dice_number[tartger_player_index][SECOND_DICE_INDEX]);
			break;

		case 4:
			player_death(current_player_index);
			printf("죽었음: %d\n", player_each_dice_number[current_player_index][SECOND_DICE_INDEX]);
			break;

		default:
			printf("스킬 사용이 불가합니다\n");
			break;
	}
}

void buff_to_current_player(int current_player_index)
{
	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] += BUFF_NUMBER;
}

int find_targer_player(int current_player_index)
{
	// 조건 ? 참인경우 : 거짓인 경우
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

void check_winner(void)
{
	int each_player_dice_sum[MAX_PLAYER_NUMBER];
	int current_player_index;
	int i;

	int death_count = 0;

	bool does_everyone_lose = false;

	for (current_player_index = 0; current_player_index < MAX_PLAYER_NUMBER; current_player_index++)
	{
		each_player_dice_sum[current_player_index] =
			player_each_dice_number[current_player_index][FIRST_DICE_INDEX] +
			player_each_dice_number[current_player_index][SECOND_DICE_INDEX];
	}

	// 4에 대한 예외처리
	for (i = 0; i < MAX_PLAYER_NUMBER; i++)
	{
		if (player_each_dice_number[i][SECOND_DICE_INDEX] == PLAYER_DEATH)
		{
			death_count++;
			printf("플레이어%d 님은 패배하였습니다!\n", i);
		}
	}

	if (death_count == 2) { does_everyone_lose = true; }

	if (does_everyone_lose) { return; }

	if (each_player_dice_sum[0] > each_player_dice_sum[1])
	{
		printf("0번 플레이어 승리!");
	}
	else if((each_player_dice_sum[0] < each_player_dice_sum[1]))
	{
		printf("1번 플레이어 승리!");
	}
	else
	{
		printf("무승부");
	}
}