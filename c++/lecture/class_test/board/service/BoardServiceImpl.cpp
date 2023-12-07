//
// Created by eddi on 23. 11. 30.
//

#include "BoardServiceImpl.h"
#include <iostream>

BoardServiceImpl::BoardServiceImpl(std::shared_ptr<BoardRepository> boardRepository) : boardRepository(boardRepository) { }

std::vector<BoardRegisterResponse> BoardServiceImpl::list()
{
    std::cout << "BoardService: 리스트 출력!" << std::endl;

    boardRepository->findAll();

    return std::vector<BoardRegisterResponse>();
}

BoardRegisterResponse *BoardServiceImpl::create(BoardRegisterRequest *request) {
    Board *registeredBoard = boardRepository->save(request->toBoard());

    return new BoardRegisterResponse(
            registeredBoard->getTitle(),
            registeredBoard->getWriter(),
            registeredBoard->getContent());
}

BoardReadResponse *BoardServiceImpl::read(int boardNo)
{
    std::optional<Board> maybeBoard = boardRepository->findById(boardNo);

    if (maybeBoard.has_value()) {
        std::cout << "maybeBoard" << std::endl;
        Board board = maybeBoard.value();

        std::unique_ptr<BoardReadResponse> boardReadResponse =
                std::make_unique<BoardReadResponse>(
                        board.getTitle(), board.getWriter(), board.getContent());

        return boardReadResponse.release();
    } else {
        return nullptr;
    }

    return nullptr;
}
