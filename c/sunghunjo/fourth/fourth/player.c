#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include "player.h"

// 배열의 시작은 indec 0번부터 시작합니다.
// 주의사항 => 어셈블리어 코드에서도 봤듯이 메모리에 차원(Dimension) 개념은 없습니다.
// 그래서 다차원 배열이라는 표현 보다는 근본있게 '다중 배열' 이라고 합시다.

// 실제 아래 코드는 player_name[2][32] 형태로 구성됩니다.
// 그러므로 32개 짜리가 2개 있다는 뜻이 됩니다.
// 고로 실제 메모리를 살펴 볼 때 아래와 같은 형태의 결과가 나옵니다.
// 
//					  0  1  2  3  4  5  6  7   [한 줄당 8개]
// 
//0x00007FF7F562D900  66 69 72 73 74 5f 70 6c  first_pl
//0x00007FF7F562D908  61 79 65 72 00 00 00 00  ayer....
//0x00007FF7F562D910  00 00 00 00 00 00 00 00  ........	
//0x00007FF7F562D918  00 00 00 00 00 00 00 00  ........		<<<- 4줄이니까 32


//0x00007FF7F562D920  73 65 63 6f 6e 64 5f 70  second_p
//0x00007FF7F562D928  6c 61 79 65 72 00 00 00  layer...
//0x00007FF7F562D930  00 00 00 00 00 00 00 00  ........
//0x00007FF7F562D938  00 00 00 00 00 00 00 00  ........		<<<- 4줄이니까 32

// 결론적으로 배열이 되었든 다중 배열이 되었든 전부 메모리의 열거일 뿐
char player_name[MAX_PLAYER_NUMBER][MAX_PLAYER_NAME_LENGTH];
int current_player_set_index;

// ex) test[3][2][10]
//		이 형태라면 10개의 공간이 2개 있음
//		즉 20개짜리 공간이 됨
//		이 20개짜리 공간이 3개 있다는 뜻이 됨
//		결론적으로 총 60개의 공간을 가짐 

void set_player_info(char name[])
{
	int input_player_name_length = strlen(name);
	// player_name[2][32]에서 current_player_set_index를 통해
	// 0번, 1번을 제어하고자 하는 목적

	// ******** 배열의 인덱스 시작은 0부터 시작합니다 *********
	// ******** 혼동이 발생하는 대표적인 원인은
	//			배열을 만들 때는 사용할 개수를 직접적고
	//			사용 할 때는 0번 부터 시작해서 발생하는 혼동입니다.*********

	// * 배열의 이름은 배열의 시작주소
	strncpy(player_name[current_player_set_index++], name, input_player_name_length + 1);
}

void print_player_info(int index)
{
	printf("사용자 %d 의 이름은 = %s\n", index, player_name[index]);
}