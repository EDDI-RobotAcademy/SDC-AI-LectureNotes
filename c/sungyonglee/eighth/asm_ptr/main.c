#include <stdio.h>

int main (void)
{
    int i;
    int number = 4;
    int number2 = 7;
    int number3 =33;
    int *ptr = &number;
    printf("*ptr = %d\n", *ptr);

    int array[3] = { 1, 2, 3 };
    int *ptr2 = array;
    for (i = 0; i < 3; i++)
    {
        printf("ptr2[%d] = %d\n", i, ptr2[i]);
    }

    int *array2[3] = { &number, &number2, &number3 };
    int **ptr3 = array2;

    for (i = 0; i < 3; i++)
    {
        printf("*ptr3[%d] = %d\n", i, *ptr3[i]);
    }

    int **array3[1] = { array2 };
    int ***ptr4 = array3;

    // 연산자 순서가 대괄호가 빠릅니다.
    printf("**ptr4[%d] = %d\n", 0, **ptr4[0]);      // ptr4 이 지정한 array3이 1개 배열 뿐이기 때문에 **ptr4[1]은 정해지지 않은 값이 출력될 수 있음. 만약 있다면 제일 앞의 값이 출력 됨.
    printf("*(*ptr4)[%d] = %d\n", 0, *(*ptr4)[0]);
    printf("*(*ptr4)[%d] = %d\n", 1, *(*ptr4)[1]);
    printf("*(*ptr4)[%d] = %d\n", 2, *(*ptr4)[2]);

    return 0;
}