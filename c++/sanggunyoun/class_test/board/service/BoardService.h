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
    // virtual(가상) - 존재하지 않는 것이기 때
    // BoardResponse 다발을 list 함수를 만들 예정이다.
    virtual std::vector<BoardResponse> list() = 0;
//    virtual std::vector<BoardResponse> create() = 0;
//    virtual std::vector<BoardResponse> Read() = 0;
//    virtual std::vector<BoardResponse> Modify() = 0;
//    virtual void Remove() = 0;
};

#endif //CLASS_TEST_BOARDSERVICE_H
