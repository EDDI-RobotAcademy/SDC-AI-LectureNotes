#include "function_one.h"

#include <stdio.h>

/*
    1. 스키장에서 스키 장비를 임대하는데 37500원이 든다. 또 3일 이상 이용할 경우 20%를 할인 해준다.
    일주일간 이용할 경우 임대 요금은 얼마일까 ? (연산 과정은 모두 함수로 돌린다)
*/

void ski_lease(int day)
{
    int i, total_price;
    int price = 37500;
    
    for (i = 1; i <= day; i++)
    {
        if (i < 3)
        {
            total_price = total_price + price;
        }
            
        total_price = total_price + price - price / 100 * 20;
    }

    printf("%d일간 이용한 스키 장비 임대비 : %d\n", day, total_price);
}