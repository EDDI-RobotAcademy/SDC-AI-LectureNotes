//
// Created by eddi on 23. 11. 30.
//
 // C에서 핸들러 기능을 한다.
#include "BoardServiceImpl.h"
#include <iostream>

BoardServiceImpl::BoardServiceImpl(std::shared_ptr<BoardRepository> boardRepository) : boardRepository(boardRepository) { }

std::vector<BoardResponse> BoardServiceImpl::list()
{
    std::cout << "BoardService: 리스트 출력!" << std::endl;

    boardRepository->findAll();

    return std::vector<BoardResponse>();
}