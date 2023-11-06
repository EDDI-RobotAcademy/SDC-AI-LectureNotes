#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>

#include "player.h"

char player1_name[PLAYER_NAME_MAX];
char player2_name[PLAYER_NAME_MAX];


void set_player1_name(char name[])
{
	const int palyer_name_length = strlen(name);

	strncpy(player1_name, name, palyer_name_length + 1);

}
void set_player2_name(char name[])
{
	const int palyer_name_length = strlen(name);

	strncpy(player2_name, name, palyer_name_length + 1);

}
void print_player1_name(void)
{
	printf("사용자1 이름은 %s\n", player1_name);
}

void print_player2_name(void)
{
	printf("사용자2 이름은 %s\n", player2_name);
}