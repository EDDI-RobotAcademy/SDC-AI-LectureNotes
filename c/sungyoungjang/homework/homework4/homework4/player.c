#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include "player.h"


char player[MAX_PLAYER_NAME_LENGTH][MAX_PLAYER_NAME_LENGTH];
int current_player_set_index;

void set_player_info(char name[])
{
	int input_player_name_length = strlen(name);

	strncpy(player[current_player_set_index++], name, input_player_name_length + 1);
}

void print_player_info(int index)
{
	printf("사용자 %d 의 이름은 =%s\n", index, player[index]);
}
