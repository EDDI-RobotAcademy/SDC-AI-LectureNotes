#include "ui_service_modify_handler.h"

#include <stdlib.h>

#include "../../../../../board/adapter/output/file/board_file_adapter.h"
#include "../../../../../board/adapter/output/file/board_file_adapter_table.h"

#include "../../../../../board/application/services/response/board_service_create_response.h"
#include "../../../../../board/adapter/output/file/repository/in_memory_board.h"

#include "../../../../../board/domain/model/board_model.h"

board_service_create_response *get_exist_board_info(unsigned int id)
{
    in_memory_board *in_memory_board_object;
    board_service_create_response *response;

    in_memory_board_object = board_file_adapter_table[BOARD_FILE_ADAPTER_FIND_BY_ID](id);

    response = init_board_service_create_response(
        get_in_memory_board_id(in_memory_board_object),
        get_in_memory_board_title(in_memory_board_object),
        get_in_memory_board_writer(in_memory_board_object),
        get_in_memory_board_content(in_memory_board_object)
    );

    return response;
}

void print_exist_board_info(board_service_create_response *response)
{
    print_board_service_response(response);
}

void *ui_service_modify(void *nothing)
{
    board_service_create_response *response;
    board_model *board_model_object;

    char title[32] = { 0 };
    char content[128] = { 0 };

    char board_id[32] = { 0 };
    char *writer;
    unsigned int id;

    get_user_keyboard_input_with_message("수정하고 싶은 게시물 번호를 입력하세요: ", board_id);
    id = atoi(board_id);

    response = get_exist_board_info(id);
    print_exist_board_info(response);
    writer = get_board_service_create_response_writer(response);

    get_user_keyboard_input_with_message("제목을 입력하세요: ", title);
    get_user_keyboard_input_with_message("내용을 입력하세요: ", content);

    board_model_object = init_board_model_with_parameter(
        init_board_model_id_with_parameter(id),
        init_board_model_info_with_parameter(
            init_board_model_title_with_parameter(title),
            init_board_model_writer_with_parameter(writer),
            init_board_model_content_with_parameter(content)
        )
    );

    return board_model_object;
}