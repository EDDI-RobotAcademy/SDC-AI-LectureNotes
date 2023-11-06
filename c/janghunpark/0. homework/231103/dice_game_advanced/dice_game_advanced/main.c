/*
2인 주사위 게임 심화 1단계

Game Logic
1. 사용자 2명을 만들어서 각 사용자들의 이름을 지정한다.
2. 각 사용자 2명은 주사위를 동시에 주사위를 굴린다.
3. 만약 처음에 굴린 주사위가 짝수라면 한 번 더 굴릴 수 있다.
3 - 1) 나온 숫자가 1, 5, 6이라면 첫 번째 주사위 수에 합산된다.
3 - 2) 숫자 2가 나오면 첫 번째 주사위에 5를 합산한다.
3 - 3) 숫자 4가 나오면 즉시 패배한다.
3 - 4) 숫자 3이 나오면 상대편 주사위 숫자(합)에 - 4를 한다.
4. 최종 주사위 숫자(합)이 큰 사람이 승리한다.

Key Point
* malloc과 함수 포인터의 목적 및 활용
* 포인터로 배열의 주소를 받아와 쓰는 방식의 적용

Main Algorithm
< main>
1. 플레이어들 이름 정보 지정 및 출력
2. 플레이어들의 첫 번째 주사위 난수 발생 및 출력
3. 플레이어의 첫 번째 주사위 숫자가 짝수인지 확인
4. 짝수인 플레이어(들)의 두 번째 주사위 난수 발생 및 출력
5. 숫자별 스킬의 적용 및 출력
6. 최종 승자 확인
*/

#include <stdio.h>
#include "dice.h"
#include "player.h"
#include "random_generator.h"

int main(void)
{
	create_player_name_array("철수");
	create_player_name_array("영희");
	print_player_name_to_array();
	
	random_config();
	roll_dice();
	check_winner();

	return 0;
}