#include <stdio.h>

#include "game.h"
#include "player.h"
#include "dice.h"
#include "random.h"
#include "common.h"

void playe_game()
{
	int loop;
	char* nickname[MAX_PLAYER_NUMBER] = {
		"탱커",
		"힐러"
	};

	printf("퀴즈 풀이\n");

	for (loop = 0; loop < MAX_PLAYER_NUMBER; loop++)
	{
		init_player_nickname(nickname[loop]);
	}

	print_player_list();

	random_seed_config();

	for (loop = 0; loop < MAX_PLAYER_NUMBER; loop++)
	{
		int firse_dice_number = roll_dice();
		printf("첫 번째 주사위 눈금: %d\n", firse_dice_number);

		if (check_even(firse_dice_number))
		{
			int second_dice_number = roll_dice();
			printf("스킬을 발동합니다!\n");

			//apply_dice_skill();
		}
	}
}