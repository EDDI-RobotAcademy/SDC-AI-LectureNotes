#include <stdio.h>
#include "dice_game.h"
#include "player1.h"
#include "player2.h"
#include "print_random.h"

#define LOOP_MAX		1

int main(void)
{
	int loop_count = 0;

	while (loop_count++ < LOOP_MAX)
	{
		roll_dice();
		print_dice_number();
	}
	
	set_player_name("Hello");
	print_player_name();

	return 0;
}