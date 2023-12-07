//
// Created by eddi on 23. 11. 30.
//

#include "BoardController.h"
#include "../service/BoardServiceImpl.h"
#include "../repository/BoardRepositoryImpl.h"
#include "../../account/service/AccountServiceImpl.h"

#include "../service/response/BoardReadResponse.h"
#include "response_form/BoardReadResponseForm.h"

#include <iostream>
#include <vector>

BoardController::BoardController(std::shared_ptr<BoardService> boardService) : boardService(boardService) { }

std::vector<BoardListResponseForm> BoardController::boardList()
{
    std::cout << "BoardController: 게시물 리스트 출력!" << std::endl;

    return boardService->list();
}

BoardRegisterResponseForm *BoardController::boardRegister(BoardRegisterRequestForm *requestForm)
{
    std::cout << "BoardController: 게시물 등록하기!" << std::endl;

    std::shared_ptr<AccountRepositoryImpl> repository = AccountRepositoryImpl::getInstance();
    std::shared_ptr<AccountServiceImpl> accountService = AccountServiceImpl::getInstance(repository);
    std::string writer = accountService->findAccoutIdBySessionId(requestForm->getWriterSessionId());

    BoardRegisterResponse *response = boardService->create(requestForm->toBoardRegisterRequest(writer));
    return response->toBoardRegisterResponseForm();
}

BoardReadResponseForm *BoardController::boardRead(int boardNo)
{
    std::cout << "BoardController: 게시물 읽기!" << std::endl;

    // 위에 처럼 requestForm 가져와서 session 정보 가지고 사용자 인증을 해야함 (우선 패스)
    BoardReadResponse *response = boardService->read(boardNo);

    return response->toBoardReadResponseForm();
    //return nullptr;
}

BoardReadResponseForm *BoardController::boardModify(BoardModifyRequestForm *requestForm)
{
    std::cout << "BoardController: 게시물 수정하기!" << std::endl;

    return boardService->modify(requestForm->toBoardModifyRequest());
}

void BoardController::boardRemove(int boardNo)
{
    std::cout << "BoardController: 게시물 삭제하기!" << std::endl;

    boardService->remove(boardNo);
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
