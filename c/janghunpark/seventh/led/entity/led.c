#include <stdlib.h>
#include <stdio.h>

#include "led.h"

// led array에 메모리를 할당하는 역할
// 생성자 역할 init; struct를 객체화하는 역할
// c는 수동으로 해줘야 하며 보통 그럴 때 붙이는 접두어 = init(초기화하다)

// 구조체 내부에 들어가서 관리되고 있지 않다는 문제
// 고로 led_manager (객체 매니저)를 만들어서 관리할 필요가 있다.
// service와 repository는 왜 구분이 필요한가?

// extern에 입력한 변수는 이렇게 한 번 더 써줘야 함
int led_array_count;

// count 숫자만큼 led 객체 생성
led *init_led_object(int count)
{
    // led 타입의 메모리 공간을 저장하는 포인터
    // malloc은 heap에 메모리 할당
    // sizeof() = 만든 타입의 개별 사이즈를 저장
    // tmp_led_array는 main에서 led_array로 뽑아냄
    const led *tmp_led_array = (led*)malloc(sizeof(led) * count);
    led_array_count = count;
    return tmp_led_array;
}

void set_led_status(led *array, int led_index, bool on_off)
{
    array[led_index].status = on_off;
}

void print_led_array_status(led *array)
{
    int current_led_index;

    printf("led 배열 출력: \n");

    for (current_led_index = 0; current_led_index < led_array_count; current_led_index++)
    {
        printf("%4s", array[current_led_index].status ? "on" : "off");
    }
    printf("\n");
}