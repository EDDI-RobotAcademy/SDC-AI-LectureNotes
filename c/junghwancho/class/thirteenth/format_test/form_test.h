#ifndef __FORM_TEST_H__
#define __FORM_TEST_H__

// extern = 전역 변수, 외부에서 쓸 수 있는 변수
// unsigned int = 양수의 정수만 사용한다. int 보다 사용 가능 숫자가 2배 더 많다 42억 ..
extern unsigned int test_form_unique_id;

// type 지정하겠다.
// _이하를 뒤에 꺼로 부르겠다.
typedef struct _test_form test_form;

// 구조체를 정의하겠다
// 구조체가 가지고 있는 정보는 아래와 같음
struct _test_form
{
    int unique_id;
    // C에는 문자열을 표현하는 방법이 없어서, char 포인터를 사용해서 문자열의 첫 글자의 주소를 가져옴(malloc으로 문자열을 배치할 메모리 확보)
    // char * 대신에 char [] 가 들어갈 수도 있다.
    char *major;
    int age;
    char *self_introduction;
};

int increment_test_form_unique_id(void);
test_form *init_test_form_with_id(int id, char *major, int age, char *self_introduction);
test_form *init_test_form(char *, int, char *);
test_form **init_test_form_array(int count);

#endif