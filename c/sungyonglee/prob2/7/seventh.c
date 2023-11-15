// 정수형 배열에 랜덤 숫자 3개를 입력한 이후 배열에 들어 있는 숫자를 출력하세요.
#include <stdio.h>


void config_random_seed_seventh(void)
{
    srand(time(NULL));
}

int generate_random_seventh(const int min, const int max)
{
    return rand() % (max - min +1) + min;
}

void print_int_array(void)
{
    config_random_seed_seventh();
    
    int random_number1, random_number2, random_number3;
    random_number1 = generate_random_seventh(1, 100);
    random_number2 = generate_random_seventh(1, 100);
    random_number3 = generate_random_seventh(1, 100);
    
    int array[3] = { random_number1, random_number2, random_number3};
    int *ptr = array;
    
    int i = 0;
    int sum_array = 0;
    for (i = 0; i < 3; i++)
    {
        int sum_array = sum_array + ptr[i];
        printf("정수형 배열 랜덤 숫자 3 개[%d] = %d\n", i, ptr[i]);
    }
    printf("배열의 합: %d\n", sum_array);
}

