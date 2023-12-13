//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDSERVICE_H
#define CLASS_TEST_BOARDSERVICE_H

#include <vector>
#include "response/BoardRegisterResponse.h"
#include "request/BoardRegisterRequest.h"
#include "response/BoardReadResponse.h"
#include "../controller/response_form/BoardListResponseForm.h"
#include "request/BoardModifyRequest.h"

class BoardService {
public:
    virtual ~BoardService() = default;
    // virtual(가상) - 존재하지만 존재하지 않는 것이기 때문
    // BoardRegisterResponse 다발을 리턴하는 list 함수를 만들 예정이야!
    virtual std::vector<BoardListResponseForm> list() = 0;
    virtual BoardRegisterResponse *create(BoardRegisterRequest *request) = 0;
    virtual BoardReadResponse *read(int boardNo) = 0;
    virtual BoardReadResponseForm *modify(BoardModifyRequest *request) = 0;
    virtual void remove(int boardNo) = 0;
};

#endif //CLASS_TEST_BOARDSERVICE_H
