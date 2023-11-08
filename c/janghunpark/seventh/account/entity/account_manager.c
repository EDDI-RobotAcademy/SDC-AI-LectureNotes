#include "account_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

account_manager global_account_manager;

void init_account_manager_object(void)
{
    // 구조체를 사용할 때 포인터 변수는 '->' 로 접근
    // 포인터가 아닌 변수는 '.' 으로 접근
    global_account_manager.account_array = 
        (account *)malloc(sizeof(account) * DEFAULT_ALLOC_COUNT);

    global_account_manager.account_count = DEFAULT_ALLOC_COUNT;
    global_account_manager.current_account_index = 0;
}

// 새로운 계정 추가
void register_new_account(char *name)
{
    int current_index = global_account_manager.current_account_index;
    int name_length = strlen(name) + 1;
    // 이름 길이값을 구한다.
    // +1 은 null 을 형성하여 문제 방지한다.

    // 포인터에 메모리가 할당되어 있지 않으면 segmentation fault 오류가 뜬다. 잊지 말것!
    global_account_manager.account_array[current_index].account_name = 
        (char *)malloc(sizeof(char) * name_length);
    
    // strncpy (메모리, 문자열, 문자열 길이) = 메모리에 문자열을 문자열의 길이만큼 복붙
    strncpy(global_account_manager.account_array[current_index].account_name, 
            name, 
            name_length);

    // 사용자를 한 명씩 더 입력할 때마다 print되는 current_account_max의 숫자를 하나씩 늘림
    global_account_manager.current_account_index++;
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