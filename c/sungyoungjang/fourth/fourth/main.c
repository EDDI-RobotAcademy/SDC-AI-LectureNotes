#include <stdio.h>

#include "dice_game.h"
#include "player.h"
#include "malloc_test.h"

//주사위

#define FOR_TEST_DYNAMIC_ARRAY_COUNT	8
/* 사용자 2명을 만들어서 각 사용자들의 이름을 지정하도록 구성합니다.
	각각의 사용자 2명의 주사위를 굴립니다.
	주사위를 굴려서 숫자가 큰 사람이 이겼다고 출력하도록 만들어봅시다.*/

/* Domain(주제)분리하기
   일단 현재 상황에서 필요하다 생각되는 것을 나열함
   진행하면서 이런것들이 필요하다 싶으면 추가함
   즉 폭포수 설계(Water Fall)로 가면 미리 다 만들어놔야 하는데 비해
   애자일(Agile) 방식을 사용하면 위에 설계 방식은 필요없게됨
   [단 XP => eXtreme Programing 기법이 필요함 => 함수 포인터임]*/

// 사용자
// 주사위
int main(void) 
{	
	/*Agile 방식을 따를 때 가장 중요한것
	  세부 사항을 먼저 만들려고 하면 망함.
	  최상위 아젠다를 먼저 만들어야함.*/
	
	// 현재 관점에서 최상위 아젠다는 아래와 같습니다.
	// 주의 할 사항 => 이과의 경우 답이 정해지길 원하는 경향이 있음(나 포함)
	//				   그러다 보니 x^2를 적분했을 때 1/3 x^3이 나와야 한다라는 명확한 답을 원함
	//					그러나 프로그래밍에는 정답이 없음.
	// 1. 플레이어 이름을 설정합니다.
	int loop_count = 0;
	int i;

	// 복습 할 때 test_array가 결국 malloc()을 통해 할당 받은 메모리 공간이라는 것을 상기하시오.
	int test_array[100] = {1,2,3};
	int* test_pointer = test_array;

	char person_name[32] = "안녕하세요";

	for (i = 0; i < 100; i++)
	{
		test_pointer[i] = (i+3) *2;
		printf("포인터를 배열처럼 사용할 수 있음 : %d\n", test_pointer[i]);
	}

	set_player_info("frist_player");
	set_player_info("second_player");

	print_player_info(0);
	print_player_info(1);
	
	//2. 각 플레이어들이 주사위를 굴립니다.
	//roll_dice("first_player");
	//roll_dice("second_player");
	random_config();
	roll_dice(0);
	roll_dice(1);

	print_dice_number(0);
	print_dice_number(1);

	//3. 굴린 주사위의 눈금을 보고 승자를 판정합니다.
	check_winner(0,1);

	//malloc test
	// => 실제로 숫자 값(상수)를 직접 때려 넣는 것은
	//	  별로 좋지가 않다,
	create_int_dynamic_array(FOR_TEST_DYNAMIC_ARRAY_COUNT);

	while (loop_count++ < FOR_TEST_DYNAMIC_ARRAY_COUNT)
	{
		put_one_integer_data(loop_count * 2);
	};
	print_integer_dynamic_array();

	/* 지역 변수는 특정영역 '{'으로 시작해서 '}'으로
	   끝나는 공간 내부에서만 사용할 수 있기 때문
	   다르게 표현하자면 Stack에서만 사용 할 수 있기 때문이다.*/

	create_char_dynamic_array(person_name);
	set_name_to_char_dynamic_array(person_name);
	print_char_dynamic_array();


	return 0;
}