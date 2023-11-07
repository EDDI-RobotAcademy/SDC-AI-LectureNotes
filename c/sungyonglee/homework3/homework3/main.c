#include <stdio.h>

#include "player.h"
#include "dice_game.h"
#include "random_generator.h"

int main(void)

{
	set_player_info("first_player");
	set_player_info("second_player");

	print_player_info(0);
	print_player_info(1);
	printf("\n");

	random_config();
	//roll_dice(0);
	//roll_dice(1);

	int player_each_dice_number[MAX_PLAYER_NUMBER];

	const int min = 1;
	const int max = 6;
	int i;
	int n;
	int score_player0 = 0;
	int score_player1 = 0;
	int bonus_point_player0 = 0;
	int bonus_point_player1 = 0;
	int attack_point_player0 = 0;
	int attack_point_player1 = 0;

	for (i = 0; i < 2; i++)  // 첫번째 플레이어 주사위 굴리기
	{
		int index_first = i;
		player_each_dice_number[index_first] = generate_random(min, max);
		printf("첫번째 플레이어가 주사위를 굴립니다.\n");
		printf("\n");
		printf("플레이어의 %d 번째 주사위 눈금은 %d\n", index_first, player_each_dice_number[index_first]);
		int remainder;
		remainder = player_each_dice_number[index_first] % 2;
		if (remainder == 0)
		{
			printf("첫 번째 주사위가 짝수입니다. 보너스 주사위를 굴립니다.\n");
			for (n = 1; n < 2; n++)
			{
				int index_second = n;
				player_each_dice_number[index_second] = generate_random(min, max);
				printf("플레이어의 %d 번째 주사위 눈금은 %d\n", index_second, player_each_dice_number[index_second]);
				printf("점수를 획득합니다. %d\n", player_each_dice_number[index_second]);
				score_player0 += player_each_dice_number[index_second];
				if (player_each_dice_number[index_second] == 2)
				{
					bonus_point_player0 = 3;
					printf("보너스 점수를 획득합니다. %d\n", bonus_point_player0);
					score_player0 += bonus_point_player0 - attack_point_player1;
				}
				else if (player_each_dice_number[index_second] == 3)
				{
					attack_point_player0 = 4;
					printf("상대의 점수를 깎습니다. %d\n", attack_point_player0);
					score_player1 -= attack_point_player0;
				}
				else if (player_each_dice_number[index_second] == 4)
				{
					printf("플레이어가 자살했습니다.\n");
				}
			}
		}
		else if (remainder == 1)
		{
			printf("첫 번째 주사위가 홀수입니다. 보너스 주사위를 굴리지 않습니다.\n");
		}
		printf("\n");
	}

	for (i = 0; i < 2; i++)  // 두번째 플레이어 주사위 굴리기
	{
		int index_first = i;
		player_each_dice_number[index_first] = generate_random(min, max);
		printf("두번째 플레이어가 주사위를 굴립니다.\n");
		printf("\n");
		printf("플레이어의 %d 번째 주사위 눈금은 %d\n", index_first, player_each_dice_number[index_first]);
		int remainder;
		remainder = player_each_dice_number[index_first] % 2;
		if (remainder == 0)
		{
			printf("첫 번째 주사위가 짝수입니다. 보너스 주사위를 굴립니다.\n");
			for (n = 1; n < 2; n++)
			{
				int index_second = n;
				player_each_dice_number[index_second] = generate_random(min, max);
				printf("플레이어의 %d 번째 주사위 눈금은 %d\n", index_second, player_each_dice_number[index_second]);
				printf("점수를 획득합니다. %d\n", player_each_dice_number[index_second]);
				score_player1 += player_each_dice_number[index_second];
				if (player_each_dice_number[index_second] == 2)
				{
					bonus_point_player1 = 3;
					printf("보너스 점수를 획득합니다. %d\n", bonus_point_player1);
					score_player1 += bonus_point_player1 - attack_point_player0;
				}
				else if (player_each_dice_number[index_second] == 3)
				{
					attack_point_player1 = 4;
					printf("상대의 점수를 깎습니다. %d\n", attack_point_player1);
					score_player0 -= attack_point_player1;
				}
				else if (player_each_dice_number[index_second] == 4)
				{
					printf("플레이어가 자살했습니다.\n");
				}
			}
		}
		else if (remainder == 1)
		{
			printf("첫 번째 주사위가 홀수입니다. 보너스 주사위를 굴리지 않습니다.\n");
		}
		printf("\n");
	}

	//	int score_player1 = score_player1 + bonus_point_player1 - attack_point_player0;

	printf("0 번 플레이어의 점수는 %d\n", score_player0);
	printf("1 번 플레이어의 점수는 %d\n", score_player1);
	printf("\n");

	if (score_player0 > score_player1)
	{
		printf("0 번 플레이어가 승리했습니다.\n");
	}
	else if (score_player0 < score_player1)
	{
		printf("1 번 플레이어가 승리했습니다.\n");
	}
	else if (score_player0 == score_player1)
	{
		printf("무승부 입니다.\n");
	}

	//print_dice_number(0);
	//print_dice_number(1);


	/*
	void input(int a[], int cnt);
	{
		int a;
		printf("점수를 입력하세요 \n");
		printf("값 입력 : ");
		scand("%d",a);
	}

	bool pass(int a, int cnt)
	{
		int hap = 0;
		if (a < 40) return false;
		return true;
	}
	*/


	return 0;

}