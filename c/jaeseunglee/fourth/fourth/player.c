#define _CRT_SECURE_NO_WARNINGS

#include "player.h"
#include <stdio.h>
#include <string.h>


// 어셈블리어 코드에서도 봤듯이 메모리에 차원[Dimension]개념은 없음
// 다차원 배열 X => 다중 배열

// 실제 아래 코드는 player[2][32]형태로 구성
// 그러모르 32개짜리가 2개 있다는 뜻
// 실제 메모리를 살펴 볼 때 아래와 같은 형태의 결과가 나옴
//					   0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
// 
// 0x00007FF6FA8AD900  66 69 72 73 74 5f 70 6c 61 79 65 72 00 00 00 00  first_player....
// 0x00007FF6FA8AD910  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
// 
// 0x00007FF6FA8AD920  73 65 63 6f 6e 64 5f 70 6c 61 79 65 72 00 00 00  second_player...
// 0x00007FF6FA8AD930  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00

// 결론적으로 배열이 되었든 다중 배열이 되었든 전부 메모리의 열거일 뿐
char player[MAX_PLAYER_NUMBER][MAX_PLYAER_NAME_LENGTH];

// ex) test[3][2][10]
// => 10개의 공간이 2개 있는게 3개있음
// 총 메모리 크기 == 3*2*10 = 60
// 
// 10
// 10
// 
// 10
// 10
//
// 10
// 10

// int 전역변수는 자동으로 '0'으로 초기화됨
int current_player_set_index;

void set_player_info(char name[])
{
	int input_player_name_length = strlen(name);
	// player[2][32]에서 current_player_set_index를 통해
	// 0번 1번을 제어하고자 하는 목적
	// 배열의 크기가 가변적이지 않다는 점이 단점

	// *********** 배열의 인덱스 시작은 0부터 시작				**********************
	// *********** 혼동이 발생하는 대표적인 원인은				**********************
	// *********** 배열을 만들 때 사용할 갯수를 적고			**********************
	// *********** 사용을 할 때에는 0부터 시작해서 발생하는 혼동**********************

	// 배열의 이름은 배열의 시작 주소
	// player배열 주소 == player[0] 주소
	strncpy(player[current_player_set_index++], name, input_player_name_length + 1);
	
}

void print_player_info(int index)
{
	printf("사용자 %d 의 이름은 = %s\n", index, player[index]);
}