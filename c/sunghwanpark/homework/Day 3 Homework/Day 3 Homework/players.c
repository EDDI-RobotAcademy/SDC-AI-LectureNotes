#define _CRT_SECURE_NO_WARNINGS 
#include <string.h>
#include "players.h"
#define number_of_players  2

char player_name[PLAYER_NAME_MAX];

void set_player_name(char name[])
{
	const int player_name_length = strlen(name);
	strncpy(player_name, name, player_name_length + 1);
}
void print_player_name(void)
{
	printf("사용자 이름은 %s\n", player_name);
}



