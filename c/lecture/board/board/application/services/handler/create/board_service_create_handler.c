#include "board_service_create_handler.h"

#include <stdio.h>

#include "../../../../adapter/output/file/board_file_adapter.h"
#include "../../../../adapter/output/file/handler/save/board_file_adapter_save_handler.h"
#include "../../../../adapter/output/file/board_file_adapter_table.h"

#include "../../../../domain/model/board_model.h"
#include "../../../../domain/model/board_model_info.h"

#include "../../../../application/services/request/board_service_create_request.h"
#include "../../../../adapter/output/file/repository/in_memory_board.h"

#include "../../../../application/services/response/board_service_create_response.h"

void *board_service_create(void *request)
{
    board_model *board;
    board_service_create_request *create_request = request;

    in_memory_board *created_board;
    board_service_create_response *create_response;

    printf("board service: 게시물을 생성합니다!\n");

    board = init_board_model_with_parameter(
        init_board_model_info_with_parameter(
            init_board_model_title_with_parameter(
                get_board_service_create_request_title(create_request)
            ),
            init_board_model_writer_with_parameter(
                get_board_service_create_request_writer(create_request)
            ),
            init_board_model_content_with_parameter(
                get_board_service_create_request_content(create_request)
            )
        )
    );

    created_board = board_file_adapter_table[BOARD_FILE_ADAPTER_SAVE](board);
    clear_board_service_create_request(create_request);

    printf("ready to return response\n");
    printf("created_board object = 0x%x\n", created_board);
    printf("board id = %u\n", get_in_memory_board_id(created_board));
    printf("board title = %s\n", get_in_memory_board_title(created_board));
    printf("board writer = %s\n", get_in_memory_board_writer(created_board));
    printf("board content = %s\n", get_in_memory_board_content(created_board));

    create_response = init_board_service_create_response(
        get_in_memory_board_id(created_board),
        get_in_memory_board_title(created_board),
        get_in_memory_board_writer(created_board),
        get_in_memory_board_content(created_board)
    );

    printf("finish to make response\n");

    return create_response;
}
