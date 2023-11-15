#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define MAX 100
#define MIN 1
#define COUNT 1

// 5번
void printAge(int number) 
    {
    printf("입력된 정수: %d\n", number);
    }

// 6번
int Sum(int num1, int num2) 
{
    int sum = num1 + num2;

    printf("\n");
    return sum;
}


// 7번
void printArray(int arr[], int size) 
{
    printf(" 랜덤 배열 : ");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
   printf("\n");
}


int main() 
{
    // 1번 문제 아무 변수나 만들고 변수 값을 출력하세요. = 29
    int num = 29;
    printf("%d\n", num);

    // 2번 문제 랜덤 숫자를 출력하세요
    int min = MIN;
    int max = MAX;
    int i;
    int count = COUNT;

    

    printf("랜덤 숫자 출력:\n");

    for (i = 0; i < count; i++) 
    {
        int random_number = rand() % (max - min + 1) + min;
        printf("%d ", random_number);
    }
    printf("\n");

    // 3번 위에서 만든 랜덤 숫자가 2로 나눠서 나머지가 1인 경우만 출력하세요
    printf("랜덤 숫자 홀수 출력:\n");

    for (i = 0; i < count; i++) 
    {
        int random_number = rand() % (max - min + 1) + min;
        if (random_number % 2 == 1) 
        {
            printf("%d ", random_number);
        }
    }
    printf("\n");

    // 4. 숫자 3~20사이의 모든 정수를 출력하세요
   printf("3~20에서 정수 출력:\n");

   for (i = 3; i <= 20; i++) 
   {
        printf("%d", i);
   }
   printf("\n");

    // 5. 정수형 인자 1개를 파라미터로 받아 출력하세요
    int input = 29;
    printAge(input);

    // 6. 정수형 인자 2개를 파라미터로 받아 더한 결과를 return하세요.
        int input1 = 29;
        int input2 = 30;

        int result = Sum(input1, input2);

    printf("두 정수의 합: %d", result);

    printf("\n");

    // 7. 정수형 배열에 랜덤 숫자 3개를 입력한 이후 배열에 들어 있는 숫자를 출력하세요
    int arr[SIZE];
   

    for (int i = 0; i < SIZE; i++) 
    {
        arr[i] = rand() % (MAX - MIN + 1) + MIN;
    }
    printArray(arr, SIZE);

 
   
  

    srand(time(NULL));
    
    return 0;

}
