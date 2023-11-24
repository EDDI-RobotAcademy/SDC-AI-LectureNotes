#include <gtest/gtest.h>

#include "../../../../board/adapter/input/board_api.h"
#include "../../../../board/adapter/input/board_api_table.h"

#include "../../../../board/adapter/input/request_form/board_api_create_request_form.h"

#include "../../../../board/adapter/output/file/repository/in_memory_board_manager.h"

#include "../../../../board/application/services/response/board_service_create_response.h"

TEST(board_adapter_input, 게시판에_게시물_작성하기)
{
    int i;
    char title[] = "안녕";
    char writer[] = "가즈아";
    char content[] = "어디로 갈까 ?";

    in_memory_board *memory_board;
    board_api_create_request_form *request_form;
    // 사실 이건 board_api_create_response_form으로 만들어야함
    board_service_create_response *response;
    int user_choice_command_number = BOARD_API_REGISTER;

    init_in_memory_board_manager();
    read_file_to_set_board_manager();

    request_form = init_board_api_create_request_form(title, writer, content);
    response = (board_service_create_response *)board_api_table[user_choice_command_number](request_form);

    clear_board_api_create_request_form(request_form);

    clear_board_service_create_response(response);

    // memory_board = global_in_memory_board_manager.in_memory_board_array;

    // for (i = 0; i < global_in_memory_board_manager.alloc_count; i++)
    // {
    //     if (memory_board[i])
    //     clear_in_memory_board_object(
    //         &global_in_memory_board_manager.in_memory_board_array[i]
    //     );
    // }
}
