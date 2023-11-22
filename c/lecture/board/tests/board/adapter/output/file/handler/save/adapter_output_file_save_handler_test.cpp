#include <gtest/gtest.h>

#include <string.h>

#include "../../../../../../../board/adapter/output/file/repository/in_memory_board_manager.h"

TEST(board_file_adapter_save_handler, 파일_버퍼를_객체로_변환하기)
{
    int i;
    char buffer[4096] = "0\034안녕\034가즈아\034어디로 갈까 ?\034\n1\034안녕\034가즈아\034어디로 갈까 ?\034\n2\034안녕\034가즈아\034어디로 갈까 ?\034\n";
    int buffer_length = strlen(buffer);

    init_in_memory_board_manager();
    read_file_to_set_board_manager();

    convert_file_to_in_memory_board(buffer, buffer_length);



    // for (i = 0; i < global_in_memory_board_manager.alloc_count; i++)
    // {
    //     clear_in_memory_board_object(
    //         &global_in_memory_board_manager.in_memory_board_array[i]
    //     );
    // }
}