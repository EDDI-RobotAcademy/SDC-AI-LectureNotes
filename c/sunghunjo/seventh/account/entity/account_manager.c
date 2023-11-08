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

// 이름을 받아와 global_account_manager 에 넣는 느낌이다.
void register_new_account(char *name)
{
    // 현재 몇번째 인지를 나타낸다.
    // 항상 global_account_manager.current_account_index로 표현하기 힘드니 current_index로 대채
    int current_index = global_account_manager.current_account_index;
    // name의 길이이고 +1은 문자열 마지막에는 NULL이 들어가야 하기 때문에 자리를 만든다.
    int name_length = strlen(name) + 1;

    // account* 형태의 account_array는 char* 형태의 account_name를 가지고 있고
    // 포인터는 저장공간을 만들어 줘야 함으로 이름의 길이 + 1만큼의 char형태의 저장공간을 부여한다.
    global_account_manager.account_array[current_index].account_name =
            (char *)malloc(sizeof(char) * name_length);
    
    // 부여된 저장공간에 name의 문자열을 name_length만큼 복사해서 붙인다.
    strncpy(global_account_manager.account_array[current_index].account_name,
            name,
            name_length);
    
    // current_account_index는 현재 몇번째인지 알려주는 것으로
    // 후위연산자를 써서 마지막에 +1을 해서 다음번 register_new_account를 실행할 때
    // +1 이 된상태로 시작된다.
    global_account_manager.current_account_index++;
}

// account_manager.account_array.account_name의 문자열을 print하는 함수 
void print_account_manager(void)
{
    // 현재 account_array가 몇인지 나타낸다. 
    int i;
    // account_array가 몇개인지 나타낸다.
    int curruent_account_max = global_account_manager.current_account_index;
    printf("current_account_max: %d\n", curruent_account_max);

    for(i = 0; i < curruent_account_max; i++)
    {
        printf("사용자 name: %s\n", global_account_manager.account_array[i].account_name);
    }
}