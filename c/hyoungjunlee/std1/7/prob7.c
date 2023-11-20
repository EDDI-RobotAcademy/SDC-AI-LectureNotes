#include "prob7.h"
#include "../random_set/get_random.h"
void prob7(void)
{
    random_seed();
    int arr[3];
    for(int i=0;i<3;i++)
    {
        arr[i] = get_random();
        printf("--> %d ",arr[i]);
    }
    
}