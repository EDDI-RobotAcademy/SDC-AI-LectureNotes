#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "player.h"

char player_name[PLAYER_NAME_MAX];

void set_player_name(char name[])
{
	const int player_name_length = strlen(name);

	strncpy(player_name, name, player_name_length + 1);
	return player_name;
}

void print_player_name(void)
{
	printf("사용자의 이름 : %s\n", player_name);
}