#include "console_window.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../../board/adapter/input/board_api.h"
#include "../../../board/adapter/input/board_api_table.h"

#include "../user_keyboard/user_keyboard_input.h"

#include "../../../board/adapter/input/request_form/board_api_create_request_form.h"

#include "../service/ui_service.h"
#include "../service/handler/list/ui_service_list_handler.h"
#include "../service/handler/create/ui_service_create_handler.h"
#include "../service/handler/read/ui_service_read_handler.h"
#include "../service/handler/modify/ui_service_modify_handler.h"
#include "../service/ui_service_table.h"

void start_console_ui_window(void)
{
    //board_api_create_request_form *create_request_form;
    void *request_form;
    void *response_form;

    int user_choice_command_number;
    bool player_enter_quit = false;

    printf("start ui loop\n");
    board_api_table[BOARD_API_LIST](NULL);

    while (!player_enter_quit)
    {
        user_choice_command_number = user_choice_number_for_board_command();
        request_form = ui_service_table[user_choice_command_number](NULL);
        board_api_table[user_choice_command_number](request_form);
    }
}

int user_choice_number_for_board_command(void)
{
    char keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char command_message[] = "0번. 게시물 전체 조회\n"
                     "1번. 게시물 작성\n"
                     "2번. 게시물 읽기\n"
                     "3번. 게시물 수정\n"
                     "4번. 게시물 삭제\n"
                     "5번. 종료\n";

    get_user_keyboard_input_with_message(command_message, keyboard_input);

    return atoi(keyboard_input);
}