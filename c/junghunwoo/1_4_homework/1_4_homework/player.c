#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "player.h"

//배열의 시작은 index 0번부터 시작합니다.
//주의사항 => 어셈블리어 코드에섣 봤듯이 메모리에 차원(Dimension) 개념은 없습니다.
//그래서 다차원 배열이라는 표현 보다는 근본 있게 '다중 배열' 이라고 합시다.

// 실제 아래 코드는 player[2][32] 형태로 구성됩니다.
// 그러므로 32개 짜리가 2개 있다는 뜻이 됩니다.
// 고로 실제 메모리를 살펴 볼 때 아래와 같은 형태의 결과가 나옵니다.
/*
0x00007FF7C4A0D720  66 69 72 73 74 5f 70 6c  first_pl
0x00007FF7C4A0D728  61 79 65 72 00 00 00 00  ayer....
0x00007FF7C4A0D730  00 00 00 00 00 00 00 00  ........
0x00007FF7C4A0D738  00 00 00 00 00 00 00 00  ........   <<<- 4이니까 32(8*4)

0x00007FF7C4A0D740  73 65 63 6f 6e 64 5f 70  second_p
0x00007FF7C4A0D748  6c 61 79 65 72 00 00 00  layer...
0x00007FF7C4A0D750  00 00 00 00 00 00 00 00  ........
0x00007FF7C4A0D758  00 00 00 00 00 00 00 00  ........   <<<- 4이니까 32
*/
char player[MAX_PLAYER_NUMBER][MAX_PLAYER_NAME_LENGTH];
int current_player_set_index;

// ex) test [3][2][10]
//	이 형태라면 10개의 공간이 2개 있음
// 즉 20개짜리 공간이 되
// 이 20개짜리 공간이 3개 있다는 뜻이 됨
// 결록적으로 총 60개으 공간을 가짐

void set_player_info(char name[])
{
	int input_player_name_length = strlen(name);
	// player[2][32]에서 current_player_set_index를 통해
	// 0번, 1번을 제어하고자 하는 목적(가변이 안된다)

	// ***** 배열의 인덱스 시작은 0부터 시작합니다 *****
	// ***** 혼동이 발생하는 대표적인 원인은
	//		 배열을 만들 떄는 사용할 개수를 직접 적고
	//		 사용 할 때는 0번 부터 시작해서 발생하는 혼동입니다. *****

	// * 배열의 이름은 배열의 시작 주소
	strncpy(player[current_player_set_index++], name, input_player_name_length + 1);
}

void print_player_info(int index)
{
	printf("사용자 %d의 이름은 -%s\n", index, player[index]);
}