#include <stdio.h>
#include "dice_game.h"
#include "player1.h"
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int dice1; 
	int dice2;

	char player1;
	char player2;

	set_player_name1("김영희");
	player1 = player_name;
	print_player_name1();
	srand(time(NULL));
	roll_dice();
	dice1 = dice_number;
	print_dice_number();
	

	set_player_name1("김철수");
	player2 = player_name;
	print_player_name1();
	srand(time(NULL));
	roll_dice();
	dice2 = dice_number;
	print_dice_number();


	if (dice1 > dice2)
	{
		printf("이긴 사람은:%d", player1);
	} 
	
	else if (dice2 > dice1)
	{
		printf("이긴 사람은: %d", player2);
	}
	else
	{
		printf("무승부입니다.");
	}
	

	return 0;
}