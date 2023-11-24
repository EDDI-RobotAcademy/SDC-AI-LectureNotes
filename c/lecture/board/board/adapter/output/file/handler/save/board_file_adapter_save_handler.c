#include "board_file_adapter_save_handler.h"

#include <stdio.h>

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

void convert_board_model(board_model *board, char *data_to_write, unsigned int unique_id)
{
    // ascii code 0x1c = File Seperator
    sprintf(data_to_write, "%u%c%s%c%s%c%s%c\n",
        unique_id,
        0x1c,
        get_board_model_title(board->board_model_info->board_model_title),
        0x1c,
        get_board_model_writer(board->board_model_info->board_model_writer),
        0x1c,
        get_board_model_content(board->board_model_info->board_model_content),
        0x1c);
}

int find_unique_id_in_reverse_order(char *read_buffer)
{
    int i;
    int count = 0;
    int start = 0, end;
    char found_unique_id[32] = { 0 };
    bool check_four_separator = false;
    char enter_character = '\n';
    char find_separator = 0x1c;
    int read_buffer_length = strlen(read_buffer);

    for (i = read_buffer_length - 1; i >= 0; i--)
    {
        if (!strncmp(&read_buffer[i], &find_separator, 1))
        {
            count++;
        }

        if (!check_four_separator && count == 4)
        {
            end = i - 1;
            printf("reverse found end: %d\n", end);
            check_four_separator = true;
        }

        if (check_four_separator && 
            !strncmp(&read_buffer[i], &enter_character, 1))
        {
            check_four_separator = false;
            start = i + 1;
            printf("reverse found start: %d\n", start);
        }
    }

    strncpy(found_unique_id, &read_buffer[start], end - start + 1);

    return atoi(found_unique_id);
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

    printf("board = 0x%x\n", board);
    printf("board->board_model_id = 0x%x\n", board->board_model_id);
    
    // 생성(create)
    if (board->board_model_id == NULL)
    {
        int file_end;
        unsigned int unique_id = 0;

        printf("create start\n");
        read_from_file(file_descriptor, read_buffer, BUDDY_PAGE_SIZE);
        file_end = strlen(read_buffer);
        printf("read_buffer_length = %d\n", file_end);

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
    }
    else if (get_board_model_id(board->board_model_id) != NULL)
    {
        printf("update start\n");
        read_from_file(file_descriptor, read_buffer, BUDDY_PAGE_SIZE);

        // update 대응
        target_index = find_unique_id(
            get_board_model_id(board->board_model_id),
            file_length,
            read_buffer);

        convert_board_model(board, data_to_write);
        printf("update convert\n");

        move_file_pointer(file_descriptor, target_index);
        printf("update move pointer\n");

        write_to_file(file_descriptor, data_to_write);
        printf("update finish to write file\n");
    }

    printf("after file work\n");

    //alloc_in_memory_board_manager(board);
    //printf("after alloc_in_memory_board_manager()\n");

    // convert_board_model(board, data_to_write);
    // move_file_pointer(file_descriptor, target_index);

    // write_to_file(file_descriptor, data_to_write);
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
    //printf("board unique id: %d\n", board->board_model_id->board_id);
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
    
    board_id = get_board_model_id(board->board_model_id);
    return &global_in_memory_board_manager.in_memory_board_array[board_id];
}
