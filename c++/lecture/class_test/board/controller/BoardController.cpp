//
// Created by eddi on 23. 11. 30.
//

#include "BoardController.h"
#include "../service/BoardServiceImpl.h"
#include "../repository/BoardRepositoryImpl.h"
#include "../../account/service/AccountServiceImpl.h"

#include <iostream>
#include <vector>

BoardController::BoardController(std::shared_ptr<BoardService> boardService) : boardService(boardService) { }

std::vector<BoardRegisterResponse> BoardController::boardList()
{
    std::cout << "BoardController: 게시물 리스트 출력!" << std::endl;

    boardService->list();

    return std::vector<BoardRegisterResponse>();
}

BoardRegisterResponseForm *BoardController::boardRegister(BoardRegisterRequestForm *requestForm)
{
    std::cout << "BoardController: 게시물 등록하기!" << std::endl;

    AccountService &accountService = AccountServiceImpl::getInstance();
    std::string writer = accountService.findAccoutIdBySessionId(requestForm->getWriterSessionId());

    //boardService->create(requestForm->toBoardRegisterRequest(writer));
    return nullptr;
}

BoardController& BoardController::getInstance(
        std::shared_ptr<BoardService> boardService)
{
    static BoardController instance(boardService);
    return instance;
}

BoardController& BoardController::getInstance() {
    static BoardController instance(
            std::make_shared<BoardServiceImpl>(
                    std::make_shared<BoardRepositoryImpl>()));

    return instance;
}
