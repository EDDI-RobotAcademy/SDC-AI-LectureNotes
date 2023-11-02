#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include "player.h"

#define PLAYER_NAME_MAX			32

char player_name[PLAYER_NAME_MAX];

void set_player_name(char name[])
{
	const int player_name_length = strlen(name);
	strncpy(player_name, name, player_name_length + 1);
}

void print_player_name(void)
{
	printf("°ÇÅõ¸¦ º÷´Ï´Ù! %s´Ô!\n", player_name);
}