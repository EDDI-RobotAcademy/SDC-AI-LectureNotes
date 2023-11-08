#include <stdio.h>
#include "led/entity/led.h"
#include "account/entity/account_manager.h"


int main (void)
{
   int i;
   //led 갯수에 대한 배열 설정으로 led_array 배열을 만든 것입니다.
   led *led_array;
   const int led_array_count = 7;
    printf("First C Programming on Linux!\n");

    led_array = init_led_object(led_array_count);

    for (i = 0; i < led_array_count; i++)
    {
        set_led_status(led_array, i, true);
    }

    print_led_array_status(led_array);

    printf("account, account_manager test!\n");

    init_account_manager_object();
    register_new_account("hi");
    register_new_account("Hello");
    register_new_account("gd");
    print_account_manager();

    return 0;
}