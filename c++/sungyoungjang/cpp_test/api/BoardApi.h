//
// Created by eddi on 23. 11. 29.
//

#ifndef CPP_TEST_BOARDAPI_H
#define CPP_TEST_BOARDAPI_H

enum class BoardAPI {
    LIST,
    REGISTER,
    READ,
    MODIFY,
    REMOVE,
    END
};

constexpr int BOARD_API_BUFFER_COUNT = static_cast<int>(BoardAPI::END); // static_cast 를 해야 번호를 인식 *필 *
constexpr int BOARD_API_BUFFER = BOARD_API_BUFFER_COUNT - 1;

#endif //CPP_TEST_BOARDAPI_H
