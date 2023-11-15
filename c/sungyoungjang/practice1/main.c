#include <stdio.h>
#include <time.h>

#include "utility/random.h"
#include "1/first.h"
#include "2/second.h"
#include "3/third.h"
#include "4/fourth.h"
#include "5/fifth.h"
#include "6/sixth.h"
#include "7/seventh.h"
#include "8/eighth.h"
#include "9/nineth.h"
#include "10/tenth.h"


int main (void)
{
    
    int i;
    int random_array_alloc;
    int *random_array;
    int *array_pointer;
    

    
    random_pick();
    
    // 1번
    
    printf("1. 아무 변수나 만들고 변수 값을 출력하세요.\n");
    printf("result = %d\n",intger(9,10));

    // 2번

    printf("2. 랜덤 숫자를 출력하세요.\n");
    
    random_number();
    //가변
    print_random_number_from_main_parammeter_transfer(1,100);

    //3번
    
    printf("3. 위의 2번에서 만든 랜덤 숫자가 2로 나눠서 나머지가 1인 경우만 출력하세요.\n");
    random_num();

    //4번

    printf("4. 숫자 3 ~ 숫자 20 사이의 모든 정수를 출력하세요.\n");
    printf("%d\n",for_ex());

    //5번

    printf("5. 정수형 인자 1개를 파라미터로 받아 출력하세요.\n");
    parameter(10);

    //6번

    printf("6. 정수형 인자 2개를 파라미터로 받아 더한 결과를 return 하세요.\n");
    parameter_add(10,31);

    //7번

    printf("7. 정수형 배열에 랜덤 숫자 3개를 입력한 이후 배열에 들어 있는 숫자를 출력하세요.\n");
    print_array();
    
    // 8번

    random_array_alloc = random_alloc_array(&random_array);
    printf("8. 동적 할당된 배열 출력하기:\n");
    for (i = 0; i < random_array_alloc; i++)
    {
        printf("random_array[%d] = %d\n", i, random_array[i]);
    }
    printf("\n");

    free(random_array);

    //9번
    int *nine = malloc_array(&random_array_alloc);

    for(i = 0; i < random_array_alloc;i++)
    {
        printf("9번의 출력은 : %d\n", nine[i]);
    }

    //10번
    printf("10. 정수형 배열에 아무 숫자나 넣고 이 배열의 모든 값을 더해서 return 하는 함수를 작성하세요.\n");
    add_every_array_element();



    
    return 0;
}
