#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "player.h"


// 배열의 시작은 index 0부터 시작됨
// 주의 사항 => 어셈블리어 코드에서도 봤 듯 메머리에 차원 개념은 없다
// 그래서 다차원 배열이라는 표현 보다는 다중 배열
// 실제 아래 코드는 player[2][32] 형태로 구성 < 리포지토리 형식 확인 : 더 큰 개념(?) 을 앞에 배치
// 그러므로 32개 짜리가 2개 있다는 뜻
// 고로 실제 메모리를 살표 볼 때 아래와 같은 형태의 결과가 나온다.
// 리포지토리 확인 player
// 결론적으로 배열이 되었든 다중 배열이 되었든 전부 메모리의 열거
// [][] 열거 시 앞에께 큰 공간
char player[MAX_PLAYER_NUMBER][MAX_PLAYER_NAME_LENGTH];
int current_player_set_index;

void set_player_info(char name[])
{	int input_player_name_length = strlen(name);
// player[2][32]에서 current_player_set_index를 통해 0번, 1번을 제어하고자 하는 목적
// index 시작은 0 부터 시작하는데 사용 할 개수랑 헷갈리지 않기
// ex) 사용 할 개수 2개 = index 0, 1
// 배열의 이름은 배열의 시작 주소
	strncpy(player[current_player_set_index++], name, input_player_name_length + 1); // <-- 사고 발생(열 처리)을 위해 +1 칸 추가 해줌
	}

void print_player_info(int index)
{
	printf("사용자 %d 의 이름은 = %s\n", index, player[index]);
}