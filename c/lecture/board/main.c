#include <stdio.h>
#include <stdbool.h>

#include "ui/console/window/console_window.h"
#include "board/adapter/output/file/repository/in_memory_board_manager.h"

int main (void)
{
    printf("C Based DDD Practice: Board\n");
    // In-Memory 레벨에서 게시물 관리자 객체 생성
    init_in_memory_board_manager();
    // 파일(DB)을 읽어서 게시물 관리자 객체에 정보를 설정함
    read_file_to_set_board_manager();

    // UI Engine 시작
    start_console_ui_window();
    
    return 0;
}
