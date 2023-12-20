#include "BoardApiTable.h"
#include "BoardApi.h"

#include <iostream>

#include "handler/list/BoardAPIListHandler.h"
//#include "handler/register/board_api_register_handler.h"
//#include "handler/read/board_api_read_handler.h"
//#include "handler/modify/board_api_modify_handler.h"
//#include "handler/remove/board_api_remove_handler.h"

std::array<BoardAPIFunction, BOARD_API_BUFFER_COUNT> board_api_table = {
        std::make_unique<BoardAPIListHandler>(),
//        std::make_unique<BoardAPIRegisterHandler>(),
//        std::make_unique<BoardAPIReadHandler>(),
//        std::make_unique<BoardAPIModifyHandler>(),
//        std::make_unique<BoardAPIRemoveHandler>(),
};
