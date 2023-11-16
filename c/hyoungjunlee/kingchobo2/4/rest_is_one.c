#include <stdio.h>
void rest_is_one(void)
{
    int sum =0;
    for(int i=1;i<=13;i++)
    {
        if(i % 4 ==1)
        {
            if(i % 6 ==1)
            { 
                sum +=i;
            }
        }

    }
    printf("4나 6으로 나눠도 나머지가 1인 수들의 합->%d",sum);
}