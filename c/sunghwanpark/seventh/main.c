#include <stdio.h>
#include "led/entity/led.h"

int main (void)
{
    int i;
    led *led_array;
    const int led_array_count = 7;

    printf("First C Programming on Linux!\n");
       // led_array_count가 7로 고정값이기 때문에 size 7 동적할당 
    led_array = init_led_object(led_array_count);

    for (i=0;i<led_array_count;i++)
    {
        // boolean의 값은 true로 고정 
        set_led_status(led_array,i,true);
    }
    // boolean 값은 true로 고정시켰기 무조건 'on' 출력
    print_led_array_status(led_array);

    printf("account,account_manager test!\n");

    init_account_manager_object();
    register_new_account("test");
    print_account_manager();

    return 0;
}