#include "board_file_adapter_save_handler.h"

#include <stdio.h>

#include "../../../../../domain/model/board_model.h"

#include "../../../../../../file/file.h"
#include "../../../../../../file/raw_io/file_io.h"
//#include "../../../../../../in_memory/board/in_memory_board_manager.h"

#include "../../repository/in_memory_board_manager.h"

#include <fcntl.h>
#include <stdbool.h>

#include <sys/types.h>
#include <dirent.h>
#include <linux/limits.h>
#include <unistd.h>

#include <string.h>

#define GLOBAL_DIR_LOCATION         "../database"
#define GLOBAL_FILE_INFO            "board_info.txt"
#define GLOBAL_FILE_FULL_PATH       "../database/board_info.txt"

int find_unique_id(unsigned int unique_id, int file_length, char *buffer)
{
    int i;
    char id_string[32] = { 0 };
    int id_string_length;

    sprintf(id_string, "%u", unique_id);
    id_string_length = strlen(id_string);

    for (i = 0; i < file_length; i++)
    {
        if (!strncmp(&buffer[i], id_string, id_string_length))
        {
            return i;
        }
    }
}

void convert_board_model(board_model *board, char *data_to_write)
{
    // ascii code 0x1c = File Seperator
    sprintf(data_to_write, "%u%c%s%c%s%c%s%c\n",
        get_board_model_id(board->board_model_id),
        0x1c,
        get_board_model_title(board->board_model_info->board_model_title),
        0x1c,
        get_board_model_writer(board->board_model_info->board_model_writer),
        0x1c,
        get_board_model_content(board->board_model_info->board_model_content),
        0x1c);
}

void write_board_info_to_file(int file_descriptor, board_model *board)
{
    int file_length;
    int target_index = 0;
    char read_buffer[BUDDY_PAGE_SIZE] = { 0 };
    char data_to_write[BUDDY_PAGE_SIZE] = { 0 };

    file_length = file_total_length(file_descriptor);
    reset_file_pointer(file_descriptor);

    printf("file length = %d\n", file_length);

    printf("file_descriptor = %d\n", file_descriptor);
    
    if (file_length > 0)
    {
        read_from_file(file_descriptor, read_buffer, BUDDY_PAGE_SIZE);

        // update 대응
        target_index = find_unique_id(
            get_board_model_id(board->board_model_id),
            file_length,
            read_buffer);
    }

    convert_board_model(board, data_to_write);
    move_file_pointer(file_descriptor, target_index);

    write_to_file(file_descriptor, data_to_write);
}

// update인지 register 인지에 대한 일관성
in_memory_board *save_to_file(void *domain_board_model)
{
    board_model *board = domain_board_model;
    bool existing_info;
    int file_descriptor;
    int board_id;
    // char pwd_path[PATH_MAX];
    // int current_path_length;

    printf("Board File Adapter: 게시물 저장\n");
    printf("board unique id: %d\n", board->board_model_id->board_id);
    // printf("현재 디렉토리: %s\n", getcwd(pwd_path, PATH_MAX));

    // current_path_length = strlen(pwd_path);
    // sprintf(&pwd_path[current_path_length], "/%s", GLOBAL_FILE_FULL_PATH);
    // printf("result: %s\n", pwd_path);

    file_descriptor = file_open(GLOBAL_FILE_FULL_PATH, O_RDWR);
    //file_descriptor = open(pwd_path, O_RDWR);

    if (file_descriptor == -1)
    {
        printf("re open file\n");
        file_descriptor = file_open(GLOBAL_FILE_FULL_PATH, O_CREAT | O_RDWR, 0644);
    }

    write_board_info_to_file(file_descriptor, board);

    file_close(file_descriptor);

    printf("after close()\n");
    alloc_in_memory_board_manager(board);
    
    printf("after alloc_in_memory_board_manager()\n");
    board_id = get_board_model_id(board->board_model_id);
    return &global_in_memory_board_manager.in_memory_board_array[board_id];
}
