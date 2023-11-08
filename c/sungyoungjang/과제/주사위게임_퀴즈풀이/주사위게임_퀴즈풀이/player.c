#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>

#include "player.h"

char* player_nickname[MAX_PLAYER_NUMBER];
int player_count;

void init_player_nickname(char* nickname)
{
	int nickname_length = strlen(nickname);
	player_nickname[player_count] = (char*)malloc(sizeof(char) * nickname_length);
	strncpy(player_nickname[player_count], nickname, nickname_length + 1);

	player_count++;
}
/*init_player_nickname 함수는 플레이어의 닉네임을 초기화 하여 배열에 저장합니다.
이 함수는 문자열의 길이 만큼 메모리를 할당 후, 해당 메모리의 문자열을 복사후 닉네임에 저장.*/

void print_player_list(void)
{
	int loop_count;

	for (loop_count = 0; loop_count < player_count; loop_count++)
	{
		printf("사용자 %d: 닉네임: %s\n", loop_count, player_nickname[loop_count]);
	}
}
/*print_player_list 현재까지 등록된 플레이어의 목록을 출력하는 함수.
player_nickname 에 저장된 플레이어를 출력하고, 각 플레이어를 보여줌.*/