from account_form.repository.AccountFormRepository import AccountFormRepository

from utility.keyboard.KeyboardInput import KeyboardInput


class AccountFormRepositoryImpl(AccountFormRepository):
    __instance = None

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    def __init__(self):
        print("AccountFormRepositoryImpl 초기화 동작")

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def createAccountRegisterForm(self):
        userInputId = KeyboardInput.getKeyboardInput("아이디를 입력하세요:")
        userInputPassword = KeyboardInput.getKeyboardInput("비밀번호를 입력하세요:")
        return userInputId, userInputPassword