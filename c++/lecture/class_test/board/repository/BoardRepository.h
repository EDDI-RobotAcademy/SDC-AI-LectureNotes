//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDREPOSITORY_H
#define CLASS_TEST_BOARDREPOSITORY_H

#include <vector>
#include <optional>
#include "../entity/Board.h"

class BoardRepository {
public:
    virtual ~BoardRepository() = default;
    virtual std::vector<Board> findAll() = 0;
    virtual Board *save(Board *board) = 0;
    virtual std::optional<Board> findById(int boardNo) = 0;
    virtual void deleteById(int boardNo) = 0;
};

#endif //CLASS_TEST_BOARDREPOSITORY_H
