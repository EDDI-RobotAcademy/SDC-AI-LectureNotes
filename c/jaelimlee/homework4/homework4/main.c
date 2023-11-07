/*
사용자 2명을 만들어서 각 사용자들의 이름을 지정하도록 구성합니다.
각각의 사용자 2명은 각각 주사위를 2개씩 굴립니다.

주의: 아래 조건이 반드시 지켜져야 합니다.
첫 번째 주사위가 짝수라면 두 번째 주사위를 굴립니다.
두 번째 주사위는 점수에 합산되며 스킬을 사용할 수 있습니다.
(즉 첫 번째 주사위가 홀수면 두 번째 주사위를 굴릴 수 없습니다)

(두 번째 주사위 - 스킬용 설정)
숫자 2가 나오면 자신의 주사위에 + 3을 적용합니다.
숫자 4가 나오면 그냥 죽습니다 (자살)
숫자 3이 나오면 상대편 점수에 -4를 공격합니다.

이 방식을 적용하여 승자를 판정해봅시다!
*/

#include <stdio.h>
#include "player.h"
#include "dice.h"
#include "random_generator.h"



int main(void)
{
	// 1. 플레이어 이름 설정 
	char person_name1[32] = "유저0";
	char person_name2[32] = "유저1";

	create_char_dynamic_array(person_name1);
	set_name_to_char_dynamic_array(person_name1);
	print_char_dynamic_array();

	create_char_dynamic_array(person_name2);
	set_name_to_char_dynamic_array(person_name2);
	print_char_dynamic_array();

	
	// 2. 주사위 2개 굴림
	random_config();

	roll_dice(0);
	roll_dice(1);

	print_dice_number(0);
	print_dice_number(1);


	// 3. 
}