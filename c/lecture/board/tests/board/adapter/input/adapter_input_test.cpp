#include <gtest/gtest.h>

#include "../../../../board/adapter/input/board_api.h"
#include "../../../../board/adapter/input/board_api_table.h"

#include "../../../../board/adapter/input/request_form/board_api_create_request_form.h"

#include "../../../../board/adapter/output/file/repository/in_memory_board_manager.h"

TEST(board_adapter_input, 게시판에_게시물_작성하기)
{
    char title[] = "안녕";
    char writer[] = "가즈아";
    char content[] = "어디로 갈까 ?";

    board_api_create_request_form *request_form;
    int user_choice_command_number = BOARD_API_REGISTER;

    init_in_memory_board_manager();

    request_form = init_board_api_create_request_form(title, writer, content);
    board_api_table[user_choice_command_number](request_form);

    clear_board_api_create_request_form(request_form);
}

