#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "player.h"


char player_name[PLAYER_NAME_MAX];

void set_player_name(char name[])
{
	const int player_name_length = strlen(name);

	strncpy(player_name, name, player_name_length + 1);

}

void print_player_name(void)
{
	// %s는 문자열을 출력할 때 사용(문장 출력)
<<<<<<< HEAD
	printf("사용자 이름은: %s\n", player_name);
=======
	printf("사용자 이름: %s\n", player_name);
>>>>>>> ff1371bda160b8833fb064d2b66a1bd8bbf7e7fb
}