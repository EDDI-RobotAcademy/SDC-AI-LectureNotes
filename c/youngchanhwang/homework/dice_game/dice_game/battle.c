#include "battle.h"
#include "player.h"
#include "dice.h"
#include <stdio.h>

void battle(char player1_name[], char player2_name[])
{
	dice_roll();
	const int player1_dice_number = dice_number;
	printf("%s 의 주사위는 %d\n", player1_name, player1_dice_number);



	dice_roll();
	const int player2_dice_number = dice_number;
	printf("%s 의 주사위는 %d\n", player2_name, player2_dice_number);

	if (player1_dice_number > player2_dice_number) 
	{
		printf("%s의 승리입니다!\n", player1_name);
	}
	else if (player1_dice_number < player2_dice_number)
	{
		printf("%s의 승리입니다!\n", player2_name);
	}
	else 
	{
		printf("비겼습니다.");
	}


}