#include "add_multiple.h"
void add_multiple(void)
{
    int i;
    int sum=0;
    for(i=0;i<=1000;i++)
    {
        if(i % 3==0)
        sum+=i;
    }
    printf("총 합은? -->%d",sum);
}