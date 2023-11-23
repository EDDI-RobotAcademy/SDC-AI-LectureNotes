#include "board_api_register_handler.h"

#include "../../../../application/services/board_service.h"
#include "../../../../application/services/handler/create/board_service_create_handler.h"
#include "../../../../application/services/board_service_table.h"

#include "../../../../application/services/request/board_service_create_request.h"
#include "../../../../application/services/response/board_service_create_response.h"

#include <stdio.h>

void *board_api_register(void *request_form)
{
    board_service_create_request *request;
    board_service_create_response *response;

    if (request_form == NULL)
    {
        printf("올바른 내용을 입력해주세요\n");
        return NULL;
    }

    printf("board api: 게시물을 작성합니다!\n");

    request = init_board_service_create_request(
        get_board_service_create_request_title(request_form),
        get_board_service_create_request_writer(request_form),
        get_board_service_create_request_content(request_form));

    response = board_service_table[BOARD_SERVICE_CREATE](request);
    printf("finish to create request\n");

    //clear_board_service_create_request(request);
    printf("clear request object\n");

    return response;
}