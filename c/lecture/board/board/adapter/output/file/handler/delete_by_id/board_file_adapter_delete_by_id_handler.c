#include "board_file_adapter_delete_by_id_handler.h"

#include <stdio.h>
#include <fcntl.h>

#include "../../../../../../file/file.h"
#include "../../../../../../file/raw_io/file_io.h"
#include "../../../../../../in_memory/board/in_memory_board_manager.h"

#define GLOBAL_FILE_FULL_PATH       "../database/board_info.txt"

bool delete_file_info_with_id(unsigned int board_id)
{
    int find_enter_line;
    int file_length;
    int target_index = 0;
    int buffer_end;

    char read_buffer[BUDDY_PAGE_SIZE] = { 0 };
    char data_to_write[BUDDY_PAGE_SIZE] = { 0 };
    char backup_buffer[BUDDY_PAGE_SIZE] = { 0 };
    char post_process_buffer[BUDDY_PAGE_SIZE] = { 0 };
    int backup_buffer_length;

    int file_descriptor;

    printf("delete_file_info_with_id() board_id: %u\n", board_id);

    file_descriptor = file_open(GLOBAL_FILE_FULL_PATH, O_RDWR);
    file_length = file_total_length(file_descriptor);
    reset_file_pointer(file_descriptor);
    printf("file_length: %d\n", file_length);

    read_from_file(file_descriptor, read_buffer, BUDDY_PAGE_SIZE);
    buffer_end = strlen(read_buffer);
    printf("buffer_end = %d\n", buffer_end);

    if (buffer_end < 0)
    {
        printf("파일 내용 읽기 실패!\n");
        return false;
    }

    target_index = find_unique_id(board_id, file_length, read_buffer);

    find_enter_line = find_enter_line_from_target_index(read_buffer, target_index);
    if (find_enter_line == -1)
    {
        printf("find enter line error!\n");
        return false;
    }

    strncpy(backup_buffer, &read_buffer[find_enter_line + 1], file_length - find_enter_line);
    printf("backup_buffer: %s\n", backup_buffer);

    move_file_pointer(file_descriptor, target_index);
    printf("update move pointer\n");

    backup_buffer_length = strlen(backup_buffer);
    backup_buffer[backup_buffer_length] = '\0';

    write_to_file(file_descriptor, backup_buffer);
    truncate(GLOBAL_FILE_FULL_PATH, file_length - (find_enter_line - target_index + 1));
    //write(file_descriptor, post_process_buffer, find_enter_line - target_index + 1);

    return true;
}

void *delete_by_id_to_file(void *board_id)
{
    unsigned int id = board_id;
    void *result;

    printf("Board File Adapter: 특정 게시물 삭제\n");

    result = delete_file_info_with_id(board_id);

    return result;
}