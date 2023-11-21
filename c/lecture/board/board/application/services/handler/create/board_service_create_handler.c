#include "board_service_create_handler.h"

#include <stdio.h>

#include "../../../../adapter/output/file/board_file_adapter.h"
#include "../../../../adapter/output/file/handler/save/board_file_adapter_save_handler.h"
#include "../../../../adapter/output/file/board_file_adapter_table.h"

#include "../../../../domain/model/board_model.h"
#include "../../../../domain/model/board_model_info.h"

#include "../../../../application/services/request/board_service_create_request.h"

void board_service_create(void *request)
{
    board_model *board;
    board_service_create_request *create_request = request;

    printf("board service: 게시물을 생성합니다!\n");

    board = create_board_model_with_parameter(
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

    board_file_adapter_table[BOARD_FILE_ADAPTER_SAVE]();
}
