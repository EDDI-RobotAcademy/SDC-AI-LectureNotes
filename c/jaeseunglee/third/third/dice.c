#include <stdio.h>
#include <stdlib.h>
#include "random_generator.h"
#include "dice.h"
#include "player.h"

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

//void dice_fight(int player1, int player2)
//{
//	
//	if (player1 == player2)
//	{
//		printf("자기 자신과 싸웁니다!\n");
//	}
//	else
//	{
//		printf("참가번호 %d, 참가번호 %d의 싸움이 시작됩니다!\n", player1, player2);
//
//		int dice_player1 = roll_the_dice();
//		int dice_player2 = roll_the_dice();
//
//		printf("참가번호 %d의 주사위 숫자는 %d!\n참가번호 %d의 주사위 숫자는 %d!\n", player1, dice_player1, player2, dice_player2);
//
//		if (dice_player1 > dice_player2)
//		{
//			printf("참가번호 %d의 승리입니다!\n축하합니다!\n", player1);
//		}
//		else if(dice_player1 < dice_player2)
//		{
//			printf("참가번호 %d의 승리입니다!\n축하합니다!\n", player2);
//		}
//		else
//		{
//			printf("무승부입니다!\n한 치 앞도 내다볼 수 없군요! \n");
//		}
//	} 
//}



// 함수를 선언하고, 각 플레이어의 이름을 파라메터로써 받아올 수 있도록 합니다.
void dice_fight(char player1[], char player2[])
{
	printf("%s, %s의 싸움이 시작됩니다!\n", player1, player2);


	// 각각 플레이어가 주사위를 굴리는 상황입니다. 
	// int 지역 변수를 선언하여 후에 쓸 수 있도록 저장합니다.
	int dice_player1 = roll_the_dice();
	int dice_player2 = roll_the_dice();

	printf("%s의 주사위 숫자는 %d!\n%s의 주사위 숫자는 %d!\n", player1, dice_player1, player2, dice_player2);

	// 각 플레이어의 주사위 크기를 비교합니다.
	// if / else if / else 부분은 전부 if로 대체하여도 현재는 크게 상관없습니다.

	if (dice_player1 > dice_player2)
	{
		// player1의 주사위 수가 클 경우 player1이 이겼다는 문장을 출력합니다.
		printf("%s의 승리입니다!\n축하합니다!\n", player1);
	}
	else if (dice_player1 < dice_player2)
	{
		// player2의 주사위 수가 클 경우 player2가 이겼다는 문장을 출력합니다.
		printf("%s의 승리입니다!\n축하합니다!\n", player2);
	}
	else
	{
		// 두 숫자가 같을 경우 무승부라는 문장을 출력합니다.
		printf("무승부입니다!\n한 치 앞도 내다볼 수 없군요! \n");
	}
	
}