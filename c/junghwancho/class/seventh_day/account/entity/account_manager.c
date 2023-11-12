#include "account_manager.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

account_manager global_account_manager;

void init_account_manager_object(void)
{
    // 구조체를 사용할 때 포인터 변수는 '->' 로 접근
    // 포인터가 아닌 변수는 '.' 으로 접근
    // 구조체 내부의 정보를 볼 때
    global_account_manager.account_array = 
        (account *)malloc(sizeof(account) * DEFAULT_ALLOC_COUNT);

    global_account_manager.account_count = DEFAULT_ALLOC_COUNT; // 현재 몇개 까지 할당할 수 있는지 MAX 값 지정
    global_account_manager.current_account_index = 0; // 실제 몇 명 할당 했는지
}

void register_new_account(char *name)
{
    int current_index = global_account_manager.current_account_index;
    int name_length = strlen(name) + 1 ;
    
    global_account_manager.account_array[current_index].account_name =
         (char *)malloc(sizeof(char) * name_length); // 포인터에는 반드시 메모리 할당 해줘야함

    strncpy(global_account_manager.account_array[current_index].account_name,
            name,
            name_length);

    global_account_manager.current_account_index++; // 생성된 만큼 index 증가
}

void print_account_manager(void)
{
    int i;
    int current_account_max = global_account_manager.current_account_index;
    printf("current_account_max: %d\n", current_account_max);

    for (i = 0; i < current_account_max; i++)
    {
        printf("사용자 name: %s\n", global_account_manager.account_array[i].account_name);
    }
}