#include "account_manager.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// _account_manager형의 global_account_manager를 전역변수로 선언한다.
account_manager global_account_manager;

// account_manager를 초기화 하는 형태이다.
void init_account_manager_object(void)
{
    // 구조체를 사용할 때 포인터 변수는 '->' 로 접근
    // 포인터가 아닌 변수는 '.' 으로 접근
    // _account_manager형의 global_account_manager의 
    // _account형의 account_array에 account형 공간 DEFAULT_ALLOC_COUNT(32)만큼 할당한다.
    global_account_manager.account_array = 
        (account*)malloc(sizeof(account) * DEFAULT_ALLOC_COUNT);
    
    // account_count는 int형이므로 DEFAULT_ALLOC_COUNT(32)를 대입한다.
    // account_count는 최대 account를 표시하는 것이다.
    global_account_manager.account_count = DEFAULT_ALLOC_COUNT;
    // current_account_index는 현재 몇번째 account인지 확인을 하기 위함이다.
    global_account_manager.current_account_index = 0;
}

// 이름을 받아와 넣는 느낌이다.
void register_new_account(char *name)
{
    int current_index = global_account_manager.current_account_index;
    int name_length = strlen(name) + 1;

    global_account_manager.account_array[current_index].account_name =
            (char *)malloc(sizeof(char) * name_length);

    strncpy(global_account_manager.account_array[current_index].account_name,
            name,
            name_length);
        
    global_account_manager.current_account_index++;
}

void print_account_manager(void)
{
    int i;
    int curruent_account_max = global_account_manager.current_account_index;
    printf("current_account_max: %d\n", curruent_account_max);

    for(i = 0; i < curruent_account_max; i++)
    {
        printf("사용자 name: %s\n", global_account_manager.account_array[i].account_name);
    }
}