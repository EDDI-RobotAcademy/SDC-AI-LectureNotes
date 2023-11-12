#include <stdlib.h>
#include <stdio.h>

#include "led.h"

int led_array_count;

led *init_led_object(int count)
{
    // led 타입의 메모리 공간을 저장하는 포인터
    led *tmp_led_array = (led *)malloc(sizeof(led) * count);
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