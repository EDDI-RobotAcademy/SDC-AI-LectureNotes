#include <stdio.h>

#include "ski.h"

void ski_cost_evaluation(int one_day_cost, int days)
{
    printf("하루 렌탈 비용: %d원\n", one_day_cost);
    printf("대여 기간: %d일\n", days);
    
    int total_cost;
    float discount_rate = 0.8;

    if (days < 3)
    {
        total_cost = one_day_cost * days;
        printf("렌탈 비용 = %d\n", total_cost);
    }
    if (days >= 3)
    {
        total_cost = (one_day_cost * days) * discount_rate;
        printf("오래 빌리셔서 할인이 적용됩니다!\n");
        printf("렌탈 비용 = %d\n", total_cost);
    }
}