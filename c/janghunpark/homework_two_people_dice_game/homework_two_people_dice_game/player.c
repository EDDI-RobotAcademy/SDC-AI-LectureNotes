#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include "player.h"

#define PLAYER_NAME_MAX			32

char player_name1[PLAYER_NAME_MAX];
char player_name2[PLAYER_NAME_MAX];

void set_player_name1(char name1[])
{
	const int player1_name_length = strlen(name1);
	strncpy(player_name1, name1, player1_name_length + 1);
}

void print_player_name1(void)
{
	printf("°ÇÅõ¸¦ º÷´Ï´Ù! %s´Ô!\n", player_name1);
}

void set_player_name2(char name2[])
{
	const int player2_name_length = strlen(name2);
	strncpy(player_name2, name2, player2_name_length + 1);
}

void print_player_name2(void)
{
	printf("°ÇÅõ¸¦ º÷´Ï´Ù! %s´Ô!\n", player_name2);
}