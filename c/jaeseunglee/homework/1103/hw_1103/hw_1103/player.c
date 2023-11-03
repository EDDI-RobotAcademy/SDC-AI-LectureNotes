#define _CRT_SECURE_NO_WARNINGS

#include "player.h"
#include <stdio.h>
#include <string.h>



char player[MAX_PLAYER_NUMBER][MAX_PLAYER_NAME_LENGTH];
int current_player_set_index;

char* player1;
char* player2;

void set_player_info(char* name)
{
	int input_player_name_length = strlen(name);
	strncpy(player[current_player_set_index++], name, input_player_name_length + 1);

}

void print_player_info(int index)
{
	printf("Player%d 의 이름은 = %s\n", index, player[index]);


}

char* get_player_info(int index)
{
	return player[index];
}