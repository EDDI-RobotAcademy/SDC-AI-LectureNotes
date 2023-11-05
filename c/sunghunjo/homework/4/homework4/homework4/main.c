#include <stdio.h>

#include "player.h"
#include "dice.h"
#include "skill.h"
#include "random_generator.h"
#include "win.h"

// player정하기(? 명)2명
// player 이름을 만듬 malloc으로 player[]에 공간을 만들어서 이름을 저장함
// 필터 : player, malloc
// 
// 동적할당으로 하기(malloc)
//
//
// 주사위를 굴린다.만약 짝수라면 한번더 굴린다.플레이어의 숫자를 기록
// 만약 숫자가 2, 3, 4가 나오면 스킬 발현 하고 숫자를 합친다.아니라면 숫자를 그냥 합친다.
// 필터 : game - dice(굴리는거, 스킬발현조건, 숫자 합치기), game - skill
//
//
// 후에 플레이어들의 숫자를 비교하여 큰쪽이 이긴다.
// 필터 : win
//
// 진행방향
// main(시작)->player이름 받고 동적할당(malloc으로 공간만들고 이름 넣기)->player한명씩 주사위를 돌린다->dice_roll
// ->player[이름]에 숫자를 저장을 시킴->짝수확인 하고 짝수면 다시돌리기->숫자가 2, 3, 4가 맞는지 확인
// -> 2, 3, 4면 스킬을사용(->아니라면 기존 숫자에 더해주기)->스킬을 상대방()에게 사용->후에 누가 숫자가 더큰가 판별
// ->print하면 끝

int main(void)
{
	set_player_info("철수");
	set_player_info("영희");

	print_player_info(0);
	print_player_info(1);

	random_config();
	roll_dice(0);
	roll_dice(1);

	printf("\n");

	print_dice_number(0);
	print_dice_number(1);

	printf("\n");

	check_winner(0, 1);

	return 0;
}