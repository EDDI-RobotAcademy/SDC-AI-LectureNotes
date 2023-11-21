#include "board_api_table.h"
#include "handler/list/board_api_list_handler.h"
#include "handler/register/board_api_register_handler.h"
#include "handler/read/board_api_read_handler.h"
#include "handler/modify/board_api_modify_handler.h"
#include "handler/remove/board_api_remove_handler.h"

#include <stdio.h>

void board_api_not_implemented (void *nothing)
{
    printf("Board API: 아직 구현되지 않은 기능입니다!\n");
}

const board_api_call_ptr_t board_api_table[BOARD_API_BUFFER_COUNT] =
{
    [0 ... BOARD_API_BUFFER] = board_api_not_implemented,
    #include "board_api_table_mapper.h"
};