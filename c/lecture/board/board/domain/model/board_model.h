#ifndef __BOARD_MODEL_H__
#define __BOARD_MODEL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_model_id.h"
#include "board_model_info.h"

typedef struct _board_model board_model;

struct _board_model
{
    board_model_id *board_model_id;
    board_model_info *board_model_info;
};

board_model *init_board_model_info_with_parameter(board_model_id *, board_model_info *);

void clear_board_model_info(board_model *);

#ifdef __cplusplus
}
#endif

#endif