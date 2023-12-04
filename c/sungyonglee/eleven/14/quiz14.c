#include <stdio.h>

/*
2개를 숫자를 입력 받아서
누가 더 큰지 혹은 같은지 판별할 수 있는 프로그램을 작성하시오.
제어문을 사용하지 않고 구현하도록함!
printf는 여러번 사용해도 무방!
(반드시 함수를 사용하도록!)
*/



int number1;
int number2;

void quiz14(void)
{
printf("number1 입력:");
scanf("%d",&number1);
printf("number2 입력:");
scanf("%d",&number2);
    if (number1 > number2)
    {
        printf("number1 이 더 큽니다.\n");
    }
    else if (number1 < number2)
    {
        printf("number2 이 더 큽니다.\n");
    }
    else
    {
        printf("number1 과 number2 는 같습니다.\n");
    }

}