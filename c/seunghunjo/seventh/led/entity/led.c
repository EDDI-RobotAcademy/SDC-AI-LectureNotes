#include <stdlib.h>
#include <stdio.h>

#include "led.h"

int led_array_count;

led *init_led_objeckt(int count)
{
    // led 타입의 메모리 공간을 저장하는 포인터
    led *tmp_led_array = (led*)malloc(sizeof(led) * count);
    // 몇개가 입력받은 건지 저장을해준다.
    led_array_count = count;
    return tmp_led_array;
}

void set_led_statuse(led *array,int led_index, bool on_off)
{
    // led형태의 array를 받아 array의 led_index번째 의 status가 on(true)인지 off(false)인지 정한다.
    array[led_index].status = on_off;
}

void print_led_array_status(led *array)
{
    int current_led_index;

    printf("led 배열 출력: \n");

    for( current_led_index = 0; current_led_index < led_array_count; current_led_index++)
    {
        // set_led_statuse에서 정한 on(ture) 과 off(fales)를 순차적으로 print해준다.
        printf("%4s", array[current_led_index].status ? "on" : "off");
    }
    
    printf("\n");
}