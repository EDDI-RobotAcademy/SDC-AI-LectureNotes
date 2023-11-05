#include <stdio.h>

/* 사용자 2명을 만들어서 각 사용자들의 이름을 지정하도록 구성합니다.
*  각각의 사용자 2명의 주사위를 굴립니다.
*  주사위를 굴려서 숫자가 큰 사람이 이겼다고 출력하도록 만들어봅시다!
* 첫 번째 주사위가 짝수라면 두 번째 주사위를 굴립니다.

두 번째 주사위는 점수에 합산되며 스킬을 사용할 수 있습니다.

(즉 첫 번째 주사위가 홀수면 두 번째 주사위를 굴릴 수 없습니다)

?

(두 번째 주사위 - 스킬용 설정)

숫자 2가 나오면 자신의 주사위에 + 3을 적용합니다.

숫자 4가 나오면 그냥 죽습니다 (자살)

숫자 3이 나오면 상대편 점수에 -4를 공격합니다.
*/

// Domain (주제) 분리하기
// 일단 현재 상황에서 필요하다 생각되는 것들을 나열함
// 진행하면서 이런 것들이 더 필요한 것 같은데? 하면 추가함
// 즉 폭포수 설계(Waterfall)로 가면 미리 와꾸 다 만들어놔야 하는데 비해
// 에자일(Agile 방식을 사용하면 저딴 것은 전혀 필요 없게됨
// [ 단 XP => eXtreme Programming 기법이 필요함 => 함수 포인터임 ]
// 
// 사용자
// 주사위

#include "dice_game.h"
#include "second_dice.h"
#include "random_generator.h"
#include "win.h"
#include "player.h"
#include "malloc_test.h"


#define FOR_TEST_DYNAMIC_ARRAY_COUNT		5


int main(void) {
	
	int loop_count = 0;
	
		// 1. 플레이어 이름을 설정합니다.
	int i;

	int player1_score = 0;
	int player2_score = 0;

	//복습 할 떄 test_array가 결국
	//malloc()을 통해 할당 받은 메모리 공간이라는 것을 상기하세요.
	
	int test_array[3] = { 1, 2, 3 };
	int* test_pointer = test_array;

	char person_name[32] = "안녕하세요";
	/*
	for (i = 0; i < 3; i++)
	{
		printf("포인터를 배열처럼 사용 할 수 있음: %d\n", test_pointer[i]);
	}
	*/

	set_player_info("first_player");
	set_player_info("second_player");

	print_player_info(0);
	print_player_info(1);

	//2. 각 플레이어들이 주사위를 굴립니다
	// random_config()을 하지 않으면 랜덤성이 되지 않고 둘 다 같은 값만 나오게된다.
	
	random_config();
	roll_dice(0);

	roll_dice2(0);



	// 3. 굴린 주사위의 눈금을 보고 승자를 판정합니다.
	check_winner(0, 1);

	// malloc test
	// =>실제로 숫자 값(상수)를 직접 때려 넣는 것은
	//		별로 좋지 않습니다.(예제라 그냥 사용)

	
	/*
	create_int_dynamic_array(FOR_TEST_DYNAMIC_ARRAY_COUNT);

	while (loop_count++ < FOR_TEST_DYNAMIC_ARRAY_COUNT)
	{
		put_one_integer_data(loop_count * 2);
	}

	print_integer_dynamic_array();


	create_char_dynamic_array(person_name);
	set_name_to_char_dynamic_array(person_name);
	print_char_dynamic_array();
	*/


	return 0;
}