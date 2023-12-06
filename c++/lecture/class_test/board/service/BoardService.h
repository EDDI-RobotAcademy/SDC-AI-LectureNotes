//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDSERVICE_H
#define CLASS_TEST_BOARDSERVICE_H

#include <vector>
#include "response/BoardRegisterResponse.h"
#include "request/BoardRegisterRequest.h"

class BoardService {
public:
    virtual ~BoardService() = default;
    // virtual(가상) - 존재하지만 존재하지 않는 것이기 때문
    // BoardRegisterResponse 다발을 리턴하는 list 함수를 만들 예정이야!
    virtual std::vector<BoardRegisterResponse> list() = 0;
    virtual BoardRegisterResponse *create(BoardRegisterRequest *request) = 0;
//    virtual std::vector<BoardRegisterResponse> read() = 0;
//    virtual std::vector<BoardRegisterResponse> modify() = 0;
//    virtual void remove() = 0;
};

#endif //CLASS_TEST_BOARDSERVICE_H
