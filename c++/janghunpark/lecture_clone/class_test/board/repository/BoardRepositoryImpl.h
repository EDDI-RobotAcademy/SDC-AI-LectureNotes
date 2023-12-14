//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDREPOSITORYIMPL_H
#define CLASS_TEST_BOARDREPOSITORYIMPL_H


#include "BoardRepository.h"
#include "../service/response/BoardRegisterResponse.h"

class BoardRepositoryImpl : public BoardRepository {

public:
    std::vector<Board> findAll() override;
    Board *save(Board *board) override;
    std::optional<Board> findById(int boardNo) override;
    void deleteById(int boardNo) override;

    static BoardRepositoryImpl& getInstance();
};


#endif //CLASS_TEST_BOARDREPOSITORYIMPL_H
