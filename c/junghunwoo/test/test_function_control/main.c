#include <stdio.h>

#include "1/function_one.h"
#include "2/function_two.h"
#include "3/function_three.h"
#include "4/function_four.h"


int mult2(int num)

{

    return num * 2;

}

int main (void)
{
    //1번 문제
    ski_lease(7);
    
    //2번 분제
    number_dvisor(88);

    //3번 문제
    sum_multiple(3);

    //4번 문제
    sum_multiple_other(4, 6);

    //5번 문제


    //6번 문제

    //7번 문제
    int i, sum = 0, result;

    for(i = 0; i < 5; i++)

        sum += i;

    result = mult2(sum);



    return 0;
}
