#include "console_window.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../../board/adapter/input/board_api.h"
#include "../../../board/adapter/input/board_api_table.h"

#include "../user_keyboard/user_keyboard_input.h"

void start_console_ui_window(void)
{
    int user_choice_command_number;
    bool player_enter_quit = false;

    board_api_table[BOARD_API_LIST]();

    while (!player_enter_quit)
    {
        user_choice_command_number = user_choice_number_for_board_command();
        board_api_table[BOARD_API_REGISTER]();
        board_api_table[BOARD_API_READ]();
        board_api_table[BOARD_API_MODIFY]();
        board_api_table[BOARD_API_REMOVE]();
        break;
    }
}

int user_choice_number_for_board_command(void)
{
    char keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char command_message[] = "0번. 게시물 작성\n"
                     "1번. 게시물 읽기\n"
                     "2번. 종료\n";

    get_user_keyboard_input_with_message(command_message, keyboard_input);

    return atoi(keyboard_input);
}