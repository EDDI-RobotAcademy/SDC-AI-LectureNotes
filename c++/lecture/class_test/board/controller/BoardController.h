//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDCONTROLLER_H
#define CLASS_TEST_BOARDCONTROLLER_H


#include <memory>
#include <vector>

#include "../service/BoardService.h"
#include "request_form/BoardRegisterRequestForm.h"
#include "response_form/BoardRegisterResponseForm.h"
#include "response_form/BoardReadResponseForm.h"

class BoardController {
private:
    std::shared_ptr<BoardService> boardService;
    //BoardService* boardService;

public:
    BoardController(std::shared_ptr<BoardService> boardService);
    //explicit BoardController(BoardService* service) : boardService(service) { }

    std::vector<BoardRegisterResponse> boardList();
    BoardRegisterResponseForm *boardRegister(BoardRegisterRequestForm *requestForm);
    BoardReadResponseForm *boardRead(int boardNo);
    std::vector<BoardRegisterResponse> boardModify();
    void BoardRemove();

    static BoardController& getInstance(std::shared_ptr<BoardService> boardService);
    static BoardController& getInstance();
};


#endif //CLASS_TEST_BOARDCONTROLLER_H
