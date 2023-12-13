#include "user_keyboard_input.h"

#include <unistd.h>



void get_user_keyboard_input(char *user_keyboard_input)
{
    read(0, user_keyboard_input, MAX_USER_KEYBOARD_INPUT);
}
