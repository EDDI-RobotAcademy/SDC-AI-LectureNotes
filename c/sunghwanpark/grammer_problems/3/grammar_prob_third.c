#include "grammar_prob_third.h"
#include "../2/grammar_prob_second.h"

// 3. 위의 2번에서 만든 랜덤 숫자가 2로 나눠서 나머지가 1인 경우만 출력하세요.

int return_if_remain_is_one(const int min, const int max)
{
    random_config();
    int result = generate_random(1,10);
    if(result % 2 == 1)
    {
        return result;
    }
    else{return -1;}
    return 0;
}