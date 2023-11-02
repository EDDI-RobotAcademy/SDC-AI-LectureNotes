#include <stdio.h>
#include "dice_game.h"
#include "player.h"



int main(void)
{
	char player1_name;
	char player2_name;
	int player1_score = 0;
	int player2_score = 0;

	set_player_name("alpha");
	player1_name = player_name;
	print_player_name();
	set_player_name("beta");
	player2_name = player_name;
	print_player_name();

	
	roll_dice();
	player1_score = dice_number;

	roll_dice();
	player2_score = dice_number;

	
	if (player1_score < player2_score)
	{
		printf("%s는 %d %s는 %d으로 %s가 이겼습니다.", player1_name, player1_score, player2_name, player2_score, player2_name);
	}
	



	return 0;
}