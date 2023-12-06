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
    std::vector<BoardResponse> create() override;
};


#endif //CLASS_TEST_BOARDSERVICEIMPL_H
