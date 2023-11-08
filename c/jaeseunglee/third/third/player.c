#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include "player.h"




// 데이터 타입 char (1byte) <- 문자를 저장 할 수 있음
// 배열을 만드는 방법
// -> 변수 만드는 방법과 유사함
// 1. 데이터 타입을 선언
// 2. 배열의 이름을 선언
// 3. 대괄호를 열고 배열의 크기를 적습니다. ex) [PLAYER_NAME_MAX]
// 4. 필요하다면 초기화를 합니다.(우선은 배제합니다)
char player_name[PLAYER_NAME_MAX];
char player1[PLAYER_NAME_MAX];
char player2[PLAYER_NAME_MAX];



void set_player_name(char name[])
{
	// string length 의 약자로 문자열의 길이를 구합니다.
	const int player_name_length = strlen(name);

	// strncpy 는 문자열을 지정한 숫자만큼 복사합니다.
	// strncpy(복사 될 위치, 복사 할 녀석, 복사 할 갯수)
	//         복사 할 갯수는 문자(글자 1개)단위로 이루어집니다.
	//         추가적으로 한글은 한 글자당 2~3byte씩 먹으므로 예상과 다른 숫자가 나올 수 있습니다.
	strncpy(player_name, name, player_name_length + 1);
}

void set_player1(char name[])
{
	const int player1_name_length = strlen(name);
	strncpy(player1, name, player1_name_length + 1);
	
}

void set_player2(char name[])
{
	const int player2_name_length = strlen(name);
	strncpy(player2, name, player2_name_length + 1);

}



char *set_name(char name[])
{
	
	char *temp[PLAYER_NAME_MAX];
	
	const int temp_name_length = strlen(name);
	strncpy(temp, name, temp_name_length + 1);
	printf("%s\n\n\n\n",temp);
	return temp;
}


void print_player_name(void)
{
	// %s는 문자열을 출력 할 때 사용합니다. (문장)
	printf("사용자 이름은 %s\n", player_name);
}