#define _CRT_SECURE_NO_WARNINGS // Windows 보안 이슈 때문에 붙임. 
#include "player.h"
#include <string.h>
#include <stdio.h>

// 배열의 시작은 index 0번부터 시작된다. 
//주의 사랑 -> 어셈블리어 코드에서도 봤듯이 메모리에 차원(Dimension) 개념은 없다. 
// 그래서 다차원 배열이라는 표현보다는 근본 있게 '다중 배열'이라는 표현이 맞다. 

//아래 코드는 player[2][32] 형태로 구성된다. 
// 그러므로 32개 짜리가 2개 있다는 뜻이 된다. 
char player[MAX_PLAYER_NUMBER][MAX_PLAYER_NAME_LENGTH];
int current_player_set_index;

// ex) test[3][2][10]
//		위의 형태는 10개의 공간이 2개 있다. 
//		즉, 20개짜리 공간이 된다.
//		이 20개짜리 공간이 3개 있다는 뜻이 된다. 
//		결론적으로 총 60개의 공간을 가지게 됨. 

void set_player_info(char name[])
{
	int input_player_name_length = strlen(name);
	// player[2][32]에서 current_player_set_index를 통해서 0번, 1번을 제어하고자 하는 목적 
	strncpy(player[current_player_set_index++], name, input_player_name_length + 1);
	
}

void print_player_info(int index)
{
	printf("사용자 %d 의 이름은: %s\n", index+1, player[index]);
}


