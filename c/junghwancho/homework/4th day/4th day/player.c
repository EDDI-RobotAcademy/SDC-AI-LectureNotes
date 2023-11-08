#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //printf function
#include <string.h> //strncpy function < user 이름 copy 기능
#include "player.h"

char player[MAX_PLAYER_NUMBER][MAX_PLAYER_NAME_LENGTH]; // MAX player, MAX player name 정의 
int current_player_set_index; // 현재 play 수 정의 지표, 초기 0

void set_player_info(char name[]) // [] 배열이 들어오면 player 숫자 카운트 및 이름 설정
{
	int input_player_name_length = strlen(name); // player 이름 길이 검사
	strncpy(player[current_player_set_index++], name, input_player_name_length + 1);
	// 검사된 이름에 1 byte 더해주고, 현재 player 숫자 카운트
}

void print_player_info(int index)
{
	printf("player %d = %s\n", index, player[index]);
}