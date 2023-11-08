#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "player.h"

char player_name[PLAYER_NAME_MAX];
int current_player_set_index;

void set_player_name_one(char name[])
{
	int input_player_name_length = strlen(name);
	strncpy(player_name[current_player_set_index++], name, input_player_name_length + 1);
}

void set_player_name_two(char name[])
{
	int input_player_name_length = strlen(name);
	strncpy(player_name[current_player_set_index++], name, input_player_name_length + 1);
}

void print_player_name_one(int index)
{
	printf("first_player = %d\/", index, player_name);
}

void print_player_name_two(int index)
{
	printf("second_player = %d\/", index, player_name);
}