#include "prob10.h"
int prob10(int *arr)
{
    int sum=0;
    for(int i=0; i<7;i++)
    {
        printf("배열 값 %d\n",arr[i]);
        sum += arr[i];
    }
    return sum;
}
//10. 정수형 배열에 아무 숫자나 넣고 이 배열의 모든 값을 더해서 return 하는 함수를 작성하세요.