#include "game.h" // game 헤더를 선언하여 game.c의 함수를 호출.
#include "player.h" // player 헤더를 선언하여 player.c의 함수를 호출.
#include "dice.h" // dice 헤더를 선언하여 dice.c의 함수를 호출.

#include <stdio.h> // stdio.h 입출력 함수를 불러와 사용선언.
#include <stdbool.h> // stdbool.h  참과 거짓을 나타내는 변수를 선언 할 수있다.

#define FIRST_DICE_INDEX	0 // 첫번째 주사위의 인덱스을 나타내는 상수로 '0'으로 정의.
#define SECOND_DICE_INDEX	1 // 두번째 주사위의 인덱스을 나타내는 상수로 '1'으로 정의.
#define BUFF_NUMBER		3 // 스킬이 발동했을 때 증가하는 값에 대한 상수로, 3으로 정의.
#define DEBUFF_NUMBER	4 // 스킬이 적용됐을 때 감소하는 값에 대한 상수로, 4로 정의.
#define PLAYER_DEATH -4444 // PLAYER_DEATH: 플레이어가 죽었을 때 할당되는 값에 대한 상수로, -4444로 정의.

// 위와 같은 define 매크로는 프로그램의 가독성을 높이고 나중에 상수 값을 변경해야 할 경우 코드의
// 여러 부분에서 한 번에 변경할 수 있도록 도와줄 수 있다.

int player_each_dice_number[MAX_PLAYER_NUMBER][MAX_ROLL_NUMBER];
/* player_each_dice_number 라는 배열을 선언하고, 이 배열을 주사위를 돌린 플레이어의 점수를 저장할 때 쓰인다
MAX_PLAYER_NUMBER = 플레이어의 최대 수를 나타내는 상수이다.
MAX_ROLL_NUMBER = 플레이어당 주사위를 굴린 횟수를 기록하는 상수이다.*/


void play_game(void)
{	
	int loop; // loop 변수 선언.
	int current_player_index; // current_player_index 변수 선언.
	char* nickname[MAX_PLAYER_NUMBER] = // 2명의 플레이어를 입력.
	{
		"제갈량",
		"사마의"
	};

	printf("사용자 닉네임 생성\n");

	for (loop = 0; loop < MAX_PLAYER_NUMBER; loop++)
	{
		init_player_nickname(nickname[loop]);
	}
	print_player_list();
	/* loop 변수를 0으로 시작하여 MAX_PLAYER_NUMBER보다 작을 때 동안 증가 
	init_player_nickname 함수를 호출하여 매개변수에 저장된 각 플레이어의 이름을 
	player_nickname 배열에 초기화.
	print_player_list 함수를 호출하여 player_nickname 배열에 저장된
	모든 플레이어의 닉네임 목록을 출력. */
	random_seed_config(); // 난수패턴을 발생하는 random_seed_config() 호출.

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
	/*roll_dice() 함수를 선언 후 주사위를 돌리고 그 결과값을 first_dice_number에 저장한다.
	그 후 결과값이 짝수 인지확인이 되면 apply_dice_skill함수를 호출 하여 스킬 및 결과값을 산출한다.*/
	check_winner();
	// check_winner 함수를 호출하여 위의 결과를 토대로 승자를 확인한다.
}

void apply_dice_skill(int current_player_index)
{
	int second_dice_number = 
		player_each_dice_number[current_player_index][SECOND_DICE_INDEX] += roll_dice();
	int target_player_index;

	printf("현재 두 번째 주사위 눈금 =%d\n", second_dice_number);

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
			player_each_dice_number[current_player_index][SECOND_DICE_INDEX] -= BUFF_NUMBER);
		debuff_to_target_player(target_player_index);
		break;

	case 4:

		player_death(current_player_index);
		printf("죽음 : %d\n", player_each_dice_number[current_player_index][SECOND_DICE_INDEX]);
		break;
	
	default:
		printf("스킬 사용이 불가합니다.\n");
		break;

	}
}
/*apply_dice_skill 함수는 첫번째 주사위 값이 짝수 일 경우 작동하는 함수이며,
두번째 주사위를 굴렸을 때, roll_dice 함수에 더하고 그 결과값을 second_dice_number에 저장한다.
switch문을 사용하여
주사위 값이 2가 나올 경우 buff_to_current_player 함수를 호출하여 해당되는 점수를 더하고
주사위 값이 3이 나올 경우 find_target_player 함수를 호출하여 상대 플레이어의 점수를 깍습니다.
주사위 값이 4가 나올 경우 player_death 함수를 호출하여 해당 플레이어는 게임오버가 됩니다.
그 외의 주사위 값은 사용 불가.*/

void buff_to_current_player(int current_player_index)
{
	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] += BUFF_NUMBER;
}
/*buff_to_current_player 함수는 해당 플레이어의 점수를 BUFF_NUMBER의 상수만큼 점수를 더한다. */

int find_target_player(int current_player_index)
{
	// 조건 ? 참인경우 : 거짓인 경우
	// 위의 형태로 작성.
	return current_player_index ? 0 : 1;
}

void debuff_to_target_player(int target_player_index)
{
	player_each_dice_number[target_player_index][SECOND_DICE_INDEX] -= DEBUFF_NUMBER;
}
/*debuff_to_target_player 함수는 상대 플레이어의 점수를 DEBUFF_NUMBER의 상수만큼 점수를 뺀다. */

void player_death(int current_player_index)
{
	player_each_dice_number[current_player_index][SECOND_DICE_INDEX] = PLAYER_DEATH;
}
/*player_death 함수는 해당 플레이어의 점수를 PLAYER_DEATH의 상수만큼 뺀다(게임오버 시킨다.)*/

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
/*each_player_dice_sum 배열을 선언하고, 각 플레이어의 주사위 합을 저장하고, loop를 통해 두 번째 주사위의 값이 
PLAYER_DEATH 상수와 일치하는 플레이어가 있는지 확인 후, 이에 따라 death_count를 증가 시켜 패배 메시지를 출력하게 한다.
만약 둘다 death 카운트가 있다면 무승부로 나오며 그외에는 점수에 따라 승패를 결정한다.*/


	// 4에 대한 예외처리

	for (i = 0; i < MAX_PLAYER_NUMBER; i++)
	{
		if (player_each_dice_number[i][SECOND_DICE_INDEX] == PLAYER_DEATH)
		{
			death_count++;
			printf("플레이어 %d 님은 패배하셨습니다.\n", i);
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
		printf("무승부!");
	}
}