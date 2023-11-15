#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// _account 타입을 만들어서 실제 사용할때는 account로 사용가능
typedef struct _account account;

// _account 타입에서 char *account_name이라는 구조의 하위를 만든다.
struct _account
{
    char *account_name;
};

account *init_account_object(char *name);

#endif
