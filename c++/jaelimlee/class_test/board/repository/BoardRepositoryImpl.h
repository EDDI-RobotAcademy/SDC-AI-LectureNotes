//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDREPOSITORYIMPL_H
#define CLASS_TEST_BOARDREPOSITORYIMPL_H


#include "BoardRepository.h"

class BoardRepositoryImpl : public BoardRepository {

public:
    std::vector<Board> findAll() override;
};


#endif //CLASS_TEST_BOARDREPOSITORYIMPL_H
