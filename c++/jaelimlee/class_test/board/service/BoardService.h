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
    // virtual(가상) - 존재하지만 존재하지 않는 것이기 때문에 가상임.
    // 인터페이스를 생성한 것임.
    // BoardResponse 다발을 리턴하는 list 함수를 만들 예정. but 아직은 사용하지 않을 것임.
    // c언어로 생각하면 함수 포인터 테이블을 만든 것이라 생각하면 됨
    virtual std::vector<BoardResponse> list() = 0;
    virtual std::vector<BoardResponse> create() = 0; // 게시글 작성
    virtual std::vector<BoardResponse> read() = 0; // 읽기
    virtual std::vector<BoardResponse> modify() = 0; // 수정
    virtual void remove() = 0; // 삭제
};

#endif //CLASS_TEST_BOARDSERVICE_H
