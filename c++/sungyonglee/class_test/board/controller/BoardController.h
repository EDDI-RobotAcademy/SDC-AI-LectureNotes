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
    // 힌트  std::vector<BoardResponse> boardRegister();
    // std::vector<BoardResponse> boardRead();    // 대상 계시물 번호
    // std::vector<BoardResponse> boardModify();  // response 수정된 결과가 옴
    // void BoardRemove();                        // 삭제 결과는 response 될 것이 없음
};


#endif //CLASS_TEST_BOARDCONTROLLER_H
