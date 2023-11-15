#include <stdio.h>

#include "1/first.h"
#include "2/second.h"
#include "3/third.h"
#include "4/fourth.h"

int main (void)
{
    // 1번
    
    printf("1. 아무 변수나 만들고 변수 값을 출력하세요.\n");
    printf("result = %d\n",intger(9,10));

    // 2번

    printf("2. 랜덤 숫자를 출력하세요.\n");
    printf("랜덤 값은 : %d\n",random_gen(1,100));

    //3번
    
    printf("3. 위의 2번에서 만든 랜덤 숫자가 2로 나눠서 나머지가 1인 경우만 출력하세요.\n");
    printf("%d\n",random_num());

    //4번

    printf("4. 숫자 3 ~ 숫자 20 사이의 모든 정수를 출력하세요.\n");
    printf("%d",for_ex());
    
    
    return 0;
}
