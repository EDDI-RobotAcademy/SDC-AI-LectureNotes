//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDSERVICEIMPL_H
#define CLASS_TEST_BOARDSERVICEIMPL_H


#include <vector>
#include <memory>
#include "response/BoardResponse.h"
#include "BoardService.h"
#include "../repository/BoardRepository.h"

class BoardServiceImpl : public BoardService {
private:
    std::shared_ptr<BoardRepository> boardRepository;

public:
    BoardServiceImpl(std::shared_ptr<BoardRepository> boardRepository);
    std::vector<BoardResponse> list() override;
    // 여기다 만들 기능 쭉 쓰고,  service에도 쭉 쓰
};


#endif //CLASS_TEST_BOARDSERVICEIMPL_H
