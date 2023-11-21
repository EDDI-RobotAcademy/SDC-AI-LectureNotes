#include "prob8.h"
#include "../random_set/get_random.h"
void prob8(void)
{
    random_seed();
    int len = get_random();
    printf("랜덤 배열 길이는 이거 ->%d\n",len);
    int* arr = (int*)malloc(sizeof(int)*len);
    for(int i=0; i<len;i++)
    {
        arr[i]=i;
        printf("값 -> %d\n",arr[i]);
    }
}
