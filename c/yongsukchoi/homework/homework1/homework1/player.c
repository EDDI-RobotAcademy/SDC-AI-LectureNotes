#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "player.h"

char player[PLAYER_COUNT][PLAYER_NAME_LENGTH];
int player_index;

void set_player_name(char name[]) {
	strncpy(player[player_index++], name, strlen(name) + 1);
}

void print_player_name(void) {
	int i;

	for (i = 0; i < PLAYER_COUNT; i++) {
		printf("%d번째 사용자는 %s입니다.\n", i + 1, player[i]);
	}
}