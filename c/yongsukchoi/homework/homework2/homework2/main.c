#include <stdio.h>
#include "player.h"
#include "roll_dice.h"
#include "win.h"
#include "random_generator.h"

int main(void) {
	set_player_name("player1");
	set_player_name("player2");

	print_player_name();

	random_config();

	play_roll_dice();

	print_winner();

	return 0;
}