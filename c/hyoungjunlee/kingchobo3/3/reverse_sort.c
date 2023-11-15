#include "reverse_sort.h"
#include <string.h>
#include <stdio.h>
void reverse_sort(void)
{
    int arr[10]= {3, 77, 10, 7, 4, 9, 1, 8, 21, 33};
    int tmp;
    
    int len=sizeof(arr)/sizeof(int);
    int k=len-1;
    
    
    for(int i=0;i<len/2;i++)
    {
        tmp = arr[i];
        arr[i]=arr[k-i];
        arr[k-i]=tmp;
    }
    for(int j=0;j<len;j++)
    {
        printf("%d ",arr[j]);
    }
    int even=0;
    int odd =0;
    for(int p=0;p<len;p++)
    {
        if(p % 2 == 0)
            even+=arr[p];
        if(p % 2 == 1)
            odd+=arr[p];
    }
    printf("홀수요소 합 %d 짝수요소 합 %d 둘의 곱 %d",even,odd,even*odd);
}