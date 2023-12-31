#include <stdio.h>

/* 사용자 2명을 만들어 각 사용자 이름 지정
   각각의 사용자 2명의 주사위를 굴림
   주사위를 굴려서 숫자가 큰 사람이 이겼다고 출력하도록 만들기
*/

// Domain (주제) 분리하기
// 일단 현재 상황에서 필요하다 생각되는 것들을 나열함
// 진행하면서 이런 것들이 더 필요할 것 같은데? 하면 추가
// 즉 폭포수 설계(Waterfall)로 가면 미리 와꾸 다 만들어놔야 하는데 비해
// 애자일(Agile) 방식을 사용하면 저런 것은 필요X
// 단 XP=> eXtreme Programming 기법이 필요함-> 함수 포인터임

// 사용자
// 주사위

#include "player.h"
#include "dice_game.h"
#include "random_generator.h"
#include "win.h"
#include "malloc_test.h"

#define FOR_TEST_DYNAMIC_ARRAY_COUNT		8

int main(void)
{
	// * Agile 방식을 따를 때 가장 중요한 것
	//   세부 사항을 먼저 만들려고 하면 망함
	//   최상위 아젠다를 먼저 만들어야 함

	// 현재 관점에서 최상위 아젠다는 아래와 같음
	// 결론적으로 소설을 쓰면 됨
	// 주의 사항=> 이과인 경우 답이 정해지길 원하는 경향이 있음
	//				그러다 보니 X^2을 적분했을 때 1/3 x^3이 나와야 한다라는 명확한 답을 원함
	//				그러나 프로그래밍에는 정답이 없음
	// 1. 플레이어 이름 설정
	int loop_count = 0;
	int i;

	// 복습
	// test_array가 결국 malloc()을 통해 할당 받은 메모리 공간임을 상기할 것.
	int test_array[3] = { 1,2,3 };
	int* test_pointer = test_array;

	char person_name[32] = "안녕하세요";

	for (i = 0; i < 3; i++)
	{
		printf("포인터를 배열처럼 사용할 수 있음: %d\n", test_pointer[i]);
	}

	set_player_info("first_player");
	set_player_info("second_player");

	print_player_info(0);
	print_player_info(1);

	// 2. 각 플레이어들이 주사위를 굴림
	//roll_dice(first_player)
	//roll_dice(second_player);
	random_config();
	roll_dice(0);
	roll_dice(1);

	print_dice_number(0);
	print_dice_number(1);

	// 3. 굴린 주사위의 눈금을 보고 승자를 판정
	check_winner(0, 1);

	// malloc test
	// -> 실제로 숫자 값(상수)을 직접 넣는 것은 별로 좋지 X
	create_int_dynamic_array(FOR_TEST_DYNAMIC_ARRAY_COUNT);

	while (loop_count++ < FOR_TEST_DYNAMIC_ARRAY_COUNT)
	{
		put_one_integer_data(loop_count * 2);
	}

	print_integer_dynamic_array();
	/* 지역 변수는 특정 영역 '{'으로 시작해서 '}'으로 끝나는 공간 내부에서만 사용할 수 있기 때문
	   다르게 표현하지면 Stack 에서만 사용 가능
	test_local_variable();
	printf("test_variable=%d\n", test_variable;
	*/
	
	create_char_dynamic_array(person_name);
	set_name_to_char_dynamic_array(person_name);
	print_char_dynamic_array();

	return 0;
}