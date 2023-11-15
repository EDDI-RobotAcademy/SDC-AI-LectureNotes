#include <stdio.h>
#include <time.h> // time(NULL) 사용 lib

#include "2/random_generate.h"
#include "2/random_number_play.h"
#include "3/common.h"
#include "8/random_size_dynamic_array.h"
#include "11/player.h"

int main (void)
{
//1. 아무 변수나 만들고 변수 값을 출력하세요.

int test_var = 10;
printf("test_var %d\n", test_var);

//2. 랜덤 숫자를 출력하세요.

config_random_seed();

int test_var_random = get_random_number();

printf("test_var_random: %d\n", test_var_random);

// 3. 2번에서 만든 랜덤 숫자가 2로 나눠서 나머지가 1인 경우만 출력

if (check_even(test_var_random) == false)
{
    printf("test_var_random: %d\n", test_var_random);
}

// 4. 숫자 3 ~ 20 사이의 정수를 모두 출력하시오
for (int i = 3; i <= 20; i++){
    printf("int %2d\n", i);
}

// 5. 정수형 인자 1개를 파라미터로 받아 출력하시오
int int_print = 3;

printf("int_print: %d\n", int_print);

// 6. 정수형 인자 2개를 파라미트로 받아 더한 결과를 return 하시오
int int_add_1 = 2;
int int_add_2 = 3;

int result = int_add_1 + int_add_2;

printf("int_add: %d\n", result);

// 7. 정수형 배열에 랜덤 숫자 3개를 입력한 이후 배열에 들어 있는 숫자를 출력하세요.

config_random_seed();

int x = get_random_number();
int y = get_random_number();
int z = get_random_number();

int int_random[3] = {x, y, z};
printf("int_random: %3d, %3d, %3d\n", int_random[0], int_random[1], int_random[2]);

// 8. 랜덤을 돌려서 임의 개수의 정수형 동적 배열을 만들고 동적 배열에 숫자를 넣은 이후 출력하세요.
int random_size = get_random_number();
random_size_dynamic_array(random_size);

// 9. 정수형 배열에 아무 숫자나 넣고 이 배열을 파라미터로 받아 출력하는 함수를 작성하시오.
config_random_seed();

int int_array[3] = {get_random_number(),get_random_number(),get_random_number()};
for (int j = 0; j < 3; j++){
    printf("int_array %d\n", int_array[j]);
}

// 10. 정수형 배열에 아무 숫자나 넣고 이 배열의 모든 값을 더해서 return 하는 함수를 작성하시오.
config_random_seed();

int add_int_array[3] = {get_random_number(),get_random_number(),get_random_number()};
{
    printf("1:%d\n2:%d\n3:%d\nadd_int_array %d\n", add_int_array[0], add_int_array[1], add_int_array[2],
    add_int_array[0]+add_int_array[1]+add_int_array[2]);
}

// 11. 아무런 구조체 대충 하나 만들고 내부에 값을 할당하여 출력해보자
    player_object_array[i];
    
    set_player_name(player *object, char *name);

    char *name = {
        "test_name"
    };

    print_player_object();

    return 0;
}

