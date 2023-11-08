#include "account_manager.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 구조체 함수를 불러오기 위한 변수 
account_manager global_account_manager;

void init_account_manager_object(void)
{
    // 구조체를 사용할 때 포인터 변수는 '->' 로 접근 포인터가 아닌 변수는 '.' 으로 접근 
    // account_array는 포인터이므로 메무리 할당 필수 
    global_account_manager.account_array = 
        (account *)malloc(sizeof(account) *DEFAULT_ALLOC_COUNT);
    // 계정 갯수 최대 32개까지 (DEFAULT_ALLOC_COUNT =32 이라고 define 됨)
    global_account_manager.account_count = DEFAULT_ALLOC_COUNT;
    // 0에서 시작 
    global_account_manager.current_account_index =0;
}

// 새로운 계정 메모리 할당 
void register_new_account(char *name)
{   
    // global_account_manager.current_account_index = 0 이므로 current_index 도 0 
    int current_index = global_account_manager.current_account_index;
    int name_length = strlen(name)+1;

    // account_name은 포인터이므로 메모리 할당은 필수다. (account.h에서 포인터 생성)
    global_account_manager.account_array[current_index].account_name = 
        (char*)malloc(sizeof(char)* name_length+1);

    // char * 타입의 문자열 복사
    strncpy(global_account_manager.account_array[current_index].account_name,
            name,
            name_length); 
    // 회원의 수를 더 받을 수 있게끔 값을 더해준다. (함수 여러 번 실행)
    global_account_manager.current_account_index++;
}

void print_account_manager(void)
{
    int i;
    // global_account_manager.current_account_index++ 때문에 값이 더해져 current_account_max = 1 
    int current_account_max = global_account_manager.current_account_index;

    printf("current_account_max: %d\n", current_account_max);
    for (i = 0; i < current_account_max; i++)
    {
        printf("사용자 name: %s\n", global_account_manager.account_array[i]);
    }
}