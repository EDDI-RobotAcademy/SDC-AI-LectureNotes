#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include "player2.h"

#define PLAYER_NAME_MAX				32

char player_two_name[PLAYER_NAME_MAX];

void set_player_two_name(char name[])
{
	const int play_name_length = strlen(name);

	strncpy(player_two_name, name, play_name_length + 1);
}

void print_player_name(void)
{
	printf("\n사용자2 이름은 %s\n", player_two_name);
}