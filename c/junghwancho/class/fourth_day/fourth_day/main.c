#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "dice_game.h"
#include "win.h"
#include "malloc_test.h"

#define FOR_TEST_DYNAMIC_ARRAY_COUNT			5

// 사용자 2명을 만들어 각 사용자들의 이름을 지정
// 각각 사용자 2명이 주사위를 굴림
// 주사위를 굴려 숫자가 큰 사람이 이겼다고 출력

// domain (주제) 분리하기
// 일단 현재 상황에서 필요하다 생각되는 것들 나열
// 진행하면서 이런 것들이 더 필요한 거 같은데 = 추가
// 즉 폭포수 설계(water fall)로 가면 미리 와꾸 다 만들어놔야 하는데
// 애자일 방식으로 그런 과정 생략
// 단 XP 기법이 필요

// 사용자
// 주사위

int main(void)
{

	// 애자일 방식의 중요한 점
	// 세부 사항을 먼저 x
	// 최상위 아젠다 먼저 생성
	// 현재 관점에서 최상의 아젠다는 아래와 같다
	// 주의 할 사항 => 프로그램에 정답은 없음 !!!!!
	// 
	// 1. 플레이어 이름
	int loop_count = 0;
	int i;

	// 복습 할 때 test_array가 결국 malloc()을 통해 할당 받은 메모리 공간이라는 것 상기
	int test_array[100] = { 1, 2, 3 };
	int* test_pointer = test_array;

	char person_name[32] = "안녕하세요";

	for (i = 0; i < 100; i++)
	{
		printf("포인터를 배열 처럼 사용 할 수 있음 : % d\n", test_pointer[i]);
	}

	set_player_info("first_player");
	set_player_info("second_player");

	print_player_info(0);
	print_player_info(1);

	// 2. 주사위 굴림

	random_config();
	roll_dice(0);
	roll_dice(1);

	print_dice_number(0);
	print_dice_number(1);


	// 3. 주사위 결과를 보고 승자 판정
	check_winner(0, 1);



	//malloc test
	create_int_dynamic_array(FOR_TEST_DYNAMIC_ARRAY_COUNT);

	while (loop_count++ < FOR_TEST_DYNAMIC_ARRAY_COUNT)
	{
		put_one_integer_data(loop_count * 2);
	}

	print_integer_dynamic_array();

	// 지역 변수는 특정 영역 '{'으로 시작해 '}'으로 끝나는 공간 내부에서만 사용할 수 있다.
	// 다르게 표현하면 stack에서만 사용할 수 있다.
	//test_local_variable();
	//print("test_varioable = %d\n", test_variable);

	create_char_dynamic_array(person_name);
	set_name_to_char_dynamic_array(person_name);
	print_char_dynamic_array();

	return 0;
}



// 설계 관점의 문제점
// ex) 랭킹, 상점 같은 시스템 만들 때, 주사위 롤백, 아이템 사용 등을 만들고 싶을 때
// 작성해 둔 내용을 헤깔릴 수 있다. => 포인터 등으로 해결 ?
// 이 구조로는 확장성이 없다 ? why ? 너무 서로 기능이 곂쳐있음