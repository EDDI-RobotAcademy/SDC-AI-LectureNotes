#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include "player.h"

/*	배열의 시작은 index 0번부터 시작합니다.
*	주의 사항 => 어셈블리어 코드에서 봈드이 메모리에 차원 개념은 없습니다
*	그래서 다차원 배열이라는 표현
	*/

// 실제 아래 코드는 player[2][32] 형태로 구성됩니다.
//	그러므로 32개 짜리가 2개 있다는 뜻이 됩니다.
//  고로 실제 메모리를 살펴 볼때 아래와 같은 형태의 결과가 나옵니다.
// 0x00007FF7540DD9C0  66 72 69 73 74 5f 70 6c  frist_pl
// 0x00007FF7540DD9C8  61 79 65 72 00 00 00 00  ayer....
// 0x00007FF7540DD9D0  00 00 00 00 00 00 00 00  ........
// 0x00007FF7540DD9D8  00 00 00 00 00 00 00 00  ........ <- 4줄 32
// 
// 0x00007FF7540DD9E0  73 65 63 6f 6e 64 5f 70  second_p
// 0x00007FF7540DD9E8  6c 61 79 65 72 00 00 00  layer...
// 0x00007FF7540DD9F0  00 00 00 00 00 00 00 00  ........
// 0x00007FF7540DD9F8  00 00 00 00 00 00 00 00  ........<- 4줄 32
// 
// 결론적으로 배열이 되있는 다중 배열이 되있든 전부 메모리의 열거일 뿐
char player[MAX_PLAYER_NAME_LENGTH][MAX_PLAYER_NAME_LENGTH];
int current_player_set_index;

// ex) test[3][2][10]
// 이 형태라면 10개의 공간이 2개 있음
// 즉 20개 짜리의 공간이 됨
// 이 20개짜리의 공간이 3개 있다는 뜻이 됨
// 결론적으로 총 60개의 공간을 가짐
//

void set_player_info(char name[])
{
	int input_player_name_length = strlen(name);
	// player [2][32]에서 current_player_set_index를 통해
	// 0번 , 1번을 제어하고자 하는 목적
	// *********** 배열의 인덱스 시작은 0부터 시작합니다 ************
	// *********** 혼동이 발생하는 대표적인 원인은
	//			   배열을 만들 때는 사용할 개수를 직접 적고
	//			   사용 할 때는 0번 부터 시작해서 발생하는 혼동입니다. ************
	// 
	//  *. 배열의 이름은 배열의 시작 주소
	//   

	strncpy(player[current_player_set_index++], name, input_player_name_length + 1);
}	

void print_player_info(int index)
{
	printf("사용자 %d 의 이름은 =%s\n", index, player[index]);
}

