#include <stdio.h>
#include "dice_fight.h"
#include "random_generator.h"

#define MAX		6
#define MIN		1

int dice_number_player1 = 0;
int dice_number_player2 = 0;

int roll_dice_player1(void)
{
	dice_number_player1 = generate_random_player1(MIN, MAX);
}

int roll_dice_player2(void)
{
	dice_number_player2 = generate_random_player2(MIN, MAX);
}

void dice_fight(char player1[], char player2[])
{
	printf("%s, %s의 주사위 게임이 시작됩니다.\n", player1, player2);

	int roll_player1 = roll_dice_player1();
	int roll_player2 = roll_dice_player2();

	printf("%s의 주사위 번호는 %d 입니다.\n", player1, dice_number_player1);
	printf("%s의 주사위 번호는 %d 입니다.\n", player2, dice_number_player2);

	if (dice_number_player1 > dice_number_player2)
	{
		printf("%s의 승리입니다.\n", player1);
			}

	else if (dice_number_player2 > dice_number_player1)
	{
		printf("%s의 승리입니다.\n", player2);
		}

	else
	{
		printf("무승부입니다.\n");
	} 

}