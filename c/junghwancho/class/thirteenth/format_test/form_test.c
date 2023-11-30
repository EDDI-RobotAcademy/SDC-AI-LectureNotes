#include "form_test.h"

#include <stdlib.h>
#include <string.h>

// 헤더에 선언된 exturn 이지만 여기에 한 번 더 선언
unsigned int test_form_unique_id;

// 밑에서 구르고 난 후에 id ++ 해서 id를 구분 및 관리하겠다.
int increment_test_form_unique_id(void)
{
    return test_form_unique_id++;
}

// return 받을 test_form type을 설정
// *를 쓴 이유
// 1. 메모리 공간이 다르기 때문에 = heap으로 저장해서 보관하기 위해, stack은 휘발성 (malloc을 사용하기 위해서)
test_form *init_test_form_with_id(int id, char *major, int age, char *self_introduction)
{
    // 결국 나중에 tmp_form으로 test_form을 리턴 받기 위해
    test_form *tmp_form = (test_form *)malloc(sizeof(test_form));
    // strlen = 문자열의 길이를 반환
    // char * 의 문자열을 구해서 malloc 하기 위해
    // strncpy를 해서 문자열을 복사하기 위해 = (heap에다 저장하기 위해, 안전하게 복사하기 위해)
    int major_length = strlen(major) + 1;
    int self_introduction_length = strlen(self_introduction) + 1;

    tmp_form->unique_id = id;
    // major_length * char size 만큼 heap에 메모리를 할당하되, char * 형태로 사용하겠다.
    // tmp_form의 major가 char * 형태이기 때문에 char * 형태로 사용, not because of parameter
    tmp_form->major = (char *)malloc(sizeof(char) * major_length);
    strncpy(tmp_form->major, major, major_length);

    tmp_form->age = age;

    tmp_form->self_introduction =
        (char *)malloc(sizeof(char) * self_introduction_length);
    strncpy(tmp_form->self_introduction, self_introduction, self_introduction_length);

    // 위에서 저장한 tmp_form 을 리턴 받아 사용(출력을 하던 뭘 하던)
    return tmp_form;
}

// test_form을 heap 메모리에 저장하기 위해 * 를 사용한 변수
test_form *init_test_form(char *major, int age, char *self_introduction)
{   
    // test_form type을 tmp_form으로 리턴 받기 위해 heap 메모리 할당
    test_form *tmp_form = (test_form *)malloc(sizeof(test_form));
    // 문자열인 major와 self_int에 malloc 하기 위해 문자 열 계산
    int major_length = strlen(major) + 1;
    int self_introduction_length = strlen(self_introduction) + 1;

    // 위에 선언된 함수대로 test_form_unique_id 를 입력한 뒤 ++ 하기 위해서
    tmp_form->unique_id = increment_test_form_unique_id();

    // major_length * char 만큼의 문자열을 char *로 사용하기 위해 메모리 할당
    // tmp_form의 major가 char * 형태이기 때문에 char *로 선언
    tmp_form->major = (char *)malloc(sizeof(char) * major_length);
    strncpy(tmp_form->major, major, major_length);

    tmp_form->age = age;

    tmp_form->self_introduction =
        (char *)malloc(sizeof(char) * self_introduction_length);
    strncpy(tmp_form->self_introduction, self_introduction, self_introduction_length);

    return tmp_form;
}

// 더블 포인터 = 포인터의 배열
// test_form *를 배열로 관리하기 위한 **(더블 포인터)

test_form** init_test_form_array(int count)
{
    test_form** tmp_format = (test_form **)malloc(sizeof(test_form *) * count);

    
    

    return tmp_format;
}