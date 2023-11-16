#include <stdio.h>
#include "get_divisor.h"
void get_divisor(void)
{
    int num;
    printf("입력하세요");
    scanf("%d",&num);
    int i,j;
    printf("%d의 약수는\n",num);
    printf("( ");
    for(i=1;i<num;i++)
    {
        if(num % i==0)
            printf("%d, ",i);
    }
    printf("%d",num);
    printf(" )");
}