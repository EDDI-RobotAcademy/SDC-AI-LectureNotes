#include "BoardApiTable.h"
#include "BoardApi.h"

#include <iostream>
//#include "handler/list/board_api_list_handler.h"
//#include "handler/register/board_api_register_handler.h"
//#include "handler/read/board_api_read_handler.h"
//#include "handler/modify/board_api_modify_handler.h"
//#include "handler/remove/board_api_remove_handler.h"

void* board_api_not_implemented(void* input) {
    std::cout << "Board API: 아직 구현되지 않은 기능입니다!" << std::endl;
    return nullptr;  // = dummy 와 같음
}

std::array<BoardAPIFunction, BOARD_API_BUFFER_COUNT> board_api_table = {
        board_api_not_implemented,
//        std::make_unique<BoardAPIListHandler>(),
//        std::make_unique<BoardAPIRegisterHandler>(),
//        std::make_unique<BoardAPIReadHandler>(),
//        std::make_unique<BoardAPIModifyHandler>(),
//        std::make_unique<BoardAPIRemoveHandler>(),
};
