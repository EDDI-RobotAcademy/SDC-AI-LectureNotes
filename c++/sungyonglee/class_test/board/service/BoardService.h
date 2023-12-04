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
    // C의 경우 함수포인터 다발을 만든 경우임 (핸들러를 만든 것은 아님)
    virtual std::vector<BoardResponse> list() = 0;
    // 힌트  virtual std::vector<BoardResponse> create() = 0;
    // virtual std::vector<BoardResponse> read() = 0;
    // virtual std::vector<BoardResponse> modify() = 0;
    // virtual void remove() = 0;
    // 어카운트 도메인 추가해야 함
};

#endif //CLASS_TEST_BOARDSERVICE_H
