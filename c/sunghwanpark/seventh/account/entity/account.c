#include <stdlib.h>
#include <string.h>
#include "account.h"

account *init_account_object(char *name)
{   
    // 이름 길이 변수 생성 
    int name_length = strlen(name);

    // 함수 메모리 공간을 저장하는 임시 포인터 생성 
    account *tmp_account = (account *)malloc(sizeof(account));

    // tmp_account는 포인터 변수 (헤더 파일에서 구조체 안에 생성); 그러므로 '->'로 접근한다. 
    tmp_account -> account_name = (char *)malloc(sizeof(char) *(name_length+1));

    // char * 타입의 문자열 복사 
    strncpy(tmp_account ->account_name,name,name_length);

    return tmp_account;
}