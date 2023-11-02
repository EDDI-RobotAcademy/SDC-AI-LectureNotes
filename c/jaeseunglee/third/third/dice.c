#include <stdio.h>
#include <stdlib.h>
#include "random_generator.h"
#include "dice.h"

int roll_the_dice()
{
	int dice_number = generate_random(1, 6);
	
	
	return dice_number;
}

//int roll_the_dice(int max)
//{
//	int dice_number = generate_random(1, max);
//
//
//	return dice_number;
//}

void dice_fight(int player1, int player2)
{
	
	if (player1 == player2)
	{
		printf("자기 자신과 싸웁니다!\n");
	}
	else
	{
		printf("참가번호 %d, 참가번호 %d의 싸움이 시작됩니다!\n", player1, player2);

		int dice_player1 = roll_the_dice();
		int dice_player2 = roll_the_dice();

		printf("참가번호 %d의 주사위 숫자는 %d!\n참가번호 %d의 주사위 숫자는 %d!\n", player1, dice_player1, player2, dice_player2);

		if (dice_player1 > dice_player2)
		{
			printf("참가번호 %d의 승리입니다!\n축하합니다!\n", player1);
		}
		else if(dice_player1 < dice_player2)
		{
			printf("참가번호 %d의 승리입니다!\n축하합니다!\n", player2);
		}
		else
		{
			printf("무승부입니다!\n한 치 앞도 내다볼 수 없군요! \n");
		}
	} 
}