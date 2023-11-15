#include "func_var_fourteenth.h"
// 14. 2개를 숫자를 입력 받아서 누가 더 큰지 혹은 같은지 판별할 수 있는 프로그램을 작성하시오.
// 제어문을 사용하지 않고 구현하도록함!

int which_one_is_bigger(int num1, int num2)
{
    if(num1 > num2)
    {
        return num1;
    }
    if(num1 < num2)
    {
        return num2;
    }
    return 0;
}