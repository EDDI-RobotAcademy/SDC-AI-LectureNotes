#include <stdio.h>
#include <time.h>
#include "dice_game.h"
#include "player.h"

char player_name[PLAYER_NAME_MAX];

int main(void)
{
	int first_player_dice_number = 1;
	int second_player_dice_number = 0;
	char first_player_name[PLAYER_NAME_MAX] = "john";
	char second_player_name[PLAYER_NAME_MAX] = "cassy";

	srand(time(NULL));

	set_player_name(first_player_name);
	print_player_name();
	first_player_dice_number = dice_roll();
	print_dice_number();

	set_player_name(second_player_name);
	print_player_name();
	second_player_dice_number = dice_roll();
	print_dice_number();

	while (first_player_dice_number == second_player_dice_number)
	{
		first_player_dice_number = dice_roll();
		second_player_dice_number = dice_roll();
	}

	if (first_player_dice_number > second_player_dice_number)
	{
		printf("½ÂÀÚ : %s\n", first_player_name);
	}
	else
	{
		printf("½ÂÀÚ : %s\n", second_player_name);
	}

	return 0;
}