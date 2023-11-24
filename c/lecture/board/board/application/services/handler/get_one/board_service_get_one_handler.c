#include "board_service_get_one_handler.h"

#include <stdio.h>

#include "../../../../adapter/output/file/board_file_adapter.h"
//#include "../../../../adapter/output/file/handler/find_all/board_file_adapter_find_all_handler.h"
#include "../../../../adapter/output/file/board_file_adapter_table.h"

#include "../../../../application/services/response/board_service_create_response.h"
#include "../../../../adapter/output/file/repository/in_memory_board.h"

void *board_service_get_one(void *request)
{
    in_memory_board *in_memory_board_object;
    board_service_create_response *response;

    printf("board service: 게시물 정보를 획득합니다!\n");

    in_memory_board_object = board_file_adapter_table[BOARD_FILE_ADAPTER_FIND_BY_ID](request);

    response = init_board_service_create_response(
        get_in_memory_board_id(in_memory_board_object),
        get_in_memory_board_title(in_memory_board_object),
        get_in_memory_board_writer(in_memory_board_object),
        get_in_memory_board_content(in_memory_board_object)
    );

    return response;
}