#include <stdio.h>

#include "account/entity/account.h"

// struct vector를 만들고 이름과 x,y,z가 함께하게한다. 
// vector의 이름을 설정하고
// vector의 x,y,z를 설정한다.

// 2개의 vector를 비교한다.(x,y,z를 각각)
// 후에 통합 벡터 길이 = sqrt(x^2+y^2+z^2)(math.h)

#define MAX_ACCOUNT                 2

int main (void)
{
    int i;

    char *name[2] = {
        "조조",
        "유비"
    };

    account *account_array[MAX_ACCOUNT];

    for(i = 0; i <MAX_ACCOUNT; i++)
    {
        account_array[i] = init_account_object(name[i]);
        printf("사용자의 이름: %s\n", account_array[i]->account_name);
    }
    return 0;
}
