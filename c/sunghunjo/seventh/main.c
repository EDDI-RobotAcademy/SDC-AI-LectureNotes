#include <stdio.h>

#include "led/entity/led.h"
#include "account/entity/account_manager.h"

int main(void)
{
    int i;
    led *led_array;
    // 몇개의 led가 될것인지 정하는 변수
    const int led_array_count = 7;
    char name[32] = "hi";
    printf("First C Programming on Linux!\n");
    
    // led_array에 7개의 led형태의 공간을 초기화후 지정해주는 식
    led_array = init_led_objeckt(led_array_count);

    // led_array의 총 7개의 statuse를 on(true)로 지정해주는 for문
    for(i = 0; i < led_array_count; i ++)
    {
        set_led_statuse(led_array,i,true);
    }

    // led_array를 print 한다.
    print_led_array_status(led_array);

    printf("account, account_manager test!\n");

    // account형태의 공간을 32개 배정
    init_account_manager_object();
    // account_manager.account_array[1].name에 char*공간을 name의 길이 +1만큼 만들고
    // name를 account_manager.account_array[1].name에 복사해서 넣는다.
    register_new_account(name);
    // account_manager.account_array[2].name에 char*공간을 "test"의 길이 +1만큼 만들고
    // "test"를 account_manager.account_array[2].name에 복사해서 넣는다.
    register_new_account("test");
    register_new_account("go");
    // 총 3개의 account_manager.account_array가 배정되었으므로 
    // 3개의 account_array의 name를 print한다.
    print_account_manager();

    return 0;
}