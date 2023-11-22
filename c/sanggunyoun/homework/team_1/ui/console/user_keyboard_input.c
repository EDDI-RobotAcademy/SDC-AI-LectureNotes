#include "user_keyboard_input.h"

#include <stdio.h>
// File Descriptor(파일 디스크립터)
// 0번 = 표준 입력
// 1번 = 표준 출력
// 2번 = 표준 에러

// Unix 핵심 철학: 모든 것은 파일이다.

#include <unistd.h>
#include <string.h>

#include <termios.h>

// 사용자 입력 받기
void get_user_keyboard_input(char *keyboard_input)
{
    read(0, keyboard_input, MAX_USER_KEYBOARD_INPUT);
}

// 메시지 출력 이후 사용자 입력 받기
void get_user_keyboard_input_with_message(char *output_message, char *keyboard_input)
{
    write(1, output_message, strlen(output_message));
    //read(0, keyboard_input, MAX_USER_KEYBOARD_INPUT);
    get_user_keyboard_input(keyboard_input);
}

// 메시지 출력 이후 사용자 입력 숨겨서 받기
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
}