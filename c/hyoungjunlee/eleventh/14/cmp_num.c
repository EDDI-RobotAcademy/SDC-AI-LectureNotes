#include "cmp_num.h"
#include <stdio.h>
void cmp_num(void)
{
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    int result = num1>num2 ? num1:num2;
    printf("num1 %d, num2 %d 더 큰값 %d",num1,num2,result);
}