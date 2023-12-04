//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDCONTROLLER_H
#define CLASS_TEST_BOARDCONTROLLER_H


#include <memory>
#include <vector>

#include "../service/BoardService.h"

class BoardController {
private:
    std::shared_ptr<BoardService> boardService;
    //BoardService* boardService;

public:
    BoardController(std::shared_ptr<BoardService> boardService);
    //explicit BoardController(BoardService* service) : boardService(service) { }

    std::vector<BoardResponse> boardList();
    std::vector<BoardResponse> boardRegister(); // 게시글 작성
    std::vector<BoardResponse> boardRead(); // 읽기
    std::vector<BoardResponse> boardModify(); // 수정
    void BoardRemove(); // 삭제
};


#endif //CLASS_TEST_BOARDCONTROLLER_H
