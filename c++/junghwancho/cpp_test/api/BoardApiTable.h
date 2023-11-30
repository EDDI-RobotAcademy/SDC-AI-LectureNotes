//
// Created by eddi on 23. 11. 29.
//

#ifndef CPP_TEST_BOARDAPITABLE_H
#define CPP_TEST_BOARDAPITABLE_H

#include "BoardApi.h"

#include <array>
#include <memory>

using BoardAPIFunction = void* (*)(void*); // typedef = using

extern std::array<BoardAPIFunction, BOARD_API_BUFFER_COUNT> board_api_table;

#endif //CPP_TEST_BOARDAPITABLE_H
