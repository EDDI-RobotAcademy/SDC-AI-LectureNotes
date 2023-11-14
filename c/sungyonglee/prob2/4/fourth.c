// 숫자 3 ~ 숫자 20 사이의 모든 정수를 출력하세요.

#include <stdio.h>

void print_number_three_to_twenty(void)
{
    int loop ;

    printf("3 부터 20 까지 인쇄: \n");

    for (loop = 3; loop < 21; loop++)
    {        
        printf("%d\n", loop);
    }
}