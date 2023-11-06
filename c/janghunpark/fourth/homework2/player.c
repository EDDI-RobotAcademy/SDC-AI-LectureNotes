#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "player.h"

// 배열의 시작은 index 0번부터 시작됩니다.
// 주의사항 => 어셈블리어 코드에서도 봤듯이 메모리에 차원(dimension) 개념은 없습니다.
// 그래서 다차원 배열이라는 표현보다는 근본 있게 '다중 배열'로 표현

// 실제 아래 코드는 player[2][32] 형태로 구성된다
// 대괄호에서 앞에 있는 것이 공간의 개수, 각 공간의 크기
// 그러므로 32개 짜리가 2개 있다는 뜻
// 고로 실제 메모리를 살펴볼 때, 아래와 같은 형태의 결과가 나옴 

/*
0x00007FF62B37 / D720 / 66 69 72 73 74 5f 70 6c  first_pl
0x00007FF62B37D728  61 79 65 72 00 00 00 00  ayer....
0x00007FF62B37D730  00 00 00 00 00 00 00 00  ........
0x00007FF62B37D738  00 00 00 00 00 00 00 00  ........ <-- 4줄이니까 32byte인 것을 확인할 수 있다
0x00007FF62B37 / D740 / 73 65 63 6f 6e 64 5f 70  second_p <-- first player의 주소와 32만큼 차이남을 확인
0x00007FF62B37D748  6c 61 79 65 72 00 00 00  layer...
*/

// c에서 전역 변수는 0으로 초기화 

char player[MAX_PLAYER_NUMBER][MAX_PLAYER_NAME_LENGTH];
int current_player_set_index;

// ex) test[3][2][10]
// 이 형태라면 10칸 공간이 2개 있음 
// 즉 20개 공간이 있고 이런 공간이 3개 있음을 의미
// 결론적으로 총 60개의 공간을 가짐
// 알게 된 문법을 이용해서 사이드 프로젝트를 해보는 것을 추천

void set_player_info(char name[])
{
	int input_player_name_length = strlen(name);
	// player[2][32]에서 current_player_set_index를 통해
	// 0번, 1번을 제어하고자 하는 목적
	// 이 코드의 한계는 가변성이 떨어진다는 것

	// ***배열의 인덱스 시작은 0부터 시작합니다 ***
	// 혼동이 발생하는 대표적인 원인은 
	// 배열을 만들 때는 사용할 개수를 직접 적고
	// 사용할 때는 0번부터 시작해서 발생하는 것 때문임

	// 배열의 이름은 배열의 시작 주소
	strncpy(player[current_player_set_index++], name, input_player_name_length + 1);
}

void print_player_info(int index)
{
	printf("사용자 %d 의 이름은 = %s\n", index, player[index]);
}