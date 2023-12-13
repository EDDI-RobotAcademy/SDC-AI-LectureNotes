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
    // virtual(가상) - 존재하지만 존재하지 않는 것이기 때문
    // BoardResponse 다발을 리턴하는 list 함수를 만들 예정이야!
    virtual std::vector<BoardResponse> list() = 0;
    virtual std::vector<BoardResponse> creat() = 0;
    virtual std::vector<BoardResponse> read() = 0;
    virtual std::vector<BoardResponse> modify() = 0;
    virtual void remove() = 0;
};

#endif //CLASS_TEST_BOARDSERVICE_H
