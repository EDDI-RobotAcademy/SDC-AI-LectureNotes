# define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "player.h"

// 데이터 타입 char (1byte) <- 문자 저장 가능
// 배열을 만드는 방법
// -> 변수 만드는 방법과 유사함
// 1. 데이터 타입을 적는다.
// 2. 배열의 이름을 적는다.
// 3. 대괄호를 열고 배열의 개수를 적는다. ex) [PLAYER_NAME_MAX]
// 4. 필요하다면 초기화를 하는데 우선은 배제한다.
char player_name[PLAYER_NAME_MAX];
char player1[PLAYER_NAME_MAX];
char player2[PLAYER_NAME_MAX];

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

void set_player1(char name[])
{
	const int player1_length = strlen(name);
	strncpy(player1, name, player1_length + 1);
}

void set_player2(char name[])
{
	const int player2_length = strlen(name);
	strncpy(player2, name, player2_length + 1);
}

void print_player_name(void)
{
	// %s 는 문자열을 출력할 때 사용 (문장 출력)
	printf("사용자 이름은 %s\n", player_name);
}