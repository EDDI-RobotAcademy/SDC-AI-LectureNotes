#include <gtest/gtest.h>

#include "../../../../board/adapter/input/board_api.h"
#include "../../../../board/adapter/input/board_api_table.h"

#include "../../../../board/adapter/input/request_form/board_api_create_request_form.h"

#include "../../../../file/raw_io/file_io.h"
#include "../../../../board/domain/model/board_model.h"
#include "../../../../board/domain/model/board_model_id.h"
#include "../../../../board/domain/model/board_model_info.h"

#include "../../../../board/adapter/output/file/repository/in_memory_board_manager.h"
#include "../../../../board/adapter/output/file/handler/save/board_file_adapter_save_handler.h"

#include <string.h>
#include <fcntl.h>

// --gtest_filter=board_adapter_input_modify.*
TEST(board_adapter_input_modify, 게시물_수정하기)
{
    int i;
    int tmp_file;
    char origin_buffer[] = "0\034ㅅㄷㄴㅅ\034test\034test\034\n1\034test\034test\034test\034\n2\034go\034go\034go\034\n3\034\062\034\063\034\064\034\n";
    int origin_buffer_length;

    int read_buffer_length;
    int target_index = 0;
    char read_buffer[4096] = { 0 };
    char data_to_write[4096] = { 0 };

    unsigned int board_id = 2;
    char title[32] = "제목이 길어\0";
    char writer[32] = "go\0";
    char content[32] = "가즈아! 어디로 ?\0";

    int find_enter_line;
    char backup_buffer[4096] = { 0 };

    board_model *board;

    int file_descriptor;
    int file_length;

    tmp_file = file_open("just_for_test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    origin_buffer_length = strlen(origin_buffer);
    write(tmp_file, origin_buffer, origin_buffer_length);
    file_close(tmp_file);

    file_descriptor = file_open("just_for_test.txt", O_RDWR);
    file_length = file_total_length(file_descriptor);
    reset_file_pointer(file_descriptor);

    init_in_memory_board_manager();
    read_file_to_set_board_manager();

    board = init_board_model_with_parameter(
        init_board_model_id_with_parameter(board_id),
        init_board_model_info_with_parameter(
            init_board_model_title_with_parameter(title),
            init_board_model_writer_with_parameter(writer),
            init_board_model_content_with_parameter(content)
        )
    );
    
    // 생성(create)
    if (board->board_model_id == NULL)
    {
        int file_end;
        unsigned int unique_id = 0;

        printf("create start\n");
        read_from_file(file_descriptor, read_buffer, 4096);
        file_end = strlen(read_buffer);
        printf("read_buffer_length = %d\n", file_end);
        printf("read_buffer: %s\n", read_buffer);

        if (file_end > 0)
        {
            unique_id = find_unique_id_in_reverse_order(read_buffer);
            unique_id++;
        }

        convert_board_model(board, data_to_write, unique_id);
        printf("create convert\n");

        move_file_pointer(file_descriptor, file_end);
        printf("create move pointer\n");

        //printf("data_to_write: %s\n", data_to_write);
        write_to_file(file_descriptor, data_to_write);
        printf("create finish to write file\n");

        set_board_model_id(
            board,
            init_board_model_id_with_parameter(unique_id)
        );

        global_in_memory_board_manager.alloc_count++;
    }
    else if (board->board_model_id != NULL)
    {
        printf("update start\n");
        read_from_file(file_descriptor, read_buffer, 4096);
        printf("read_buffer: %s\n", read_buffer);

        // update 대응
        target_index = find_unique_id(
            get_board_model_id(board->board_model_id),
            file_length,
            read_buffer);

        printf("&read_buffer[target_index] = %s\n", &read_buffer[target_index]);

        find_enter_line = find_enter_line_from_target_index(read_buffer, target_index);
        if (find_enter_line == -1)
        {
            printf("find enter line error!\n");
            return;
        }
        printf("&read_buffer[find_enter_line + 1]: %s\n", &read_buffer[find_enter_line + 1]);

        convert_board_model(board, data_to_write);
        printf("update convert\n");
        // data_to_write: 2제목이 엄청 길어ify.*go`\가즈아! 어디로 ?
        // 변경 이전에 잘라 낼 부분을 파악해서 백업해두고 수정 파트 붙이고
        // 그 뒤에 백업 부분을 다시 합쳐서 복원하는 방식을 취해야함
        printf("data_to_write: \n");
        printf("%s\n", data_to_write);
        for (i = 0; data_to_write[i] != '\0'; i++)
        {
            printf("%5d", data_to_write[i]);
        }
        printf("\n");

        move_file_pointer(file_descriptor, target_index);
        printf("update move pointer\n");

        strncpy(backup_buffer, &read_buffer[find_enter_line + 1], file_length - find_enter_line);
        printf("backup_buffer: %s\n", backup_buffer);

        write_to_file(file_descriptor, data_to_write);
        printf("apply modification to write file\n");

        write_to_file(file_descriptor, backup_buffer);
        printf("update finish\n");
    }

    file_close(file_descriptor);
}