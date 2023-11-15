#include <stdlib.h>
#include <string.h>

#include "account.h"

account *init_account_object(char* name)
{
    int name_length = strlen(name) + 1;
    account *tmp_account = (account*)malloc(sizeof(account));
    tmp_account -> account_name = (char*)malloc(sizeof(char) * (name_length));
    strncpy(tmp_account -> account_name,name,name_length);

    return tmp_account;
}
