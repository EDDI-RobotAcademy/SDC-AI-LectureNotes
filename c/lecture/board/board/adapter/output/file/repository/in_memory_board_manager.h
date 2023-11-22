#ifndef __IN_MEMORY_BOARD_MANAGER_H__
#define __IN_MEMORY_BOARD_MANAGER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "in_memory_board.h"
#include "../../../../domain/model/board_model.h"

typedef struct _in_memory_board_manager in_memory_board_manager;

struct _in_memory_board_manager
{
    unsigned int alloc_count;
    in_memory_board *in_memory_board_array;
};

extern in_memory_board_manager global_in_memory_board_manager;

void init_in_memory_board_manager(void);
void alloc_in_memory_board_manager(board_model *board);

void read_file_to_set_board_manager(void);

#ifdef __cplusplus
}
#endif

#endif