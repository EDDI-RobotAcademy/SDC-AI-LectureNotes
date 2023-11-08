#pragma once
#define MAX_PLYAER_NAME_LENGTH	32
#define MAX_PLAYER_NUMBER 2

extern char player[MAX_PLAYER_NUMBER][MAX_PLYAER_NAME_LENGTH];

// 최상위 아젠다를 결정하고 만들다보니
// 실제로 초기 계획과는 다른 형태로 코드가 구현됨
// 그래서 세부 사항을 먼저 구현하면 안됨
void set_player_info(char name[]);
void print_player_info(int index);