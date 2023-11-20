#include  "grammar_prob_fourth.h"

// 4. 숫자 3 ~ 숫자 20 사이의 모든 정수를 출력하세요

#include <stdlib.h>
int return_integers( int num1,  int num2)
{
    printf("숫자 출력: ");

    while(num1 <= num2)
    {   
        printf(" %d ",num1) ;
        num1++;
        
    }
    printf("\n");
    return 0;
}