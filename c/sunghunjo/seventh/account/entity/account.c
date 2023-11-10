#include <stdlib.h>
#include <string.h>

#include "account.h"

// account를 초기화 해서 공간을 만든다.
account *init_account_object(char* name)
{
    // char* name를 받아와 name의 길이를 name_length에 저장을한다.
    int name_length = strlen(name) + 1;
    // tmp_account에 account만큼의 공간을 할당해준다.
    account *tmp_account = (account*)malloc(sizeof(account));
    // tmp_account가 *형이므로 ->로 접근을 하여 account형의 하위 내용으로 있는 
    // char* account_name에 char*공간을 name의 길이 + 1 만큼 만들어서 넣는다.
    tmp_account -> account_name = (char*)malloc(sizeof(char) * (name_length));
    // account_name에 name를 name_length만큼 복사해서 넣는다.
    strncpy(tmp_account -> account_name,name,name_length);

    // account*를 반환해야하 함으로 tmp_account를 반환해준다.
    return tmp_account;
}