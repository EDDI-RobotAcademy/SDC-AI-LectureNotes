#include "account_manager.h"
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

void register_new_account(char *name)
{
    int current_index = global_account_manager.current_account_index;
    int name_length = strlen(name);
    
    strncpy(&global_account_manager.account_array[current_index],
            name,
            name_length);
}
