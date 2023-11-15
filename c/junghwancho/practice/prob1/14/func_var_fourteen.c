/*14. 2개를 숫자를 입력 받아서
    누가 더 큰지 혹은 같은지 판별할 수 있는 프로그램을 작성하시오.
    제어문을 사용하지 않고 구현하도록함!
    printf는 여러번 사용해도 무방!
    (반드시 함수를 사용하도록!)*/

// 1. 숫자 2개 입력 함수 생성
// 2. 더 큰지 판별
// 3. 같은지 판별
#include <stdio.h>
#include "func_var_fourteen.h"

int check_who_is_bigger(int num1, int num2)
{
    if (num1 > num2)
    {
        printf("num1:%d, num2:%d로 num1이 더 큽니다.\n", num1, num2);
        return num1;
    }
    if (num1 < num2)
    {
        printf("num1:%d, num2:%d로 num2이 더 큽니다.\n", num1, num2);
        return num2;
    }
    if (num1 == num2)
    {
        printf("num1:%d, num2:%d로 같습니다.\n", num1, num2);
        return num1;   
    }  

    return 0; 
}