#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "player.h"


// 데이터 타입 char (1byte) <- 문자를 저장할 수 있음
// 배열을 만드는 방법
// - 변수 만드는 방법과 유사함
// 1. 데이터 타입을 적음
// 2. 배열의 이름을 적음
// 3. 대괄호를 열고 배열의 개수를 적음 ex) [PLAYER_NAME_MAX]
// 4. 필요하다면 초기화를 하는데 우선은 배제

char player_name[PLAYER_NAME_MAX];

void set_player_name(char name[])
{
	// strlen: string length의 약자로 문자열의 길이를 구함
	const int player_name_length = strlen(name);

	// strncpy: 문자열을 지정한 숫자만큼 복사
	// strncpy(복사될 위치, 복사할 녀석, 복사할 개수)
	//         복사할 개수는 문자(글자 1개) 단위로 이루어짐
	//         추가적으로 한글은 한 글자당 2~3byte씩 먹으므로 예상과 다른 숫자가 나올 수 있음
	strncpy(player_name, name, player_name_length + 1);

}

void print_player_name(void)
{
	// %s는 문자열을 출력할 때 사용(문장 출력)
	printf("사용자 이름은 %s\n", player_name);
}