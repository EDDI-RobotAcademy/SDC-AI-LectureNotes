#include <stdio.h>

#include "led/entity/led.h"
#include "account/entity/account_manager.h"

int main (void)
{
    int i;
    led *led_array;
    const int led_array_count = 7;
    char name[32] = "hi";
    printf("First C Programming on Linux!\n");

    led_array = init_led_object(led_array_count);
    
    for (i = 0; i < led_array_count; i++)
    {
        set_led_status(led_array, i, true);
    }

    print_led_array_status(led_array);

    printf("account, account_manager test!\n");

    init_account_manager_object();
    register_new_account(name);
    register_new_account("test");
    register_new_account("go");
    print_account_manager();

    return 0;
}