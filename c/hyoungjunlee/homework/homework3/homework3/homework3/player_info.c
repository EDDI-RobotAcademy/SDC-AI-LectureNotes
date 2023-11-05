#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player_info.h"

char player_name[PLAYER_NUMBER][PLAYER_NAME_LENGTH];
int player_index = 0;

void input_player_name(char name[])
{
	int input_player_name_length = strlen(name);
	
	
	strncpy(player_name[player_index++], name, input_player_name_length+1 );

}
