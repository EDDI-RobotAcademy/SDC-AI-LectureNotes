#include "prob9.h"
void prob9(int *arr,int a)
{
    
    for(int i=0;i<a/sizeof(int);i++)
    {
        printf("arr[%d]번 칸-> %d\n",i,arr[i]);
    }
}