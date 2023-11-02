#include <stdio.h>
#include "dice_game.h"
#include "player.h"
#include <stdlib.h>
#include <time.h>


int main(void)
{
	
	char player1[PLAYER_NAME_MAX]; // 사용자1 
	char player2[PLAYER_NAME_MAX]; // 사용자2

	int dice1; // 사용자 1의 주사위
	int dice2; // 사용자 2의 주사위


	// 사용자1 정의
	set_player_name("김영희");
	strcpy(player1, player_name);
	print_player_name();

	// 사용자1의 주사위
	srand(time(NULL));
	roll_dice();
	dice1 = dice_number;
	print_dice_number();
	
	// 사용자2 정의
	set_player_name("김철수");
	strcpy(player2, player_name);
	print_player_name();

	// 사용자2 주사위
	roll_dice();
	dice2 = dice_number;
	print_dice_number();


	if (dice1 > dice2)
	{
		printf("이긴 사람은:%s", player1);
	} 
	
	else if (dice2 > dice1)
	{
		printf("이긴 사람은:%s", player2);
	}
	else
	{
		printf("무승부입니다.");
	}
	

	return 0;
}