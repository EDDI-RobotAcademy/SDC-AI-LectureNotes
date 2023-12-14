#include <iostream>
#include <memory>
#include "dice/Dice.h"
#include "player/Player.h"
#include "board/controller/BoardController.h"
#include "board/service/BoardServiceImpl.h"
#include "board/repository/BoardRepository.h"
#include "board/repository/BoardRepositoryImpl.h"

#include "account/repository/AccountRepositoryImpl.h"
#include "account/service/AccountServiceImpl.h"
#include "account/controller/AccountController.h"
#include "console_ui/service/ConsoleUiServiceImpl.h"
#include "console_ui/controller/ConsoleUiController.h"
#include "mysql/DbProcess.h"
#include "console_ui/repository/ConsoleUiRepositoryImpl.h"

void init_database_object()
{
    const char* host = "localhost";
    const char* user = "eddi";
    const char* pass = "eddi@123";
    const char* dbName = "test_db";

    DbProcess* dbInstance = DbProcess::getInstance(host, user, pass, dbName);
    dbInstance->connect();
}

void init_singleton_object()
{
    std::shared_ptr<AccountRepositoryImpl> repository = AccountRepositoryImpl::getInstance();

//    std::shared_ptr<AccountService> service =
//            std::make_shared<AccountServiceImpl>(
//                    std::make_shared<AccountRepositoryImpl>(repository));
    std::shared_ptr<AccountServiceImpl> serviceInstance = AccountServiceImpl::getInstance(repository);
    //std::shared_ptr<AccountService> service(serviceInstance, [](auto) {});

    AccountController& controller = AccountController::getInstance(serviceInstance);

//    ConsoleUiServiceImpl& consoleUiService = ConsoleUiServiceImpl::getInstance();
//    ConsoleUiController& uiController = ConsoleUiController::getInstance(std::make_shared<ConsoleUiServiceImpl>());

    ConsoleUiRepositoryImpl& consoleUiRepository = ConsoleUiRepositoryImpl::getInstance();
    std::shared_ptr<ConsoleUiService> consoleUiService =
            std::make_shared<ConsoleUiServiceImpl>(
                    std::make_shared<ConsoleUiRepositoryImpl>());
    ConsoleUiController& uiController = ConsoleUiController::getInstance(consoleUiService);

    BoardRepositoryImpl& boardRepository = BoardRepositoryImpl::getInstance();
    std::shared_ptr<BoardService> boardService =
            std::make_shared<BoardServiceImpl>(
                    std::make_shared<BoardRepositoryImpl>());
    BoardController& boardController = BoardController::getInstance(boardService);
}

int main() {
//    if (true) {
//        Dice dice;
//        Dice dice2;
//    }

//    Dice *dice = new Dice();
//    dice->rollDice();
//
//    std::cout << "얼마 나옴 ? " << dice->getDiceNumber() << std::endl;
//
//    // 포인터로 객체 받았을 경우 delete가 필요함
//    delete dice;
//
//    Dice dice2;
//    dice2.rollDice();
//
//    std::cout << "이것도 됨 ? " << dice2.getDiceNumber() << std::endl;
//
//    std::string test_name = "테스트";
//    Player *player = new Player(test_name, 20);
//
//    std::cout << "사용자 정보 - 이름: " << player->getPlayerName() <<
//        ", 나이: " << player->getPlayerAge() << std::endl;
//
//    delete player;

//    BoardRepository *boardRepository = new BoardRepositoryImpl();
//    BoardService* boardService = new BoardServiceImpl();
//    auto boardRepository = std::make_shared<BoardRepositoryImpl>();
//    auto boardService = std::make_shared<BoardServiceImpl>(boardRepository);
//    auto boardController = std::make_shared<BoardController>(boardService);
//    boardController->boardList();

    init_singleton_object();
    init_database_object();


    ConsoleUiController &uiController = ConsoleUiController::getInstance();
    uiController.uiEngineStart();
    //uiController.uiAccountRegister();
    //uiController.uiBoardList();

    return 0;
}
