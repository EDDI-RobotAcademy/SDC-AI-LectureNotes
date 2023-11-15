// 실수와 정수를 입력받고 그 값을 함수의 인자로 넘겨 두 수의 곱을 실수형으로 반환하여 출력하라
#include "first.h"

#include <stdio.h>

float first_add(int number1, float number2)
{
    
    int result = number1 * number2;
    printf("%d\n",number1);
    printf("%f\n",number2);
    printf("%d\n", result);

    return number1 * number2;
}
