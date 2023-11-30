#include "user_keyboard_input.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <termios.h>

#include "../../../utility/trim.h"

void get_user_keyboard_input(char *keyboard_input)
{
    read(0, keyboard_input, MAX_USER_KEYBOARD_INPUT);

    trim_whitespaces(&keyboard_input);
    trim_wide_whitespaces(&keyboard_input);
}

void get_user_keyboard_input_with_message(char *output_message, char *keyboard_input)
{
    write(1, output_message, strlen(output_message));
    get_user_keyboard_input(keyboard_input);

    trim_whitespaces(&keyboard_input);
    trim_wide_whitespaces(&keyboard_input);
}

void get_user_keyboard_hidden_input_with_message(
    char *output_message, char *keyboard_hidden_input)
{
    struct termios old_terminal, new_terminal;
    int length = 0;
    char character;

    write(1, output_message, strlen(output_message));

    tcgetattr(STDIN_FILENO, &old_terminal);
    new_terminal = old_terminal;

    new_terminal.c_lflag &= ~(ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &new_terminal);

    read(0, keyboard_hidden_input, MAX_USER_KEYBOARD_INPUT);
    length = strlen(keyboard_hidden_input);
    keyboard_hidden_input[length] = '\0';

    tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal);
    printf("\n");

    trim_whitespaces(&keyboard_hidden_input);
    trim_wide_whitespaces(&keyboard_hidden_input);
}