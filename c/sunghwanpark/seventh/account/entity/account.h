#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// account = struct _account 
typedef struct _account account;

struct _account
{
    //포인터 계정 이름 생성 
    char *account_name;
};


account *init_account_object(char *name);



#endif