#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "player.h"

char* player_name[MAX_PLAYER_NUMBER];
int current_player_set_index;

void set_player_info(char* name)
{
	player_name[current_player_set_index] = (char*)malloc(sizeof(char) * (strlen(name) + 1));

	strncpy(player_name[current_player_set_index++], name, strlen(name) + 1);
}

void print_player_info(int player_number)
{
	printf("사용자 %d 의 이름은 = %s\n", player_number, player_name[player_number]);
}