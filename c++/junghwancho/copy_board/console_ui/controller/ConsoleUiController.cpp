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
    // 현재의 상태 값을 판단해서 파라미터가 필요한지 아닌지 판단하기 위해 ?
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

void ConsoleUiController::uiBoardRead()
{
    setCurrentState(ConsoleUiControllerCommand::BOARD_READ);

    int sessionId = consoleUiService->getSignInSession();

    if (sessionId == -1){
        std::cout << "로그인을 먼저 진행하세요!" << std::endl;
        return;
    }

    // BoardNo 를 뽑아오기 위해 ReadForm으로 선언
    int readBoardNo = consoleUiService->makeBoardReadForm();

    std::cout << "readBoardNo: " << readBoardNo << std::endl;

    // ReadForm 에서 뽑아낸 readBoardNo로 current board no를 구하기 위해
    setCurrentReadBoardNo(readBoardNo);

    // boardController를 사용하기 위해 싱글톤으로 선언
    BoardController &boardController = BoardController::getInstance();
    // readBoardNo를 파라미터로 받아 boardRead 수행하여 responseForm으로 변환
    BoardReadResponseForm *responseForm = boardController.boardRead(readBoardNo);

    // responseForm에서 title, writer, content 뽑아 print
    if (responseForm ! = nullptr){
        std::cout << std::setw(15) << std::left << "Title:" << responseForm->getTitle() << std::endl;
        std::cout << std::setw(15) << std::left << "Writer:" << responseForm->getWriter() << std::endl;
        std::cout << std::setw(15) << std::left << "Content:" << responseForm->getContent() << std::endl;
    }
}

void ConsoleUiController::uiBoardList()
{
    setCurrentState(ConsoleUiControllerCommand::BOARD_LIST);

    BoardController &boardController = BoardController::getInstance();
    // boardlist를 불러오기 위해 responseFormList 동적배열 선언
    std::vector<BoardListResponseForm> responseFormList = boardController.boardList();

    setTextColor(32);
    std::cout << std::left << std::setw(10) << "ID" << std::setw(30) << "Title" << std::setw(20) << "Writer" << std::endl;
    std::cout <<"========================================================" << std::endl;

    // empty 였을 때 예외문 출력 =>> empty 나중에 확인 필요
    // empty 가 아니면 아래 for 문으로 이동
    if (responseFormList.empty()) {
        std::cout << "등록된 게시물이 없습니다 !" << std::endl;
    }

    // responseFormList를 받아서 responseForm 의 Id, Title, Writer 출
    for (auto& responseForm : responseFormList) {
        std::cout << std::setw(10) << responseForm.getBoardId()
                << std::setw(30) << responseForm.getTitle()
                << std::setw(20) << responseForm.getWriter() << std::endl;
    }
}

void ConsoleUiController::uiBoardModify(int boardNo) {
    setCurrentState(ConsoleUiControllerCommand::BOARD_MODIFY);

    // session id 받아오기
    int sessionId = consoleUiService->getSignInSession();

    if (sessionId == -1){
        std::cout << "로그인을 먼저 진행하세요!" << std::endl;
    return;
}

    // boardNo를 파라미터로 받아 consoleUiService의 makeBopardModifyForm을 작성하여
    // BoardModifyRequestForm의 modifyRequestForm으로 사용하기 위해 선언
    BoardModifyRequestForm *modifyRequestsForm = consoleUiService->makeBoardModifyForm(boardNo);

    // BoardController를 사용하기 위해 선언
    BoardController &boardController = BoardController::getInstance();
    // 위의 modifyRequestForm을 받은 boardController의 boardModify를
    // BoardReadResponseForm의 responseForm으로 사용
    BoardReadResponseForm *responseForm = boardController.boardModify(modifyRequestForm);

    // responseForm 에 데이터가 있으면 아래 출력
    if (responseForm !=nullptr) {
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

    if (sessionId == -1){
        std::cout << "로그인을 먼저 진행하세요 !" << std::endl;
        return;
    }

    // BoardController 를 사용하기 위해 싱글톤 선언
    BoardController &boardController = BoardController::getInstance();
    // boardNo를 받아 boardController의 boardRemove 실행
    boardController.boardRemove(boardNo);
}

void ConsoleUiController::uiExit()
{
    std::cout << "see you next time" << std::endl;

    std::exit(0);
}

void ConsoleUiController:uiEngineStart()
{
    std::string command;
    // 함수포인터 테이블을 동적으로 생성하기 위해 선언
    initializeCommandTable();

    while (true) {
        int sessionId =
    }
};