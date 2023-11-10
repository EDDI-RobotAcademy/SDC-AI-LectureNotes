 #include <stdio.h>

// Quiz. 함수 내부에서 계산한 배열을 리턴 할 수 있는 방법이 있을까요 ?
// int[3] * returned_array (void)
// int 3개짜리 묶음의 포인터로 보겠다는 뜻
int (* returned_array(void))[3]
{
    static int test_array[3][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    return test_array;
}

int main (void)
{
    int i, j;
    int (*arr)[3];
    int num1 = 1, num2 = 2, num3 = 3;
    // int 타입의 메모리 주소를 저장하는 배열 3개
    int *number_array[3] = {&num1, &num2, &num3};
    
    int matrix[4][4] = {
        {1, 2, 3, 4 },
        {5, 6, 7, 8 },
        {9, 10,11,12},
        {13,14,15,16}
    };
    
    // int[3] * array_pointer 형태임
    // int 가 3개짜리인 녀석의 메모리 주소를 저장하는 그냥 포인터 변수임
    // 즉 12바이트 짜리 포인터 변수

    int (* array_pointer)[3] = matrix;

    for(i = 0; i<5; i++)
    {
        printf("array_pointer[%d] = %d\n", i , *array_pointer[i]);
    }
    
    arr = returned_array();
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("arr[%d][%d] = %d\n", i,j,arr[i][j]);
        }
    }

    return 0;
}
