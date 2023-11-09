#include "game.h"
#include "player.h"
#include "dice.h"
#include "random.h"

#include <stdio.h>

void play_game(void) {
	int loop;
	char* nickname[MAX_PLAYER_NUMBER] = {
		"입벌려힐들어간다",
		"주님곁으로"
	};

	printf("사용자 닉네임 생성\n");
	for (loop = 0; loop < MAX_PLAYER_NUMBER; loop++) {
		init_player_nickname(nickname[loop]);
	}
	print_player_list();

	random_seed_config();
	for (loop = 0; loop < MAX_PLAYER_NUMBER; loop++) {
		int returned_dice = roll_dice();
		printf("주사위 눈금: %d\n", returned_dice);
	}
}