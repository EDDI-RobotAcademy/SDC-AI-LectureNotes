#include "board_api_table.h"
#include "handler/board_api_handler.h"

#include <stdio.h>

void board_api_not_implemented (void)
{
    printf("Board API: 아직 구현되지 않은 기능입니다!\n");
}

const board_api_call_ptr_t board_api_table[BOARD_API_BUFFER_COUNT] =
{
    [0 ... BOARD_API_BUFFER] = board_api_not_implemented,
    #include "board_api_table_mapper.h"
};