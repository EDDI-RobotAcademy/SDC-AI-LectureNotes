//
// Created by eddi on 23. 11. 30.
//

#include "BoardServiceImpl.h"
#include <iostream>

BoardServiceImpl::BoardServiceImpl(std::shared_ptr<BoardRepository> boardRepository) : boardRepository(boardRepository) { }

std::vector<BoardListResponseForm> BoardServiceImpl::list()
{
    std::cout << "BoardService: 리스트 출력!" << std::endl;

    std::vector<Board> boardList = boardRepository->findAll();
    std::vector<BoardListResponseForm> responseList;

    for (const auto& board : boardList)
    {
        BoardListResponseForm responseForm(
                board.getId(), board.getTitle(), board.getContent());

        responseList.push_back(responseForm);
    }

    return responseList;
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
    }

    return nullptr;
}

BoardReadResponseForm *BoardServiceImpl::modify(BoardModifyRequest *request)
{
    std::optional<Board> maybeBoard = boardRepository->findById(request->getBoardNo());

    if (maybeBoard.has_value()) {
        Board board = maybeBoard.value();

        board.setTitle(request->getTitle());
        board.setContent(request->getContent());

        Board *updatedBoard = boardRepository->save(&board);

        return new BoardReadResponseForm(
                updatedBoard->getTitle(),
                updatedBoard->getWriter(),
                updatedBoard->getContent());
    }

    return nullptr;
}

void BoardServiceImpl::remove(int boardNo)
{
    boardRepository->deleteById(boardNo);
}
