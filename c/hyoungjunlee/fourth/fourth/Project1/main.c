#include <stdio.h>
#include "player.h"
#include "dice_game.h"
#include "random_generator.h"
#include "win.h"

//Domain(주제) 분리하기
//일단 현재 상황에서 필요하다 생각되는 것들을 나열함
//진행하면서 이런 것들이 더 필요한 것같은데? 하면 추가함
// 즉 폭포수 설계(waterfall)로 가면 미리 와꾸다 만들어놔야 하는데 비해
// agile(애자일)방식을 사용하면 저딴 것은 전혀 필요 없게됨
// [단 (XP =>eXtreme Programming 기법이 필요함 => 함수 포인터임 ]
//
//사용자
//주사위

int main(void)
{
	//Agile 방식을 따를 때 가장 중요한 것
	//세부 사항을 먼저 만들려고 하면 망합니다
	//최상위 아젠다를 먼저 만들어야 합니다
	//결론적으로 소설을 쓰면 됩니다
	//주의할 사항 => 이과인 경우 답이 정해지길 원하는 경향이 있음( 나 포함)
	//               그러다 보니 x^2를 적분 했을 때 1/3 x^3이 나와야 한다라는 명확한 답을 원함
	//               그러나 프로그래밍에는 정답이 없음( 소설 쓰라는 이유)
	// 
	// 
	//현재 관점에서 최상위 아젠다는
	// 1. 플레이어의 이름을 설정합니다
	set_player_info("first_player");
	set_player_info("second_player");

	print_player_info(0);
	print_player_info(1);
	//2.각 플레이어들이 주사위를 굴립니다
	random_config();
	roll_dice(0);
	roll_dice(1);

	print_dice_number(0);
	print_dice_number(1);

	//3. 굴린 주사위의 눈금을 보고 승자를 판정합니다.
	check_winner(0,1);

	return 0;
}