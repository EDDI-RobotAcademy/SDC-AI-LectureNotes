#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "11/eleventh.h"

#define MIN             1
#define MAX             10

int generate_random(const int min,const int max)
{
    return rand() % (max - min +1) + min;
}

void int_print(int num)
{
    printf("정수 출력: %d\n",num);
}

int int_sum(int num1,int num2)
{
    return num1+ num2;
}

void int_array_print(int *number,int num)
{
    int i;

    for(i = 0; i < num ; i++)
    {
        printf("정수형 배열 출력: %d\n",number[i]);
    }
}

int int_array_sum(int *number, int num)
{
    int i;
    int sum = 0;

    for(i = 0; i < num ; i++)
    {
        sum += number[i];
    }
    return sum;
}



int main (void)
{
    //1. 아무 변수나 만들고 변수 값을 출력하세요.
    int num = 1;
    int i;
    printf("변수 출력:%d \n",num);
    
    //2. 랜덤 숫자를 출력하세요.
    srand(time(NULL));
    num = generate_random(MIN,MAX);
    printf("랜덤 출력:%d \n",num);
    
    // 3. 위의 2번에서 만든 랜덤 숫자가 2로 나눠서 나머지가 1인 경우만 출력하세요.
    if(num % 2 == 1)
    {
        printf("홀수 출력:%d \n",num);
    }
    //4. 숫자 3 ~ 숫자 20 사이의 모든 정수를 출력하세요.
    for(i = 4; i < 20 ;i++)
    {
        printf("3 ~ 20사이의 모든 정수출력: %d\n",i);
    }

    // 5. 정수형 인자 1개를 파라미터로 받아 출력하세요.
    int_print(num);

    // 6. 정수형 인자 2개를 파라미터로 받아 더한 결과를 return 하세요.
    printf("두가지 정수를 더한 값: %d\n",int_sum(num,i));

    //7. 정수형 배열에 랜덤 숫자 3개를 입력한 이후 배열에 들어 있는 숫자를 출력하세요.
    int number[3] = {
        generate_random(MIN,MAX),
        generate_random(MIN,MAX),
        generate_random(MIN,MAX)
    };
    for(i = 0; i <3 ; i++)
    {
        printf("정수형 배열 출력: %d\n",number[i]);
    }

    //8. 랜덤을 돌려서 임의 개수의 정수형 동적 배열을 만들고 동적 배열에 숫자를 넣은 이후 출력하세요.
    int *random_number;
    random_number = (int*)malloc(sizeof(int) * num);

    for(i = 0; i < num ; i++)
    {
        random_number[i] = generate_random(MIN,MAX);
        printf("랜덤 배열 출력: %d\n",random_number[i]);
    }

    //9. 정수형 배열에 아무 숫자나 넣고 이 배열을 파라미터로 받아 출력하는 함수를 작성하세요.
    int_array_print(random_number,num);

    //10. 정수형 배열에 아무 숫자나 넣고 이 배열의 모든 값을 더해서 return 하는 함수를 작성하세요.
    printf("모든 배열의 합: %d\n", int_array_sum(random_number,num));
    
    // 11. 아무런 구조체 대충 하나 만들고 내부에 값을 할당하여 출력해봅시다.
    // 12. 구조체 내부에 char * 형태의 내용을 배치하고 이 내용에 값을 할당하여 출력해봅시다.
 
    eleventh *char_name;
    char *char_pointer = "졸려서 힘들어요";

    char_name = init_eleven_();
    init_char_(char_name,char_pointer);

    print_eleveth_name(char_name);

    return 0;

    
}
