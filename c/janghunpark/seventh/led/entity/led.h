// Entity란 생명 주기가 있는 정보입니다.
// 사용자 정보라는 것은 처음 회원 가입을 할 때 객체(객체 지향 프로그램에서 데이터와 그 데이터에 관련된 동작 모두)가 만들어집니다.
// 그리고 회원 탈퇴를 할 때 객체의 수명이 끝나게 됩니다.
// 이와 같이 생명 주기가 있고 관리할 정보의 대상이라면 Entity가 됩니다.
// 그러므로 실제로 Entity는 비즈니스에 있어서 핵심 업무 규칙이 됩니다.

// 고로 예를 하나 들어보자면 불(전등)을 키고 끄는 사업이라면 Entity가 무엇일까요?
// 실제로 LED가 가지고 있는 상태값을 보고 꺼졌는지 켜졌는지 판단할 수 있습니다.
#ifndef __LED_H__ // 두번 참조하는 것을 방지, build하는 속도를 높임
#define __LED_H__

#include <stdbool.h>

// typedef는 사실상 #define과 거의 유사함
// 차이는 #define으로 type을 만들지는 못함
// 그러나 typedef는 특정 타입을 만드는 작업을 수행함
// 고로 typedef struct _led led는 아래를 의미함
// struct _led 로 적어야 하는 문법을 led로 퉁치겠습니다.
typedef struct _led led;

// 구조체를 작성하는 경우엔 아래의 방식으로 작성합니다.
// 1. struct (새로 커스텀하여 만들 이름)
// 2. 중괄호 열고 닫은 이후 마지막에 ';' 추가
// 3. 커스텀한 내용이 어떤 정보들을 담게 할 것인지 데이터 배치
struct _led
{
    bool status;
}; // {}; = 구조체 문법임

extern int led_array_count;

// ** 커스텀 데이터 타입을 만들 수 있다는 것 = 구조체 사용 목적의 핵심 **
// ex) 계정
// char *name[10];
// int age;
// char *address[10];
// 위 모든 것을 퉁칠 수 있는 방법
// account *account_array 와 같은 타입을 만들어 버리는 것

// 참고: JAVA에는 class 안에 method 가 있어야 함

led *init_led_object(int count);
void set_led_status(led *array, int led_index, bool on_off);
void print_led_array_status(led *array);

#endif