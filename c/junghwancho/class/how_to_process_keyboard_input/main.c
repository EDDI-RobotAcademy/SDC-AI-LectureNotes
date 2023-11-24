#include <stdio.h>
#include "ui/console/user_keyboard_input.h"

int main (void)
{
    char keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };

    get_user_keyboard_input(keyboard_input);

    printf("사용자 입력 데이터 %s\n", keyboard_input);

    return 0;
}