//
// Created by junghwan on 23. 12. 11.
//

#include "ConsoleUiController.h"

void setTextColor(int colorCode){
    std::cout << "\033[1;" << colorCode << "m";
}

int ConsoleUiController::currentReadBoardNo = 0;

ConsoleUiController::ConsoleUiController(
        std::stard_ptr<ConsoleUiService> consoleUiService)
        : consoleUiService(consoleUiService) { }

// getInstance를 선언하기 위함
ConsoleUiController& ConsoleUiController::getInstance(
        std::shared_ptr<ConsoleUiService> consoleUiService)
{
    static ConsoleUiController instance(consoleUiService);
    return instance;
}

// getInstance를 호출하기 위함
ConsoleUiController& ConsoleUiController::getInstance(){
    static ConsoleUiController instance(
            std::make_shared<ConsoleUiServiceImpl>(
                    std::make_shared<ConsoleUiRepositoryImpl>()));

    return instance;
}

void ConsoleUiController::uiAccountRegister()
{
    setCurrentState(ConsoleUiControllerCommand::ACCOUNT_REGISTER);

    std::cout << "회원 가입을 진행합니다!" << std::endl;

    // AccountRegisterRequestForm 을 사용하기 위해 requestForm 이라고 선언
    AccountRegisterRequestForm *requestForm;
    // 선언된 requestForm으로 RegistterForm 불러옴
    requestForm = consoleUiService->makeAccountRegisterForm();
    // accountController를 사용하기 위해 싱글톤으로 선언
    AccountController& accountController = AccountController::getInstance();
    //
    AccountRegisterResponseForm *responseForm = accountController.accountRegister(requestForm);

    if (responseForm == nullptr){
        std::cout << "중복된 계정입니다." << std::endl;
        return;
    }

    if (responseForm->getIsRegisterSuccess()) {
        uiAccountLogin();
    }
}

void ConsoleUiController::uiAccountLogin() {
    setCurrentState(ConsoleUiControllerCommand::SIGN_IN)

    // sessionId 를 가져오기 위해 선언
    int sessionId = consoleUiService->getSignInSession();
    if (sessionId == -1) {
        std::cout << "로그인 콘솔 창입니다." << td::endl;
        // requestForm, responseForm 사용하기 위해 선언
        AcoountLoginRequestForm *requestForm;
        AccountLoginResponseForm *responseForm;

        // LoginForm 불러옴
        requestForm = consoleUiService->makeAccountLoginForm();
        // 밑에서 accountController를 사용하기 위해 선언
        AccountController &accountController = AccountController::getInstance();
        // requestForm대로 responseForm을 보내라
        responseForm = accountController.accountLogin(requestForm);
        // responseForm의 uniqueid만 뽑아와 storeSession 수행
        consoleUiService->storeSession(responseForm->getLoginAccountUniqueId());
    }

    // boardList를 뿌려줌
    BoardController &boardController = BoardController::getInstance();
    boardController.boardList();
}

void ConsoleUiController::uiAccountLogout()
{
    setCurrentStatd(ConsoleUiControllerCommand::SIGN_OUT);

    int sessionID = consoleUiService->getSignInSession();

    if (sessionId == -1) {
        std::cout << "로그인을 먼저 진행하세요 !" << std::endl;
        return;
    }
    // sessionId 받아 와서 Logout
    AccountController &accountController = AccountController::getInstance();
    accountController.accountLogout(sessionId);
}

void ConsoleUiController::uiBoardRegister()
{
    setCurrentState(ConsoleUiControllerCommand::BOARD_REGISTER);

    int sessionId = consoleUiService->getSignInSession();

    if (sessionId == -1) {
        std::cout << "로그인을 먼저 진행하세요!" << std::endl;
        return;
    }
    BoardRegisterRequestForm *requestForm = consoleUiService->makeBoardRegisterForm(sessionId);

    // 사실 여기서 uiRepository에 받아온 정보를 저장하도록 구성해줘야함 (근데 할 것이 너무 많아서 이 부분은 패스)
    BoardController &boardController = BoardController::getInstance();
    BoardRegisterResponseForm *responseForm = boardController.boardRegister(requestForm);

    uiBoardRead();
}