#include <stdio.h>
#include <time.h>
#include "dice_game.h"
#include "player.h"

char player_name[PLAYER_NAME_MAX];

int main(void)
{
	int first_player_dice_number = 0;
	int second_player_dice_number = 0;
	char first_player_name[PLAYER_NAME_MAX] = "john";
	char second_player_name[PLAYER_NAME_MAX] = "cassy";

	srand(time(NULL));

	set_player_name(first_player_name);
	print_player_name(first_player_name);
	first_player_dice_number = dice_roll();
	print_dice_number();

	set_player_name(second_player_name);
	print_player_name(second_player_name);
	second_player_dice_number = dice_roll();
	print_dice_number();

	while (first_player_dice_number == second_player_dice_number)
	{
		printf("주사위 숫자가 같으므로 다시 돌립니다.\n");
		printf("사용자 : %s\n", first_player_name);
		first_player_dice_number = dice_roll();
		print_dice_number();
		printf("사용자 : %s\n", second_player_name);
		second_player_dice_number = dice_roll();
		print_dice_number();
	}

	if (first_player_dice_number > second_player_dice_number)
	{
		printf("승자 : %s\n", first_player_name);
	}
	else
	{
		printf("승자 : %s\n", second_player_name);
	}

	return 0;
}