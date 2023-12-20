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
#include "../../board/controller/response_form/BoardListResponseForm.h"
#include "../../utility/keyboard/user_keyboard_input.h"

void setTextColor(int colorCode) {
    std::cout << "\033[1;" << colorCode << "m";
}

int ConsoleUiController::currentReadBoardNo = 0;
ConsoleUiControllerCommand ConsoleUiController::currentState;

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
    setCurrentState(ConsoleUiControllerCommand::ACCOUNT_REGISTER);

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
    setCurrentState(ConsoleUiControllerCommand::SIGN_IN);
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
    setCurrentState(ConsoleUiControllerCommand::SIGN_OUT);

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
    setCurrentState(ConsoleUiControllerCommand::BOARD_REGISTER);

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
    setCurrentState(ConsoleUiControllerCommand::BOARD_READ);

    int sessionId = consoleUiService->getSignInSession();

    if (sessionId == -1) {
        std::cout << "로그인을 먼저 진행하세요!" << std::endl;
        return;
    }

    // 이것도 사실 정석은 requestForm 만들어서 세션이랑 같이 보내야함
    int readBoardNo = consoleUiService->makeBoardReadForm();
    std::cout << "readBoardNo: " << readBoardNo << std::endl;

    setCurrentReadBoardNo(readBoardNo);

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

void ConsoleUiController::uiBoardList()
{
    setCurrentState(ConsoleUiControllerCommand::BOARD_LIST);

    BoardController &boardController = BoardController::getInstance();
    std::vector<BoardListResponseForm> responseFormList = boardController.boardList();

    setTextColor(32);
    std::cout << std::left << std::setw(10) << "ID" << std::setw(30) << "Title" << std::setw(20) << "Writer" << std::endl;
    std::cout << "=============================================================" << std::endl;

    if (responseFormList.empty()) {
        std::cout << "등록된 게시물이 없습니다!" << std::endl;
    }

    for (auto& responseForm : responseFormList) {
        std::cout << std::setw(10) << responseForm.getBoardId()
                << std::setw(30) << responseForm.getTitle()
                << std::setw(20) << responseForm.getWriter() << std::endl;
    }
}

void ConsoleUiController::uiBoardModify(int boardNo) {
    setCurrentState(ConsoleUiControllerCommand::BOARD_MODIFY);

    int sessionId = consoleUiService->getSignInSession();

    if (sessionId == -1) {
        std::cout << "로그인을 먼저 진행하세요!" << std::endl;
        return;
    }

    BoardModifyRequestForm *modifyRequestForm = consoleUiService->makeBoardModifyForm(boardNo);

    BoardController &boardController = BoardController::getInstance();
    BoardReadResponseForm *responseForm = boardController.boardModify(modifyRequestForm);

    if (responseForm != nullptr) {
        setTextColor(32);

        std::cout << "제목: " << responseForm->getTitle() << std::endl;
        std::cout << "작성자: " << responseForm->getWriter() << std::endl;
        std::cout << "내용: " << responseForm->getContent() << std::endl;
    }
}

void ConsoleUiController::uiBoardRemove(int boardNo)
{
    setCurrentState(ConsoleUiControllerCommand::BOARD_REMOVE);

    int sessionId = consoleUiService->getSignInSession();

    if (sessionId == -1) {
        std::cout << "로그인을 먼저 진행하세요!" << std::endl;
        return;
    }

    BoardController &boardController = BoardController::getInstance();
    boardController.boardRemove(boardNo);
}

void ConsoleUiController::uiExit()
{
    std::cout << "다음에 또 만나요 ~" << std::endl;

    std::exit(0);
}

void ConsoleUiController::uiEngineStart()
{
    std::string command;
    initializeCommandTable();

    while (true) {
        int sessionId = consoleUiService->getSignInSession();
        uiIntroduce(sessionId);
        get_user_keyboard_input_with_message("수행 할 명령을 입력하세요: ", command);

        ConsoleUiControllerCommand convertedCommand = consoleUiService->determineCommand(
                sessionId,
                std::stoi(command));

        void* parameter = consoleUiService->determineParameter(static_cast<int>(convertedCommand));
        std::cout << "parameter: " << parameter << std::endl;
//        int *boardNo;
//        if (convertedCommand == ConsoleUiControllerCommand::BOARD_MODIFY || convertedCommand == ConsoleUiControllerCommand::BOARD_REMOVE) {
//            boardNo = reinterpret_cast<int *>(parameter);
//            std::cout << "boardNo: " << boardNo << std::endl;
//            //int* intParameter = static_cast<int*>(parameter);
//        }

        executeCommand(
                convertedCommand,
                parameter);

        delete static_cast<int*>(parameter);
    }
}

void ConsoleUiController::initializeCommandTable() {
    commandTable.resize(static_cast<size_t>(ConsoleUiControllerCommand::UI_COMMAND_END));

    commandTable[static_cast<size_t>(ConsoleUiControllerCommand::ACCOUNT_REGISTER)] =
            +[](ConsoleUiController* controller, void* data) { controller->uiAccountRegister(); };
    commandTable[static_cast<size_t>(ConsoleUiControllerCommand::SIGN_IN)] =
            +[](ConsoleUiController* controller, void* data) { controller->uiAccountLogin(); };
    commandTable[static_cast<size_t>(ConsoleUiControllerCommand::SIGN_OUT)] =
            +[](ConsoleUiController* controller, void* data) { controller->uiAccountLogout(); };
    commandTable[static_cast<size_t>(ConsoleUiControllerCommand::BOARD_LIST)] =
            +[](ConsoleUiController* controller, void* data) { controller->uiBoardList(); };
    commandTable[static_cast<size_t>(ConsoleUiControllerCommand::BOARD_REGISTER)] =
            +[](ConsoleUiController* controller, void* data) { controller->uiBoardRegister(); };
    commandTable[static_cast<size_t>(ConsoleUiControllerCommand::BOARD_READ)] =
            +[](ConsoleUiController* controller, void* data) { controller->uiBoardRead(); };
    commandTable[static_cast<size_t>(ConsoleUiControllerCommand::BOARD_MODIFY)] =
            +[](ConsoleUiController* controller, void* data) { controller->uiBoardModify(*reinterpret_cast<int*>(data)); };
    commandTable[static_cast<size_t>(ConsoleUiControllerCommand::BOARD_REMOVE)] =
            +[](ConsoleUiController* controller, void* data) { controller->uiBoardRemove(*reinterpret_cast<int*>(data)); };
    commandTable[static_cast<size_t>(ConsoleUiControllerCommand::UI_EXIT)] =
            +[](ConsoleUiController* controller, void* data) { controller->uiExit(); };
}

// 명령을 처리하는 함수
void ConsoleUiController::executeCommand(ConsoleUiControllerCommand command, void* data) {
    size_t index = static_cast<size_t>(command);

    if (index < commandTable.size() && commandTable[index]) {
        // 함수를 호출
        commandTable[index](this, data);
    } else {
        // 유효하지 않은 명령에 대한 처리
        std::cout << "Invalid command." << std::endl;
    }
}

void ConsoleUiController::uiIntroduce(int sessionId)
{
    /*
     * 로그인이 되어 있으면 로그아웃, 게시판 리스트 조회하기, 게시물 작성하기, 종료하기
     * 로그인이 안되어 있으면 회원가입, 로그인, 게시판 리스트 조회하기, 종료하기         v
     * 게시판 리스트 조회하기를 했다면 게시물 작성하기, 게시물 읽기, 종료하기
     * 게시물을 읽고 있다면 게시물 수정하기, 게시물 삭제하기, 취소하기, 돌아가기
     */

    if (getCurrentState() == ConsoleUiControllerCommand::BOARD_LIST) {
        std::cout << "1. 게시물 작성하기\n";
        std::cout << "2. 게시물 읽기\n";
        std::cout << "3. 종료\n";
        return;
    }

    if (getCurrentState() == ConsoleUiControllerCommand::BOARD_READ) {
        std::cout << "1. 게시물 수정하기\n";
        std::cout << "2. 게시물 삭제하기\n";
        std::cout << "3. 돌아가기\n";
        std::cout << "4. 종료\n";
        return;
    }

    if (sessionId == -1) {
        std::cout << "1. 회원가입\n";
        std::cout << "2. 로그인\n";
        std::cout << "3. 게시물 리스트 조회\n";
        std::cout << "4. 종료\n";
        return;
    }

    std::cout << "1. 로그아웃\n";
    std::cout << "2. 게시물 리스트 조회\n";
    std::cout << "3. 종료\n";
}

int ConsoleUiController::getCurrentReadBoardNo()
{
    return currentReadBoardNo;
}

void ConsoleUiController::setCurrentReadBoardNo(int boardNo)
{
    currentReadBoardNo = boardNo;
}

ConsoleUiControllerCommand ConsoleUiController::getCurrentState() {
    return currentState;
}

void ConsoleUiController::setCurrentState(ConsoleUiControllerCommand currentState) {
    ConsoleUiController::currentState = currentState;
}
