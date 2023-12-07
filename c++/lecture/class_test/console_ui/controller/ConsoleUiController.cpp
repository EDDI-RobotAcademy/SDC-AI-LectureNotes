//
// Created by eddi on 23. 12. 5.
//

#include "ConsoleUiController.h"
#include "../../account/controller/AccountController.h"
#include "../service/ConsoleUiServiceImpl.h"
#include "../../account/controller/request_form/AccountLoginRequestForm.h"
#include "../repository/ConsoleUiRepositoryImpl.h"
#include "../../board/controller/BoardController.h"

#include "../../board/controller/request_form/BoardRegisterRequestForm.h"
#include "../../board/controller/response_form/BoardReadResponseForm.h"

ConsoleUiController::ConsoleUiController(
        std::shared_ptr<ConsoleUiService> consoleUiService)
            : consoleUiService(consoleUiService) { }

ConsoleUiController& ConsoleUiController::getInstance(
        std::shared_ptr<ConsoleUiService> consoleUiService)
{
    static ConsoleUiController instance(consoleUiService);
    return instance;
}

ConsoleUiController& ConsoleUiController::getInstance() {
    static ConsoleUiController instance(
            std::make_shared<ConsoleUiServiceImpl>(
                    std::make_shared<ConsoleUiRepositoryImpl>()));

    return instance;
}

void ConsoleUiController::uiAccountRegister()
{
    std::cout << "회원 가입을 진행합니다!" << std::endl;
    AccountRegisterRequestForm *requestForm;

    requestForm = consoleUiService->makeAccountRegisterForm();
    AccountController& accountController = AccountController::getInstance();

    AccountRegisterResponseForm *responseForm = accountController.accountRegister(requestForm);

    if (responseForm == nullptr) {
        std::cout << "중복된 계정입니다" << std::endl;
        // UI Command 창으로 보내야하지만 그냥 끝냄
        return;
    }

    if (responseForm->getIsRegisterSuccess()) {
        uiAccountLogin();
    }
}

void ConsoleUiController::uiAccountLogin()
{
    // 로그인 세션 존재 여부 파악
    int sessionId = consoleUiService->getSignInSession();
    if (sessionId == -1) {
        std::cout << "로그인 콘솔 창입니다." << std::endl;
        AccountLoginRequestForm *requestForm;
        AccountLoginResponseForm *responseForm;

        requestForm = consoleUiService->makeAccountLoginForm();
        AccountController &accountController = AccountController::getInstance();

        responseForm = accountController.accountLogin(requestForm);
        consoleUiService->storeSession(responseForm->getLoginAccountUniqueId());
    }

    // 게시판 리스트
    BoardController& boardController = BoardController::getInstance();
    boardController.boardList();
}

void ConsoleUiController::uiAccountLogout()
{
    int sessionId = consoleUiService->getSignInSession();

    if (sessionId == -1) {
        std::cout << "로그인을 먼저 진행하세요!" << std::endl;
        return;
    }

    AccountController &accountController = AccountController::getInstance();
    accountController.accountLogout(sessionId);
}

void ConsoleUiController::uiBoardRegister()
{
    int sessionId = consoleUiService->getSignInSession();

    if (sessionId == -1) {
        std::cout << "로그인을 먼저 진행하세요!" << std::endl;
        return;
    }

    BoardRegisterRequestForm *requestForm = consoleUiService->makeBoardRegisterForm(sessionId);

    BoardController &boardController = BoardController::getInstance();
    BoardRegisterResponseForm *responseForm = boardController.boardRegister(requestForm);
    // 사실 여기서 uiRepository에 받아온 정보를 저장하도록 구성해줘야함 (근데 할 것이 너무 많아서 이 부분은 패스)

    uiBoardRead();
}

void ConsoleUiController::uiBoardRead()
{
    int sessionId = consoleUiService->getSignInSession();

    if (sessionId == -1) {
        std::cout << "로그인을 먼저 진행하세요!" << std::endl;
        return;
    }

    // 이것도 사실 정석은 requestForm 만들어서 세션이랑 같이 보내야함
    int readBoardNo = consoleUiService->makeBoardReadForm();

    // 사실 위의 uiRepository에 state(상태) 값들을 저장해놨다면
    // 매번 번거롭게 boardController에 요청할 필요가 없을 것입니다.
    // 근데 그냥 요청하겠습니다.
    BoardController &boardController = BoardController::getInstance();
    BoardReadResponseForm *responseForm = boardController.boardRead(readBoardNo);

    if (responseForm != nullptr) {
        std::cout << std::setw(15) << std::left << "Title:" << responseForm->getTitle() << std::endl;
        std::cout << std::setw(15) << std::left << "Writer:" << responseForm->getWriter() << std::endl;
        std::cout << std::setw(15) << std::left << "Content:" << responseForm->getContent() << std::endl;
    }

    // 선택 할 수 있는 것 (수정, 삭제, 돌아가기)
}