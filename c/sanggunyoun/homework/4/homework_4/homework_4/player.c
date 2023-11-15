#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>

#include "player.h"

char* player_nickname[MAX_PLAYER_NUMBER];
int player_count;

void init_player_nickname(char* nickname)
{
	int nickname_length = strlen(nickname);
	player_nickname[player_count] = (char*)malloc(sizeof(char) * nickname_length);
	strncpy(player_nickname[player_count], nickname, nickname_length + 1);

	player_count++;
}

void print_player_list(void)
{
	int loop_count;

	for (loop_count = 0; loop_count < player_count; loop_count++)
	{
		printf("사용자 %d: 닉네임: %s\n", loop_count, player_nickname[loop_count]);
	}
}

