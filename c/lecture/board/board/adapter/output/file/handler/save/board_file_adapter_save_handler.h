#ifndef __BOARD_FILE_ADAPTER_SAVE_HANDLER_H__
#define __BOARD_FILE_ADAPTER_SAVE_HANDLER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../../repository/in_memory_board.h"

#include "../../../../../domain/model/board_model.h"

#define _OVERRIDE(_1, _2, _3, NAME, ...) NAME

#define convert_board_model(...) _OVERRIDE(       \
    __VA_ARGS__,                        \
    convert_board_model3,   \
    convert_board_model2    \
)(__VA_ARGS__)

void convert_board_model(board_model *, char *);
void convert_board_model(board_model *, char *, unsigned int);
in_memory_board *save_to_file(void *);

#ifdef __cplusplus
}
#endif

#endif