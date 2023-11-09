#include <stdio.h>
#include "player.h"
#include "random_generator.h"
#include "dice.h"
#include "win.h"

int main(void) {
	set_player_name("player1");
	set_player_name("player2");

	print_player_name();

	random_config();

	roll_dice(0);
	roll_dice(1);

	print_dice();
	
	check_win();

	return 0;
}