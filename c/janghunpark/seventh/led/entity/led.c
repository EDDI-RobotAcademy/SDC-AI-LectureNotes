#include <stdlib.h>
#include <stdio.h>

#include "led.h"

// led array에 메모리를 할당하는 역할
// 생성자 역할 init; struct를 객체화하는 역할
// c는 수동으로 해줘야 하며 보통 그럴 때 붙이는 접두어 = init(초기화하다)

int led_array_count;

// count 숫자만큼 led 객체 생성
led *init_led_object(int count)
{
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