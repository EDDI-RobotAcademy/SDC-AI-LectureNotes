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
    
    // DEFAULT_ALLOC_COUNT 32 만큼 계정 갯수 할당
    global_account_manager.account_count = DEFAULT_ALLOC_COUNT;
    
    // 다른 함수에서 index를 사용하기 위해 0 을 대입하여 초기화
    global_account_manager.current_account_index = 0;
}

    // 계정 이름 저장 함수
void register_new_account(char *name)
{
    // 계정 정보 순서
    int current_index = global_account_manager.current_account_index;
    
    // 계정 이름 문자+1 길이 산정
    int name_length = strlen(name) +1;

    // 계정 이름 문자+1 만큼 메모리 할당
    global_account_manager.account_array[current_index].account_name = 
        (char *)malloc(sizeof(char) * name_length);
    
    // 계정 이름 저장
    strncpy(global_account_manager.account_array[current_index].account_name,
            name,
            name_length);

    // 계정 정보가 다음 신규 정보로 덮어씌워지지 않도록 index 증가시켜 구분
    global_account_manager.current_account_index++;
}

    // 계정 이름 인쇄 함수
void print_account_manager(void)
{
    int i;
    // 현재 index 정보를 계정 갯수로 대입 (0 부터 시작하여  마지막 처리 후 ++ 산정했음)
    int current_account_max = global_account_manager.current_account_index;
    
    // 계정 갯수 인쇄
    printf("current_account_max: %d\n", current_account_max);

    for (i = 0; i < current_account_max; i++)
    {
        // 저장된 계정이름을 반복문을 통해 0 ~ max 까지 인쇄
        printf("사용자 name: %s\n", global_account_manager.account_array[i].account_name);
    }
}