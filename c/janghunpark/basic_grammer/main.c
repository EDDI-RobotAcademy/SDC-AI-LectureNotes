#include <stdio.h>

#include "random/random.h"
#include "8/dynamic_array.h"
#include "9/array_pointer.h"
#include "11/kda.h"
#include "12/player.h"

#define NUMBER_OF_PLAYERS       2

void print_int_parameter(int number)
{
    printf("입력받은 정수 인자는 %d입니다!\n", number);
}

void add_int_numbers(int num1, int num2)
{
    printf("%d + %d = %d\n", num1, num2, num1+num2);
}

void print_random_int_array(void)
{
    int num1 = generate_random_number(1, 100);
    int num2 = generate_random_number(1, 100);
    int num3 = generate_random_number(1, 100);
    int integer_array[3] = { num1, num2, num3 };
    int loop;
    for (loop = 0; loop < 3; loop++)
    {
        printf("interger_array[%d] = %d\n", loop, integer_array[loop]);
    }
}

int main (void)
{
    // 1번 문제
    int a = 1;
    printf("a = %d\n", a);

    // 2번 문제
    random_config();
    int random_number = generate_random_number(1, 100);
    printf("random number btw 1 and 100 = %d\n", random_number);

    // 3번 문제
    if ((random_number % 2 == 1))
    {
        printf("%d는 2로 나눈 나머지가 1이므로 출력합니다!\n", random_number);
    }
    if ((random_number % 2 != 1))
    {
        printf("2로 나눈 나머지가 1이 아니므로 출력하지 않습니다!\n");
    }
    
    // 4번 문제
    int i;
    for (i = 3; i <= 20; i++)
    {
        printf("%3d", i);
    }
    printf("\n");

    // 5번 문제
    print_int_parameter(5);

    // 6번 문제
    add_int_numbers(3, 7);

    // 7번 문제
    print_random_int_array();

    // 8번 문제
    generate_and_print_random_int_dynamic_array();

    // 9번 문제
    int random_int_array[3] = { 1, 3, 5 };
    int *array_pointer = random_int_array;
    print_array_by_pointer(array_pointer);

    // 10번 문제
    print_sum_in_array_by_pointer(array_pointer);

    // 11번 문제
    

    // 12번 문제
    player *player_object[NUMBER_OF_PLAYERS];
    char *name_array[NUMBER_OF_PLAYERS] = { "hello", "hi" };
    player_info_allocation(player_object, name_array);

    return 0;
}