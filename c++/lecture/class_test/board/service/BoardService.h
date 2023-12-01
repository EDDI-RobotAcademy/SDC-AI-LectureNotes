//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDSERVICE_H
#define CLASS_TEST_BOARDSERVICE_H

#include <vector>
#include "response/BoardResponse.h"

class BoardService {
public:
    virtual ~BoardService() = default;
    virtual std::vector<BoardResponse> list() = 0;
};

#endif //CLASS_TEST_BOARDSERVICE_H
