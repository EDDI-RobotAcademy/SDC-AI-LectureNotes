#include "account_manager.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

void register_new_account(char *name)
{
    int current_index = global_account_manager.current_account_index;
    int name_length = strlen(name) +1;

    global_account_manager.account_array[current_index].account_name = 
        (char *)malloc(sizeof(char) * name_length );
    
    strncpy(global_account_manager.account_array[current_index].account_name,
            name,
            name_length);

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