#ifndef __BOARD_MODEL_H__
#define __BOARD_MODEL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_model_id.h"
#include "board_model_info.h"

#include <sys/stat.h>
#include <time.h>

typedef struct _board_model board_model;

struct _board_model
{
    board_model_id *board_model_id;
    board_model_info *board_model_info;

    time_t creation_time;
    time_t updated_time;
};

#define _OVERRIDE_BOARD_MODEL(_1, _2, NAME, ...) NAME

#define init_board_model_with_parameter(...) _OVERRIDE_BOARD_MODEL(       \
    __VA_ARGS__,                        \
    init_board_model_with_parameter2,   \
    init_board_model_with_parameter1    \
)(__VA_ARGS__)

board_model *init_board_model_with_parameter(board_model_id *, board_model_info *);
board_model *init_board_model_with_parameter(board_model_info *);
board_model *create_board_model_with_parameter(board_model_info *);
void set_board_model_id(board_model *, board_model_id *);

void clear_board_model(board_model *);

#ifdef __cplusplus
}
#endif

#endif