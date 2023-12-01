//
// Created by eddi on 23. 11. 30.
//

#include "BoardController.h"

#include <iostream>
#include <vector>

BoardController::BoardController(std::shared_ptr<BoardService> boardService) : boardService(boardService) { }

std::vector<BoardResponse> BoardController::boardList()
{
    std::cout << "BoardController: 게시물 리스트 출력!" << std::endl;

    boardService->list();

    return std::vector<BoardResponse>();
}