#include "board_api_read_handler.h"

#include "../../../../application/services/board_service.h"
#include "../../../../application/services/handler/create/board_service_create_handler.h"
#include "../../../../application/services/board_service_table.h"

#include "../../../../application/services/response/board_service_create_response.h"
#include "../../../output/file/repository/in_memory_board.h"

#include <stdio.h>

void *board_api_read(void *request_form)
{
    in_memory_board *read_board_object;
    board_service_create_response *response;

    printf("board api: 게시물을 읽습니다!\n");

    read_board_object = board_service_table[BOARD_SERVICE_GET_ONE](request_form);

    response = init_board_service_create_response(
        get_in_memory_board_id(read_board_object),
        get_in_memory_board_title(read_board_object),
        get_in_memory_board_writer(read_board_object),
        get_in_memory_board_content(read_board_object)
    );

    print_board_service_response(response);
}