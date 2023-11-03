#include <stdio.h>

/* 사용자 2명을 만들어서 각 사용자들의 이름을 지정하도록 구성합니다.
   각각의 사용자 2명의 주사위를 굴립니다.
   주사위를 굴려서 숫자가 큰 사람이 이겼다고 출력하도록 만들어봅시다! */

// Domain (주제) 분리하기
// 일단 현재 상황에서 필요하다 생각되는 것들을 나열함
// 진행하면서 이런 것들이 더 필요한 것 같은데 ? 하면 추가함
// 즉 폭포수 설계(Waterfall)로 가면 미리 와꾸 다 만들어놔야 하는데 비해
// 애자일(Agile) 방식을 사용하면 저딴 것은 전혀 필요 없게됨
// [ 단 XP => eXtreme Programming 기법이 필요함 => 함수 포인터임 ]
// 
// 사용자
// 주사위

#include "player.h"
//#include "dice.h"
//#include "winner.h"

int main(void)
{
	// Agile 방식을 따를 때 가장 중요한 것
	// 세부 사항을 먼저 만들려고 하면 망합니다.
	// 최상위 아젠다를 먼저 만들어야 합니다.
	
	// 현재 관점에서 최상위 아젠다는 아래와 같습니다.
	// 결론적으로 소설을 쓰면 됩니다.
	// 주의 할 사항 => 이과인 경우 답이 정해지길 원하는 경향이 있음 (나 포함)
	//                 그러다 보니 x^2을 적분 했을 때 1/3 x^3 이 나와야 한다라는 명확한 답을 원함
	//                 그러나 프로그래밍에는 정답이 없음 (소설 쓰라는 이유)
	// 
	// 1. 플레이어 이름을 설정합니다.
	set_player_info("first_player");
	set_player_info("second_player");

	print_player_info(0);
	print_player_info(1);

	// 2. 각 플레이어들이 주사위를 굴립니다.
	//roll_dice(first_player);
	//roll_dice(second_player);

	// 3. 굴린 주사위의 눈금을 보고 승자를 판정합니다.
	//check_winner();

	return 0;
}