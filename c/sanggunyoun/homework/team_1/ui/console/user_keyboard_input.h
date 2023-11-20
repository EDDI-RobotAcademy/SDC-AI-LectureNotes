#ifndef __USER_KEYBOARD_INPUT_H__
#define __USER_KEYBOARD_INPUT_H__

#define MAX_USER_KEYBOARD_INPUT         32

void get_user_keyboard_input(char *keyboard_input);
void get_user_keyboard_input_with_message(char *output_message, char *keyboard_input);
void get_user_keyboard_hidden_input_with_message(
    char *output_message, char *keyboard_hidden_input);

#endif