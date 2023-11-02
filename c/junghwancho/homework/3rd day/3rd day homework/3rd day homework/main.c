#include <stdio.h>
#include <dice_game.h>
#include <player.h>

#define LOOP_MAX		10

int main(void)
{
	int loop_count = 0;


	while (loop_count++ < LOOP_MAX)
	{
		roll_dice();
		print_dice_number();

		set_player_name_one("first");
		set_player_name_one("second");

		print_player_name_one();
		print_player_name_two();
	}

	return 0;

}
