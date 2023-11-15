#include <stdio.h>

void inum(double);

int main(void)
{
    double input;

    printf("소수점 숫자를 가진 숫자를 입력하시오 : \n");
    scanf("%lf",&input);

    inum(input);

    return 0;
}

void inum(double output)
{
    int num1;
    double num2;

    num1 = output / 1;
    num2 = output - (int)output;

    printf("정수 부분은 : %d\n",num1);
    printf("소수점 부분은 : %lf\n",num2);

    
}