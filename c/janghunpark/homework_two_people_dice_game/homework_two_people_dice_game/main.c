#include <stdio.h>
#include "dice_game.h"
#include "player.h"

#define NUMBER_OF_PLAYER_MAX	2

int main(void)
{
	set_player_name1("hello");
	print_player_name1();
	roll_dice1();
	print_dice_number1();

	set_player_name2("goodbye");
	print_player_name2();
	roll_dice2();
	print_dice_number2();

	return 0;
}