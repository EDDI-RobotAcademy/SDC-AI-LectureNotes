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
    // 가상함수 - 존재하지만 존재하지 않는... dummy 개념으로
    // 가상으로 인터페이스를 만듬으로 함수 포인터를 사용하지 않음
    // BoardResponse 다발을 리턴하는 list 함수를 만들 예정이다.
    virtual std::vector<BoardResponse> list() = 0;
    //virtual std::vector<BoardResponse> register() = 0;
};

#endif //CLASS_TEST_BOARDSERVICE_H
