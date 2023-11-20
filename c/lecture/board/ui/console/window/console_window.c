#include "console_window.h"

#include <stdbool.h>
#include <stdio.h>

#include "../../../board/adapter/input/board_api.h"
#include "../../../board/adapter/input/handler/board_api_handler.h"
#include "../../../board/adapter/input/board_api_table.h"

void start_console_ui_window(void)
{
    bool playerEnterQuit = false;

    while (!playerEnterQuit)
    {
        board_api_table[BOARD_API_LIST]();
        break;
    }
}