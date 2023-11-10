#ifndef __ACCOUNT_MANAGER_H__
#define __ACCOUNT_MANAGER_H__

// account.h 에서 정보를 가져온다 
#include "account.h"

#define DEFAULT_ALLOC_COUNT 32

// account_manager = struct _account_manager 
typedef struct _account_manager account_manager;

struct _account_manager
{
    // 게정관리 구조체 안에 계정 갯수 변수 생성 
    int account_count;
    account *account_array;
    int current_account_index;
};

extern account_manager global_account_manager; 

void init_account_manager_object(void);
void register_new_account(char *name);
void print_account_manager(void);
#endif