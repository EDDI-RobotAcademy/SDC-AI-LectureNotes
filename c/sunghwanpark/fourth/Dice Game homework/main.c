
/*
사용자 2명을 만들어서 각 사용자들의 이름을 지정하도록 구성하시오. 
각각의 사용자 2명의 주사위를 굴리고 주사위를 굴려서 숫자가 큰 사람이 이기도록 출력하시오. 
*/

// Domain (주제) 분리하기 - 현재 상황에서 필요하다고 생각되는 것들을 나열함 
// 진행하면서 필요한 것들이 생각나면 추가하면 된다.  
// 폭포수 설계 (Waterfall)로 가면 미리 다 만들어놔야 하는데 비해 Agile 방식을 사용하면 필요없음
// [ 단 XP => eXtreme Programming 기법이 필요함 => 함수 포인터임 ] 
// 
// 사용자, 주사위 
//  

#include <stdio.h>
#include "player.h"
#include "dice_game.h"
#include "random_generator.h"
#include "win.h"
#include "malloc_test.h"

#define FOR_TEST_DYNAMIC_ARRAY_COUNT 5


int main(void)
{
// Agile 방식을 따를 때 가장 중요한 것 
// - 세부 사항을 먼저 만들려고 하면 망한다. 최상위 아젠다를 먼저 만들어야 한다. 

	// 현재 관점에서 최상위 아젠다는 아래와 같다. (소설을 쓴다고 생각하면 됨.) 
	
	int loop_count=0;

	/*
	int i; 

	// test_array가 결국 malloc()을 통해 할당 받은 메모리 공간이라는 것은 상기하시오. 
	int test_array[100] = {1,2,3};
	int* test_pointer = test_array;
	for (i = 0; i < 100; i++) {
		printf("포인터를 배열처럼 사용 할 수 있음: %d\n",test_pointer[i]);
	}
	
	*/

	char person_name[32] = "안녕하세요";

	// 1. 플레이어 이름을 설정한다. 
	set_player_info("first_player");
	set_player_info("second_player");

	print_player_info(0);
	print_player_info(1);

	// 2. 각 플레이어들이 주사위를 굴린다.  
	random_config();
	roll_dice(0);
	roll_dice(1);

	print_dice_number(0);
	print_dice_number(1);

	// 3. 굴린 주사위의 눈금을 보고 승자를 판정한다. 
	check_winner(0,1);

	//malloc test 
	// 실제로 숫자 값(상수)를 직접 넣는 것은 별로 좋지 않다. 
	create_int_dynamic_array(5);
	while (loop_count++<FOR_TEST_DYNAMIC_ARRAY_COUNT) {
		put_one_integer_data(loop_count * 2);
	}
	print_integer_dynamic_array();;
	
	create_char_dynamic_array(person_name);
	set_name_to_char_dynamic_array(person_name);
	print_char_dynamic_array();


	return 0;
}