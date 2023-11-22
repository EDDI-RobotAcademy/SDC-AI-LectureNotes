#include "in_memory_board_manager.h"

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

#include "../../../../../file/raw_io/file_io.h"
#include "in_memory_board.h"

in_memory_board_manager global_in_memory_board_manager;

#define DEFAULT_ALLOC_NUMBER            32

void init_in_memory_board_manager(void)
{
    global_in_memory_board_manager.alloc_count = DEFAULT_ALLOC_NUMBER;
    global_in_memory_board_manager.in_memory_board_array = 
        (in_memory_board *)malloc(sizeof(in_memory_board) * DEFAULT_ALLOC_NUMBER);
}

void alloc_in_memory_board_manager(board_model *board)
{
    int unique_id = get_board_model_id(board->board_model_id);

    alloc_memory_board_object(
        &global_in_memory_board_manager.in_memory_board_array[unique_id],
        unique_id,
        get_board_model_title(board->board_model_info->board_model_title),
        get_board_model_writer(board->board_model_info->board_model_writer),
        get_board_model_content(board->board_model_info->board_model_content)
    );
}

void convert_file_to_in_memory_board(char *read_buffer, int read_size)
{
    int i;
    int count = 0;
    int start = 0, end = -1;
    char file_separator = 0x1c;

    unsigned int unique_board_id;
    char title[32] = { 0 };
    char writer[32] = { 0 };
    char content[32] = { 0 };

    printf("read_size = %d\n", read_size);

    // TODO: Need to update
    for (i = 0; i < read_size; i++)
    {
        if ((count % 4 == 0) && !strncmp(&read_buffer[i], &file_separator, 1))
        {
            char unique_id[32] = { 0 };
            start = end + 1;
            end = i;
            printf("unique id start = %d, end = %d\n", start, end);

            memset(unique_id, 0x00, 32);
            strncpy(unique_id, &read_buffer[start], end);
            unique_board_id = atoi(unique_id);
            printf("unique_board_id = %u\n", unique_board_id);
            
            //global_in_memory_board_manager.in_memory_board_array[count / 4].id = atoi(tmp_string);
            count++;

            start = i + 1;
            i++;
        }

        if ((count % 4 == 1) && !strncmp(&read_buffer[i], &file_separator, 1))
        {
            end = i - 1;
            printf("unique id start = %d, end = %d\n", start, end - start + 1);

            memset(title, 0x00, 32);
            strncpy(title, &read_buffer[start], end);
            printf("title = %s\n", title);
            
            //global_in_memory_board_manager.in_memory_board_array[count / 4].title = title;
            count++;

            start = i + 1;
            i++;
        }

        if ((count % 4 == 2) && !strncmp(&read_buffer[i], &file_separator, 1))
        {
            end = i - 1;
            printf("unique id start = %d, end = %d\n", start, end);

            memset(writer, 0x00, 32);
            strncpy(writer, &read_buffer[start], end - start + 1);
            printf("writer = %s\n", writer);
            
            //global_in_memory_board_manager.in_memory_board_array[count / 4].writer = writer;
            count++;

            start = i + 1;
            i++;
        }

        if ((count % 4 == 3) && !strncmp(&read_buffer[i], &file_separator, 1))
        {
            end = i - 1;
            printf("unique id start = %d, end = %d\n", start, end);

            memset(content, 0x00, 32);
            strncpy(content, &read_buffer[start], end - start + 1);
            printf("content = %s\n", content);
            
            //global_in_memory_board_manager.in_memory_board_array[count / 4].content = content;
            count++;

            start = i + 1;
            i++;

            alloc_memory_board_object(
                &global_in_memory_board_manager.in_memory_board_array[count / 4],
                unique_board_id, 
                title, 
                writer, 
                content);

            end += 2;
        }
    }
}

void read_file_to_set_board_manager(void)
{
    int read_size;
    int file_descriptor;
    char read_buffer[4096] = { 0 };

    file_descriptor = file_open("../database/board_info.txt", O_RDONLY);
    read_from_file(file_descriptor, read_buffer, 4096);

    convert_file_to_in_memory_board(read_buffer, strlen(read_buffer));
}