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

board_model *init_board_model_with_parameter(board_model_id *, board_model_info *);

void clear_board_model(board_model *);

#ifdef __cplusplus
}
#endif

#endif