#include <stdio.h>
#include "dice_game.h"
#include "player.h"

#define NUMBER_OF_PLAYER_MAX	2

int main(void)
{
	int number_of_player = 0;
	
	while (number_of_player++ < NUMBER_OF_PLAYER_MAX)
	{
		set_player_name("박장훈");
		print_player_name();
		roll_dice();
		printf("%d번 플레이어님 숫자 = %d\n", number_of_player, dice_number);
	}
}