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


int main (void)
{
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
    
    
    return 0;
}
