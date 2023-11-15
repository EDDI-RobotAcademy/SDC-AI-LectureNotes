#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

typedef struct _account account;

struct _account
{
    char *account_name;
};

account *init_account_object(char *name);

#endif