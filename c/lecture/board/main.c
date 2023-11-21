#include <stdio.h>
#include <stdbool.h>

#include "ui/console/window/console_window.h"
#include "board/adapter/output/file/repository/in_memory_board_manager.h"

int main (void)
{
    printf("C Based DDD Practice: Board\n");
    init_in_memory_board_manager();

    start_console_ui_window();
    
    return 0;
}
