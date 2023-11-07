// 윈도우 보안 이슈 때문에 사용
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "player.h"

// 배열의 시작은 index 0번부터 시작
// 주의사항: 어셈블리어 코드에서도 봤듯 메모리에 차원(DImension) 개념은 X
// 다차원 배열이라는 표현보다 '다중 배열'

// 실제 아래 코드는 player[2][32] 형태로 구성됨
// 그러므로 32개 짜리가 2개 있다는 뜻임
// 고로 실제 메모리를 살펴볼 때 아래와 같은 형태의 결과가 나옴

//0x00007FF624C5D720  66 69 72 73 74 5f 70 6c  first_pl
//0x00007FF624C5D728  61 79 65 72 00 00 00 00  ayer....
//0x00007FF624C5D730  00 00 00 00 00 00 00 00  ........
//0x00007FF624C5D738  00 00 00 00 00 00 00 00  ........ <<- 4줄 이니까 32
// 
//0x00007FF624C5D740  73 65 63 6f 6e 64 5f 70  second_p
//0x00007FF624C5D748  6c 61 79 65 72 00 00 00  layer...
//0x00007FF624C5D750  00 00 00 00 00 00 00 00  ........
//0x00007FF624C5D758  00 00 00 00 00 00 00 00  ........ <<- 4줄 이니까 32

// 결론적으로 배열이 되었든 다중 배열이 되었든 전부 메모리의 열거일 뿐
// 2*32(각 공간 크기) = 64 (공간의 크기)
char player[MAX_PLAYER_NUMBER][MAX_PLAYER_NEME_LENGTH];

// current_player_set_index 생성 목적: 첫 번째 사람의 이름을 설정하고 그 다음 사람의 이름 설정을 위해
// 초기값 = 0으로 설정됨
int current_player_set_index;

// ex)  test[3][2][10]
//		이 형태라면 10개의 공간이 2개 있음
//		즉 20개짜리 공간이 됨
//		이 20개짤 공간이 3개 있다는 뜻이 됨
//		결론적으로 총 60개의 공간을 가짐

void set_player_info(char name[])
{
	int input_player_name_length = strlen(name);

	// player[2][32]에서 current_player_set_index를 통해 0번, 1번을 제어하고자 하는 목적

	//***** 배열의 인덱스 시작은 0부터 시작함 *******
	//***** 혼동이 발생하는 대표적 원인: 배열을 만들 때는 사용할 개수를 직접 적고
	//		사용 할 때는 0번부터 시작해서 발생하는 혼동 *******

	// 배열의 이름은 배열의 시작 주소
	strncpy(player[current_player_set_index++], name, input_player_name_length + 1);
}

void print_player_info(int index)
{
	printf("사용자 %d의 이름은= %s\n", index, player[index]);
}