#include <stdlib.h>
#include <string.h>

#include "account.h"

account *init_account_object(char *name)
{
    int name_length = strlen(name);
// 포인터의 특성은 메모리를 저장하는것
// 구조체에 포인터를 넣으려면 malloc 을 해줘야한다.
    account *tmp_account = (account *)malloc(sizeof(account));
    tmp_account->account_name = (char *)malloc(sizeof(char) * (name_length + 1));
    strncpy(tmp_account->account_name,  name, name_length);

    return tmp_account;
}