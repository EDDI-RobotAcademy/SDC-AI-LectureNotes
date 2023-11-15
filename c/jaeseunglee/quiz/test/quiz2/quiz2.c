#include <stdio.h>
#include <stdlib.h>

#include "../random/random.h"
#include "quiz2.h"

// 1. 아무 변수나 만들고 변수 값을 출력하세요.

void quiz2_1()
{
    int num;
    num = 1;
    printf("quiz2_1\n");
    printf("무작위 변수값 %d\n",num);
    printf("\n");
}

// 2. 랜덤 숫자를 출력하세요.

void quiz2_2()
{
    int random_num;
    random_num = random_int();
    printf("quiz2_2\n");
    printf("무작위 정수 %d\n",random_num);
    printf("\n");
}


// 3. 위의 2번에서 만든 랜덤 숫자가 2로 나눠서 나머지가 1인 경우만 출력하세요.

void quiz2_3()
{
    printf("quiz2_3\n");
    int random_num;
    random_num = random_int();
    if(random_num%2 == 1)
    {
        printf("무작위 정수 %d\n",random_num);

   
    }
    else
    {
        printf("짝수입니다\n");
    }
    printf("\n");
}


// 4. 숫자 3 ~ 숫자 20 사이의 모든 정수를 출력하세요.

void quiz2_4()
{
    int min = 3;
    int max = 20;
    
    
    int loop;
    printf("quiz2_4\n");

    for (loop = min; loop < max+1; loop++)
    {
        printf("%d\n",loop);
    }

    printf("\n");
}


// 5. 정수형 인자 1개를 파라미터로 받아 출력하세요.

void quiz2_5(const int num)
{
    
    printf("quiz2_5\n");

    printf("%d\n",num);

    printf("\n");
}


// 6. 정수형 인자 2개를 파라미터로 받아 더한 결과를 return 하세요.

int quiz2_6(const int num1, const int num2)
{
    printf("quiz2_6\n");

    printf("%d + %d = %d\n",num1, num2, num1 + num2);

    printf("\n");

    return num1+num2;
}


// 7. 정수형 배열에 랜덤 숫자 3개를 입력한 이후 배열에 들어 있는 숫자를 출력하세요.

void quiz2_7()
{
    int loop;
    int num[3];
    num[0] = random_int();
    num[1] = random_int();
    num[2] = random_int();

    printf("quiz2_7\n");
    for (loop = 0; loop <3; loop ++)
    {
        printf("num[%d] = %d\n",loop, num[loop] );    
    }
    

    printf("\n");
}


// 8. 랜덤을 돌려서 임의 개수의 정수형 동적 배열을 만들고 동적 배열에 숫자를 넣은 이후 출력하세요.

void quiz2_8()
{
    
    printf("quiz2_8\n");
    int loop;
    int size = random_int();
    int* arr = (int*)malloc(sizeof(int) * size);
    for(loop = 0; loop < size; loop++)
    {
        arr[loop] = random_int();
    }

    for(loop = 0; loop < size; loop++)
    {
        printf("arr[%d] = %d\n", loop, arr[loop]);
    }

    printf("\n");
}


// 9. 정수형 배열에 아무 숫자나 넣고 이 배열을 파라미터로 받아 출력하는 함수를 작성하세요.

void quiz2_9()
{
    printf("quiz2_9\n");
    int loop;
    int size = random_int();
    int* arr = (int*)malloc(sizeof(int) * size);
    for(loop = 0; loop < size; loop++)
    {
        arr[loop] = random_int();
    }
    
    quiz2_9_1(arr,size);

    printf("\n");
}

void quiz2_9_1(int arr[], const int size)
{
    
    int loop;
    for(loop = 0; loop < size; loop++)
    {
        printf("arr[%d] = %d\n",loop,arr[loop]);
    }
    
}


// 10. 정수형 배열에 아무 숫자나 넣고 이 배열의 모든 값을 더해서 return 하는 함수를 작성하세요.

int quiz2_10()
{
    printf("quiz2_10\n");
    int loop;
    int size = random_int()+1;
    printf("size: %d\n",size);
    int* arr = (int*)malloc(sizeof(int) * size);
    for(loop = 0; loop < size; loop++)
    {
        arr[loop] = random_int();
    }
    

    return quiz2_10_1(arr, size);

}

int quiz2_10_1(int arr[], const int size)
{
    
    int result=0;
    int loop;
    for(loop = 0; loop < size; loop++)
    {
        printf("arr[%d] = %d\n",loop,arr[loop]);
        result += arr[loop];
    }
    printf("총 합계: %d\n", result);
    printf("\n");

    return result;
    
}

// 11. 아무런 구조체 대충 하나 만들고 내부에 값을 할당하여 출력해봅시다.


void quiz2_11()
{
    printf("quiz2_11\n");
    sample sam;
    sam.num = random_int();

    printf("sam.num = %d\n",sam.num);
    printf("\n");
}


// 12. 구조체 내부에 char * 형태의 내용을 배치하고 이 내용에 값을 할당하여 출력해봅시다.



void quiz2_12()
{
    sample2 sam2;
    sam2.name = "아아아아아아앙아";
    printf("quiz2_12\n");

    printf("sam2.name = %s\n",sam2.name);


    printf("\n");
}

