#ifndef __ACCOUNT_MANAGER_H__
#define __ACCOUNT_MANAGER_H__

#include "account.h"

#define DEFAULT_ALLOC_COUNT         32

typedef struct _account_manager account_manager;

struct _account_manager
{
    int account_count;
    account *account_array;
    int current_account_index;
};

extern account_manager global_account_manager;

void init_account_manager_object(void);
void register_new_account(char *name);
void print_account_manager(void);

#endif