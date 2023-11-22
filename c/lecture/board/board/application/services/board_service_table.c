#include "board_service.h"
#include "handler/get_list/board_service_get_list_handler.h"
#include "handler/create/board_service_create_handler.h"
#include "handler/get_one/board_service_get_one_handler.h"
#include "handler/modify/board_service_modify_handler.h"
#include "handler/remove/board_service_remove_handler.h"
#include "board_service_table.h"

#include <stdio.h>

void board_service_not_implemented (void *nothing)
{
    printf("Board Service: 아직 구현되지 않은 기능입니다!\n");
}

const board_service_call_ptr_t board_service_table[BOARD_SERVICE_BUFFER_COUNT] =
{
    [0 ... BOARD_SERVICE_BUFFER] = board_service_not_implemented,
    #include "board_service_table_mapper.h"
};