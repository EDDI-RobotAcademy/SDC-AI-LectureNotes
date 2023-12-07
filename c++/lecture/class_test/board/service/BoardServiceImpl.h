//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDSERVICEIMPL_H
#define CLASS_TEST_BOARDSERVICEIMPL_H


#include <vector>
#include <memory>

#include "response/BoardRegisterResponse.h"

#include "request/BoardRegisterRequest.h"

#include "BoardService.h"
#include "../repository/BoardRepository.h"

class BoardServiceImpl : public BoardService {
private:
    std::shared_ptr<BoardRepository> boardRepository;

public:
    BoardServiceImpl(std::shared_ptr<BoardRepository> boardRepository);
    std::vector<BoardRegisterResponse> list() override;
    BoardRegisterResponse *create(BoardRegisterRequest *request) override;
    BoardReadResponse *read(int boardNo) override;
};


#endif //CLASS_TEST_BOARDSERVICEIMPL_H
