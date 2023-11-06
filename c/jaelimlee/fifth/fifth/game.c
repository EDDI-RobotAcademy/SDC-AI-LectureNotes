#include "game.h"
#include "player.h"
#include "dice.h"
#include "random.h"
#include "common.h"

#include <stdio.h>
#define SECOND_DICE_INDEX		1
#define BUFF_NUMBER			3
#define DBUFF_NUMBER		4

int player_each_dice_number[MAX_PLAYER_NUMBER][MAX_ROLL_NUMBER];

void play_game(void)
{
	int loop;
	int current_player_index;

	char* nickname[MAX_PLAYER_NUMBER] = {
		"입벌려 힐 들어간다",
		"주님 곁으로"
	};

	printf("사용자 닉네임 생성\n");
	// 아래 루프에 넣어도 상과 없으나 우선은 별도로 분리
	for (loop = 0; loop < MAX_PLAYER_NUMBER; loop++)
	{
		init_player_nickname(nickname[loop]);

	}
	print_player_list();
	
	random_seed_config();
	for (current_player_index = 0; current_player_index < MAX_PLAYER_NUMBER; current_player_index++)
	{
		int try_count = 0;
		int first_dice_number;

		first_dice_number = player_each_dice_number[current_player_index][try_count] = roll_dice();
		printf("주사위 눈금: %d\n", first_dice_number);

		if (check_even(first_dice_number))
		{
			printf("주사위 스킬을 발동합니다!\n");
			apply_dice_skill(current_player_index);
		}
	}
	
}

void apply_dice_skill(int current_player_index)
{
	int second_dice_number = 
		player_each_dice_number[current_player_index][SECOND_DICE_INDEX] = roll_dice();

	printf("현재 두 번째 누사위 눈금 = %d\n", second_dice_number);
	
	int target_player_index;

	switch (second_dice_number)
	{
	case 2:
		buff_to_current_player(current_player_index);
		printf("두 번쨰 주사위 점수는 %d\n", 
			player_each_dice_number[current_player_index][SECOND_DICE_INDEX]);
		break;

	case 3:
		target_player_index = find_target_player(current_player_index);
		printf("스킬 적용 전 눈금 %d", player_each_dice_number[target_player_index][SECOND_DICE_INDEX]);
		dbuff_to_target_player(target_player_index);
		printf("스킬 적용 dlgn 눈금 %d", player_each_dice_number[target_player_index][SECOND_DICE_INDEX]);
		break;

	case 4:
		break;

	default:
		printf("스킬 사용이 불가합니다!\n");
		break;
	}
}

void buff_to_current_player(current_player_index)
{
	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] += BUFF_NUMBER;
}

int find_target_player(int current_player_index)
{
	// 조건 ? 참인 경우: 거짓인 경우
	// 위의 형태로 작성
	return current_player_index ? 0 : 1;
}

void dbuff_to_target_player(int target_player_index)
{
	player_each_dice_number[target_player_index][SECOND_DICE_INDEX] += DBUFF_NUMBER;
}