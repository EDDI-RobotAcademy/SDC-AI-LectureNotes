# define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "player.h"

char player1[PLAYER_NAME_MAX];
char player2[PLAYER_NAME_MAX];

void set_player1(char name[])
{
	const int player1_length = strlen(name);
	strncpy(player1, name, player1_length + 1);
}

void set_player2(char name[])
{
	const int player2_length = strlen(name);
	strncpy(player2, name, player2_length + 1);
}