#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>

#include "player.h"

char* player_name_array[MAX_PLAYER_NUMBER];
int player_count;

void create_player_name_array(char* name)
{
	player_name_array[player_count] = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strncpy(player_name_array[player_count], name, strlen(name) + 1);
	player_count++;
}

void print_player_name_to_array(void)
{
	int loop_count;

	for (loop_count = 0; loop_count < player_count; loop_count++)
	{
		printf("플레이어 %d 이름 = %s\n", loop_count, player_name_array[loop_count]);
	}
}