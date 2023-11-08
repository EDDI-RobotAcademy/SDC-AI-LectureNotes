#include "led.h"
#include <stdlib.h>
#include <stdio.h>
int led_array_count;


led *init_led_object(int count)
{
    //함수 메모리 공간을 저장하는 포인터를 임시적으로 저장 
    led *tmp_led_array = (led *)malloc(sizeof(led)* count);
    // led_array_count는 init_led_object 함수에 들어가는 인수 값 
    led_array_count = count;
    // 임시 포인터 값 반환 
    return tmp_led_array;
}


void set_led_status(led *array, int led_index, bool on_off)
{   
    // 포인터 인수 array[배열 값]의 boolean 값 -> true or false 
    array[led_index].status = on_off;
}

// 포인터 값 반환 
void print_led_array_status(led *array)
{   // 변수 생성 (현재 led의 배열 번호)
    int current_led_index;

    printf("led 배열 출력: \n");

    // 현재 배열 값은 0부터 시작해서 정해진 수의 횟수만큼 on인지 off인지 반환 
    for (int current_led_index = 0; current_led_index < led_array_count; current_led_index++)
    {   
        //값이 true면 'on', false면 'off'
        printf("%4s", array[current_led_index].status ? "on":"off");
    }
    printf("\n");
}