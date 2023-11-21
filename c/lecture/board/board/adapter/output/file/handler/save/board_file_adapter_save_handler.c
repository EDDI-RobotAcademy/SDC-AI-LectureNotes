#include "board_file_adapter_save_handler.h"

#include <stdio.h>

#include "../../../../../domain/model/board_model.h"

#include "../../../../../../file/file.h"
#include "../../../../../../file/raw_io/file_io.h"
#include "../../../../../../in_memory/board/in_memory_board_manager.h"

#include <fcntl.h>

in_memory_board **save_to_file(void *domain_board_model)
{
    board_model *board = domain_board_model;
    int file_descriptor;

    printf("Board File Adapter: 게시물 저장\n");

    file_descriptor = file_open("../database/board_info.txt", 
                                O_CREAT | O_WRONLY | O_EXCL, 0644);


    file_close(file_descriptor);
    
    return NULL;
}
