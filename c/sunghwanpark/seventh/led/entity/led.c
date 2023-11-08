#include "led.h"
#include <stdlib.h>
#include <stdio.h>
int led_array_count;

// 
led *init_led_object(int count)
{
    led *tmp_led_array = (led *)malloc(sizeof(led)* count);
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

    for (int current_led_index=0;current_led_index<led_array_count;current_led_index++)
    {
        printf("%4s", array[current_led_index].status ? "on":"off");
    }
    printf("\n");
}