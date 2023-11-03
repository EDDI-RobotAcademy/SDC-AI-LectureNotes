#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "player.h"

// 배열의 시작은 index 0번부터 시작
// 주의사항: 어셈블리어 코드에서도 봤듯 메모리에 차원(DImension) 개념은 X
// 다차원 배열이라는 표현보다 '다중 배열'
char player[MAX_PLAYER_NUMBER][MAX_PLAYER_NEME_LENGTH];
int current_player_set_index;

void set_player_info(char name[])
{
	int input_player_name_length = strlen(name);

	strncpy(player[current_player_set_index++], name, input_player_name_length + 1);
	
		
}

void print_player_info(int index)
{
	printf("사용자 %d의 이름은= %s\n", index, player[index]);
}