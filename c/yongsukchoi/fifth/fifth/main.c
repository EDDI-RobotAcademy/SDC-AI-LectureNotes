#include <stdio.h>
#include "player.h"

int main(void) {
	int loop;
	char* nickname[MAX_PLAYER_NUMBER] = {
		"입벌려힐들어간다",
		"주님곁으로"
	};

	printf("퀴즈 풀이!\n");
	for (loop = 0; loop < MAX_PLAYER_NUMBER; loop++) {
		init_player_nickname(nickname[loop]);
	}
	print_player_list();

	return 0;
}