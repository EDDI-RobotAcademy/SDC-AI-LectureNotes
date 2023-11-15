// Entity란 생명 주기가 있는 정보입니다.
// 사용자 정보라는 것은 처음 회원 가입을 할 때 객체가 만들어집니다.
// 그리고 회원 탈퇴를 할 때 객체의 수명이 끝나게 됩니다.
// 이와 같이 생명 주기가 있고 관리할 정보의 대상이라면 Entity가 됩니다.
// 그러므로 실제로 Entity는 Business에 있어서 핵심 업무 규칙이 됩니다.

// 고로 예를 하나 들어보자면 불(전등)을 키고 끄는 사업이라면 Entity가 무엇일까요?
// 실제로 LED가 가지고 있는 상태값을 보고 켜졌는지 꺼졌는지를 판단 할 수 있습니다.
#ifndef __LED_H__
#define __LED_H__


#include <stdbool.h>

// typedef는 사실상 #define과 거의 유사함
// 차이가 있다면 #define으로 type을 만들지는 못함
// 그러나 type는 특정 타입을 만드는 작업을 수행함
// 고로 typedef struct _led led는 아래를 의미함
// struct _led 로 적어야 하는 문법을 led로 퉁 치겠습니다.
typedef struct _led led;

// 구조체를 작성하는 경우엔 아래의 방식으로 작성합니다.
// 1. struct (새로 커스텀하여 만들 이름)
// 2. 중괄호 열고 닫은 이후 마지막에 ';' 추가
// 3. 커스텀한 내용이 어떤 정보들을 달게 할 것인지 데이터 배치
struct _led
{
    bool status;
};

extern int led_array_count;
// ex) 계정
// char *namep[10];
// int age[10];
// char *address[10];

// account *account_array
// 결론적으로 class가 되었건 struct(구조체)가 되었건
// 진정한 목적은 type을 custom 하겠다는 것이 중요합니다.
led *init_led_objeckt(int count);
void set_led_statuse(led *array, int led_index, bool on_off);
void print_led_array_status(led *array);

#endif