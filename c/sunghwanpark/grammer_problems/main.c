#include <stdio.h>
#include <stdlib.h>

#include "1/grammar_prob_first.h"
#include "2/grammar_prob_second.h"
#include "3/grammar_prob_third.h"
#include "4/grammar_prob_fourth.h"
#include "5/grammar_prob_fifth.h"
#include "6/grammar_prob_sixth.h"
#include "7/grammar_prob_seventh.h"
#include "8/grammar_prob_eighth.h"
#include "9/grammar_prob_ninth.h"
#include "10/grammar_prob_tenth.h"
#include "11/grammar_prob_eleventh.h"

int main (void)
{
    int i;
    int random_array_alloc_count;
    int *random_array;
    int *array_pointer;
    int * nine_prob_array;

    test_struct *eleven_prob_struct;

    // 1번 문제 
    return_variable();

    // 2번 문제 
    printf("랜덤 번호 출력: %d\n", generate_random(1,10));
    
    // 3번 문제 
    printf("2의 배수만 출력, 아닐시 -1 출력: %d\n", return_if_remain_is_one(1,10));
    
    // 4번 문제 
    return_integers(3,20);
    
    // 5번 문제 
    printf("정수형 인자 출력: %d\n", return_integer_one_parameter(20));

    // 6번 문제 
    printf("정수형 인자 합계 출력: %d\n", return_integer_two_parameter(10,20));

    // 7번 문제 
    array_pointer = return_random_array_data();
    printf("배열 받아 출력하기: ");
    for (i=0 ; i < 3 ; i++)
    {
        printf("%3d", array_pointer[i]);
    }
    printf("\n");
    
    // 8번 문제 
    random_array_alloc_count = random_alloc_integer_array(&random_array);
    printf("동적 할당된 배열 출력하기: \n");
    for (i=0 ; i < random_array_alloc_count ; i++)
    {
        
        printf("random aray [%d] = %d\n", i, random_array[i]);
    }
    printf("\n");

    free(random_array);

    // 9번 문제 
    nine_prob_array = alloc_array (&random_array_alloc_count);

    for(i=0 ; i<random_array_alloc_count; i++)
    {
        printf("이렇게도 출력 가능: %d\n", nine_prob_array[i]);
    }

    free(nine_prob_array);

    //10번 문제
    printf("모든 배열의 요소 합: %d\n", add_every_array_element());

    // 11번, 12번 문제 
    eleven_prob_struct = alloc_test_struct();
    printf("num1 = %d\n", eleven_prob_struct->num1);
    printf("num2 = %f\n", eleven_prob_struct->num2);
    printf("num3 = %lf\n", eleven_prob_struct->num3);
    printf("text = %s\n", eleven_prob_struct->text);
    return 0;
}
