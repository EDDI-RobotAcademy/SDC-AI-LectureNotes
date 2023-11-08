#include "game.h"
#include "player.h"
#include "dice.h"
#include "random.h"
#include "common.h"

#include <stdio.h>
#include <stdbool.h>

#define FIRST_DICE_INDEX			0  // 첫 번째 DICE INDEX 정의
#define SECOND_DICE_INDEX			1  // 두 번째 DICE INDEX 정의

#define BUFF_NUMBER					3  // 두 번째 주사위가 3이 나오면 BUFF 하도록 사용하려고 상수값 정의
#define DEBUFF_NUMBER				4  // 두 번째 주사위가 4가 나오면 DEBUFF 하도록 사용하려고 상수값 정의
#define PLAYER_DEATH				-4444  // 두 번째 주사위가 4가 나오면 PLAYER_DEATH로 사용하려고 상수값 정의

int player_each_dice_number[MAX_PLAYER_NUMBER][MAX_ROLL_NUMBER]; // 주사위를 굴려 나온 숫자 값을 저장하기 위한 배열

void play_game(void) // play_game 이라는 input void output void 함수 선언
{
	int loop; // play_game에서 사용할 loop라는 지역 변수 선언 -> player nickname 설정 시 반복문에서 MAX_PLAYER_NUMBER를 count 하기 위해 생성한 변수
	int current_player_index; // play_game에서 사용할 current_player_index 지역 변수 선언 -> 반복문에서 첫 번째, 두 번째 dice를 던지기는 것을 count 하기 위한 변수
	char* nickname[MAX_PLAYER_NUMBER] = { // char* 함수를 사용하여 MAX_PLAYER_NUMBER 수에 해당하는 배열 nickname 생성
		"입벌려힐들어간다",
		"주님곁으로"
	};

	printf("사용자 닉네임 생성\n"); // 사용자 닉네임을 생성할 거라는 안내 print

	for (loop = 0; loop < MAX_PLAYER_NUMBER; loop++) // 반복문: loop를 이용하여 MAX_PLAYER_NUMBER를 count 하고,
	{												 // 그 수가 2보다 작을 때 init 이하를 수행하여 플레이어 이름 생성
		init_player_nickname(nickname[loop]); // loop가 2보다 작을 때 char*에 들어간 nickname을 생성 => loop가 2보다 클 때 반복문 종료
	}
	print_player_list(); // player.c에서 구성된 대로 생성된 player list print

	random_seed_config(); // random.c에서 구성된 대로 random으로 dice number를 초기화 시킴 => 없을 시 계속 똑같은 값 (6) 생성

	for (current_player_index = 0; current_player_index < MAX_PLAYER_NUMBER; current_player_index++) // 반복문: current_player_index를 이용하여 주사위를 순서대로 던지고
	{																								 // 첫 번째 주사위 값을 check_even을 통해 두 번째 주사위를 던질 지 판단(짝수 시)
		int try_count = 0; // 현재는 의미 없는 변수
		int first_dice_number; // 첫 번째 주사위 값을 저장하기 위한 변수 생성

		first_dice_number = // 첫 번째 주사위 값 저장 정의
			player_each_dice_number[current_player_index][try_count] = roll_dice(); // roll_dice를 수행하여 player_each_dice_number의 배열에 맞게 저장 및 first_dice_number로 사용하겠다.

		printf("주사위 눈금: %d\n", first_dice_number); // 첫 번째 주사위 값 print

		if (check_even(first_dice_number)) // 첫 번째 주사위 값을 common.c에 정의 된 check_even으로 홀/짝 판단해서 if 반복문 수행
		{
			printf("주사위 스킬을 발동합니다!\n"); // 조건(짝수)이 맞는다면 두 번째 주사위를 굴리기 전 멘트 print
			apply_dice_skill(current_player_index); // check_even으로 input된 current_player_index가 짝수일 시 아래 apply_dice_skill function 수행
		}
	}
	check_winner(); // 아래 정의된 check_winner fucntion 수행
}



void apply_dice_skill(int current_player_index) // 위의 apply_dice_skill 수행 function 정의
{
	int target_player_index; // 짝수, 3, 4 가 나왔을 때 skill을 사용 할 수 있도록 사용 할 변수 선언
	int second_dice_number = roll_dice(); // ????? 기존 player_each_dice_number에 다시 roll_dice 값을 plus = second_dice_number
	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] += second_dice_number;

	printf("현재 두 번째 주사위 눈금 = %d\n", second_dice_number); // 두 번째 dice number print

	switch (second_dice_number) // switch 문으로 조건에 맞는 기능 실행
	{
	case 2:
		buff_to_current_player(current_player_index); // 두 번째 주사위 값이 2가 나왔을 때 수행
		printf("두 번째 주사위 점수는 %d\n", // 두 번째 주사위 값과 함께 멘트 출력
			player_each_dice_number[current_player_index][SECOND_DICE_INDEX]);
		break;

	case 3:
		target_player_index = find_target_player(current_player_index); // ??? 이해가 좀 더 필요함
		printf("스킬 적용 전 눈금 %d\n",
			player_each_dice_number[target_player_index][SECOND_DICE_INDEX]);
		debuff_to_target_player(target_player_index);
		printf("스킬 적용 이후 눈금 %d\n",
			player_each_dice_number[target_player_index][SECOND_DICE_INDEX]);
		break;

	case 4:
		player_death(current_player_index); // 두 번째 주사위 값이 4가 나왔을 때 수행
		printf("죽었음: %d\n",
			player_each_dice_number[current_player_index][SECOND_DICE_INDEX]);
		break;

	default:// 위 3가지 경우가 아닌 경우 수행
		printf("스킬 사용이 불가합니다!\n");
		break;
	}
}

void buff_to_current_player(int current_player_index) // 두 번째 값이 2가 나왔을 때 수행되는 function
{
	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] += BUFF_NUMBER; // 정의된 BUFF_NUMBER (3) 을 player_each_dice_number에 +
}

int find_target_player(int current_player_index) // ?? 이해가 필요함
{
	// 조건 ? 참인경우 : 거짓인경우
	// 위의 형태로 작성합니다.
	return current_player_index ? 0 : 1;
}

void debuff_to_target_player(int target_player_index) // 두 번째 값이 3일 때 find_target_player와 함께 수행
{
	player_each_dice_number[target_player_index][SECOND_DICE_INDEX] -= DEBUFF_NUMBER; // 정의된 DEBUFF_NUMBER (4) 를 player_each_number에 -
}

void player_death(int current_player_index) // 두 번째 값이 4일 때 수행
{
	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] = PLAYER_DEATH; // 정의된 PLAYER_DEATH(-4444)를 player_each_dice_number에 대입
}

void check_winner(void) // 위의 승부 판결 기능
{
	int each_player_dice_sum[MAX_PLAYER_NUMBER]; // ??
	int current_player_index; // check_winner에서 사용 할 지역 변수 선언
	int i; // check_winner에서 사용 할 지역 변수 선언

	int death_count = 0;
	bool does_everyone_lose = false;

	for (current_player_index = 0; current_player_index < MAX_PLAYER_NUMBER; current_player_index++)
	{
		each_player_dice_sum[current_player_index] =
			player_each_dice_number[current_player_index][FIRST_DICE_INDEX] +
			player_each_dice_number[current_player_index][SECOND_DICE_INDEX];
	}
	for (i = 0; i < MAX_PLAYER_NUMBER; i++)
	{
		if (player_each_dice_number[i][SECOND_DICE_INDEX] == PLAYER_DEATH)
		{
			death_count++;
			printf("플레이어%d 님은 패배하셨습니다!\n", i);
		}
	}

	if (death_count == 2) { does_everyone_lose == true; }

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
