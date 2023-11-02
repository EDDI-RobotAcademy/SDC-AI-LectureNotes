# define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "player.h"

// 데이터 타입 char (1byte) <- 문자 저장 가능
char player_name[PLAYER_NAME_MAX];

void set_player_name(char name[])
{
	// string length의 약자로 문자열의 길이를 구할 때 사용
	const int player_name_length = strlen(name);
	// strncpy 는 문자열을 지정한 숫자만큼 복사
	// strncpy (복사될 위치, 복사할 대상, 복사할 개수)
	//			복사할 개수는 문자 (글자 1개) 단위로 이루어짐
	//			추가적으로 한글은 한 글자당 2~3byte 씩 소요되어 예상과 다른 숫자가 나올 수 있음

	strncpy(player_name, name, player_name_length + 1);

}

void print_player_name(void)
{
	// %s 는 문자열을 출력할 때 사용 (문장 출력)
	printf("사용자 이름은 %s\n", player_name);
}