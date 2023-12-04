//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDSERVICE_H
#define CLASS_TEST_BOARDSERVICE_H

#include <vector>
#include "response/BoardResponse.h"

class BoardService {
public:
    //virtual (가상 함수) => dummy 개념으로 활용 존재하지만 존재하지않은 것;
    virtual ~BoardService() = default;
    // BoardResponse 다발을 리턴하는 list 함수를 만들 예정! c에서 함수 포인터 테이블 과 같은 개
    virtual std::vector<BoardResponse> list() = 0;
    virtual std::vector<BoardResponse> create() = 0;
    virtual std::vector<BoardResponse> read() = 0;
    virtual std::vector<BoardResponse> modify() = 0;
    virtual void remove() = 0;
    // remove는 삭제하면 끝이기 때문에 void로
};

#endif //CLASS_TEST_BOARDSERVICE_H
