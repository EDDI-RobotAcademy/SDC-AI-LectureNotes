#include "board_api_list_handler.h"

#include "../../../../application/services/board_service.h"
#include "../../../../application/services/handler/get_list/board_service_get_list_handler.h"
#include "../../../../application/services/board_service_table.h"

#include "../../../../application/services/response/list/board_service_list_response.h"

#include <stdio.h>

void *board_api_list(void *request_form)
{
    board_service_list_response **list_response;

    printf("board api: 게시판 리스트를 조회합니다!\n");

    list_response = board_service_table[BOARD_SERVICE_GET_LIST](NULL);

    print_board_service_list_response(list_response);

    return list_response;
}
