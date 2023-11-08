#include "game.h"
#include "player.h"
#include "dice.h"
#include "random.h"
#include "common.h"

#include <stdio.h>
#include <stdbool.h>

#define FIRST_DICE_INDEX			0		// 첫번째 플레이어 INDEX 선언
#define SECOND_DICE_INDEX			1		// 두번째 플레이어 INDEX 선언

#define BUFF_NUMBER					3		// 주사위 2가 나왔을 때의 버퍼 점수
#define DEBUFF_NUMBER				4		// 주사위 3이 나왔을 때의 상대에게 적용할 디버퍼 점수
#define PLAYER_DEATH				-4444	// 주사위 4가 나왔을 때의 자살 시 적용하는 점수

int player_each_dice_number[MAX_PLAYER_NUMBER][MAX_ROLL_NUMBER];

void play_game(void)
{
	int loop;
	int current_player_index;
	char* nickname[MAX_PLAYER_NUMBER] = {
		"입벌려힐들어간다",
		"주님곁으로"
	};

	printf("사용자 닉네임 생성\n");
	// 아래 루프에 넣어도 상관없으나 우선은 별도로 분리하겠습니다
	for (loop = 0; loop < MAX_PLAYER_NUMBER; loop++)
	{
		init_player_nickname(nickname[loop]);
	}
	print_player_list();

	random_seed_config();
	// 플레이어 인원수 만큼 반복 수행
	for (current_player_index = 0; current_player_index < MAX_PLAYER_NUMBER; current_player_index++)
	{
		int try_count = 0;
		int first_dice_number;

		// 첫번째 주사위 굴리기
		first_dice_number =
			player_each_dice_number[current_player_index][try_count] = roll_dice();

		printf("주사위 눈금: %d\n", first_dice_number);

		// 짝수 여부 판별하여 짝수일 경우 스킬을 발동
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
	int target_player_index;
	int second_dice_number =
		player_each_dice_number[current_player_index][SECOND_DICE_INDEX] += roll_dice();

	printf("현재 두 번째 주사위 눈금 = %d\n", second_dice_number);


	// 두번째 주사위 눈금에 따라 스킬 적용
	switch (second_dice_number)
	{
	case 2:
		buff_to_current_player(current_player_index);
		printf("두 번째 주사위 점수는 %d\n",
			player_each_dice_number[current_player_index][SECOND_DICE_INDEX]);
		break;

	case 3:
		target_player_index = find_target_player(current_player_index);
		printf("스킬 적용 전 눈금 %d\n",
			player_each_dice_number[target_player_index][SECOND_DICE_INDEX]);
		debuff_to_target_player(target_player_index);
		printf("스킬 적용 이후 눈금 %d\n",
			player_each_dice_number[target_player_index][SECOND_DICE_INDEX]);
		break;

	case 4:
		player_death(current_player_index);
		printf("죽었음: %d\n",
			player_each_dice_number[current_player_index][SECOND_DICE_INDEX]);
		break;

	default:
		printf("스킬 사용이 불가합니다!\n");
		break;
	}
}

void buff_to_current_player(int current_player_index)
{
	// BUFF_NUMBER 상수 3을 더함
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
	// DEBUFF_NUMBER 상수 4를 뺌
	player_each_dice_number[target_player_index][SECOND_DICE_INDEX] -= DEBUFF_NUMBER;
}

void player_death(int current_player_index)
{
	// PLAYER_DEATH 상수 -4444 를 대입함
	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] = PLAYER_DEATH;
}

void check_winner(void)
{
	int each_player_dice_sum[MAX_PLAYER_NUMBER];
	int current_player_index;
	int i;

	int death_count = 0;
	bool does_everyone_lose = false;      // 플레이어 모두 사망

	for (current_player_index = 0; current_player_index < MAX_PLAYER_NUMBER; current_player_index++)
	{
		// 첫번째 주사위와 두번째 주사위 점수를 합산
		each_player_dice_sum[current_player_index] =
			player_each_dice_number[current_player_index][FIRST_DICE_INDEX] +
			player_each_dice_number[current_player_index][SECOND_DICE_INDEX];
	}

	// 4에 대한 예외 처리
	for (i = 0; i < MAX_PLAYER_NUMBER; i++)
	{
		if (player_each_dice_number[i][SECOND_DICE_INDEX] == PLAYER_DEATH)
		{
			death_count++;
			printf("플레이어%d 님은 패배하셨습니다!\n", i);
		}
	}

	if (death_count == 2) { does_everyone_lose = true; }

	// 모든 (2명) 플레이어 사망
	if (does_everyone_lose) { return; }

	// 합산 점수 기준으로 승리 판정
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
		printf("무승부!");
	}
}