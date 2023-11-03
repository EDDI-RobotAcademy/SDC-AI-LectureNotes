#include <stdio.h>
#include "player.h"
#include "dice_game.h"
#include "win.h"
#include "malloc.h"
 /*사용자 2명을 만들어서 각 사용자들의 이름을 지정하도록 구성합니다.
 각각의 사용자 2명의 주사위를 굴립니다.
 주사위를 굴려서 숫자가 큰 사람이 이겼다고 출력하도록 만들어봅시다.*/

// Domain(주제) 분리하기
// 일단 현재 상황에서 필요하다 생각되는 것들을 나열
// 진행하면서 이런 것들이 더 필요하다면 추가
// 즉, 폭포수 설계(Waterfall)로 가면 미리 다 만들어야하는데 반해
// 에자일(Agile) 방식을 사용하면 그때그때 만들 수 있음
// [ 단 XP => eXtreme Programming 기법이 필요함 => 함수 포인터임]

#define FOR_TEST_MALLOC_INTEGER 5

int main(void)
{
	// 복습 할 때 test_array가 결국 
	// malloc()을 통해 할당받은 메모리 공간임을 상기 할 것
	int test_array[3] = { 1,2,3 };
	int* test_pointer = test_array;

	char person_name[32] = "안녕하세요";

	int i;
	for (i=0;i<3;i++)
	{
		printf("포인터를 배열처럼 사용 할 수 있음 : %d\n", test_pointer[i]);
	}
	
	printf(return_string("123123123"));
	int loop_count=0;

	// Agile 방식을 따를 때 가장 중요한 것
	// 세부 사항을 먼저 만들려고 하면 X
	// 최상위 아젠다를 먼저 만들어야함

	// 현재 관점에서 최상위 아젠다는 아래와 같음
	// 결론적으로 소설을 쓰면 됨
	// 주의사항 : 이과의 경우 답이 정해지길 원하는 경향이 있음
	//			  그러다보니 x^2을 적분 했을 때 1/3 x^3이 나와야한다는 답을 원함
	//			  그러나 프로그래밍에는 정답이 없음
	// 
	// 1. 플레이어 이름을 설정합니다.
	set_player_info("first_player");
	set_player_info("second_player");

	print_player_info(0);
	print_player_info(1);

	random_config();

	// 2. 각 플레이어들이 주사위를 굴립니다.
	roll_dice(0);
	roll_dice(1);

	// 3. 승자를 체크합니다
	check_winner(0,1);

	// malloc test
	// => 실제로 숫자 값(상수)를 직접 넣는 것은 권장되지 않음
	create_int_dynamic_array(FOR_TEST_MALLOC_INTEGER);

	while (loop_count++ < FOR_TEST_MALLOC_INTEGER)
	{
		put_one_integer_data(loop_count * 2);
	}

	print_integer_dynamic_array();
	
	create_char_dynamic_array(person_name);
	set_name_to_char_dynamic_array(person_name);
	print_char_dynamic_array();
	
	return 0;
}