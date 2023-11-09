#include <stdio.h>
#include "player.h"

char player[PLAYER_COUNT][PLAYER_NAME_LENGTH];
int player_index = 0;

void set_player_name(char name[]) {
	strncpy(player[player_index++], name, strlen(name) + 1);
}

void print_player_name(void) {
	int i;

	for (i = 0; i < PLAYER_COUNT; i++) {
		printf("%d번째 player의 이름은 %s입니다.\n", i + 1, player[i]);
	}
}