#include <stdio.h>
#include "led/entity/led.h"
#include "account/entity/account_manager.h"

int main (void)
{
    int i; // for 문 동작용 + led_array 배열에 상태를 저장하는 index
    led *led_array; // led type의 배열 포인터
    const int led_array_count = 7;
    printf("First C Programming on Linux!\n");
    
    led_array = init_led_object(led_array_count);

    for (i = 0; i < led_array_count; i++)
    {
        set_led_status(led_array, i, 1);
    }

    print_led_array_status(led_array);

    printf("account, account_manager test!\n");

    init_account_manager_object();
    register_new_account("hey");
    register_new_account("go");
    register_new_account("test");
    register_new_account("omg");
    print_account_manager();

    return 0;
}