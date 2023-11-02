#include <stdio.h>
#include "dice_game.h"
#include "player.h"

#define NUMBER_OF_PLAYER_MAX	2

int main(void)
{
	int player_count = 0;

	set_player_name("hello");
	print_player_name();
	roll_dice();
	print_dice_number();

	set_player_name("goodbye");
	print_player_name();
	roll_dice();
	print_dice_number();

	return 0;
}