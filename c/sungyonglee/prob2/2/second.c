// 랜덤 숫자를 출력하세요.

#include <stdlib.h>
#include <time.h>

void config_random_seed(void)
{
    srand(time(NULL));
}

int generate_random(const int min, const int max)
{
    return rand() % (max - min +1) + min;
}

int random_number(void)
{
    int number;
    number = generate_random(1, 100);

    if (number % 2 == 0)
    {
        printf("랜덤 숫자 출력: %d,\n", number);    
    }
    else
    {
        printf("랜덤 숫자가 홀수이므로 출력하지 않습니다.\n");
    }
}
