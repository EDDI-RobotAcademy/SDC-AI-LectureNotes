//
// Created by eddi on 23. 11. 29.
//

#ifndef CPP_TEST_BOARDAPITABLEMAPPER_H
#define CPP_TEST_BOARDAPITABLEMAPPER_H

#include "BoardApiTable.h"
//#include "handler/list/board_api_list_handler.h"
//#include "handler/register/board_api_register_handler.h"
//#include "handler/read/board_api_read_handler.h"
//#include "handler/modify/board_api_modify_handler.h"
//#include "handler/remove/board_api_remove_handler.h"

// Define a macro for mapping
#define BOARD_API_MAPPER_ENTRY(api_enum, handler_class) \
    [static_cast<int>(api_enum)] = [](void* input) { return static_cast<BoardAPIHandler*>(new handler_class())(input); },

// Create an array using the mapping macro
const BoardAPIFunctionPtr board_api_mapper[] = {
//        BOARD_API_MAPPER_ENTRY(BOARD_API_LIST, BoardAPIListHandler)
//        BOARD_API_MAPPER_ENTRY(BOARD_API_REGISTER, BoardAPIRegisterHandler)
//        BOARD_API_MAPPER_ENTRY(BOARD_API_READ, BoardAPIReadHandler)
//        BOARD_API_MAPPER_ENTRY(BOARD_API_MODIFY, BoardAPIModifyHandler)
//        BOARD_API_MAPPER_ENTRY(BOARD_API_REMOVE, BoardAPIRemoveHandler)
//        nullptr
};

// Undefine the macro to avoid unintended use
#undef BOARD_API_MAPPER_ENTRY

#endif //CPP_TEST_BOARDAPITABLEMAPPER_H
