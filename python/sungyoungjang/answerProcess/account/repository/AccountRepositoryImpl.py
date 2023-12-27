from sqlalchemy.orm import sessionmaker

from account.entity.Account import Account
from account.repository.AccountRepository import AccountRepository
from mysql.MySQLDatabase import MySQLDatabase
from sqlalchemy.exc import SQLAlchemyError


class AccountRepositoryImpl(AccountRepository):
    __instance = None

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.engine = MySQLDatabase.getInstance().getMySQLEngine()
        return cls.__instance

    def __init__(self):
        print("AccountRepositoryImpl 생성자 호출")
        self.__receiverTask = None
        self.__transmitterTask = None

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def save(self, account):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        try:
            session.add(account)
            session.commit()

            print(f"account - id: {account.getId()}")
            return account

        except SQLAlchemyError as exception:
            session.rollback()
            print(f"DB 저장 중 에러 발생: {exception}")
            return None

    def update(self, account):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        # protected 키워드는 이런데서 사용합니다.
        existingAccount = session.query(Account).filter_by(_Account__accountId=account.getAccountId()).first()
        if existingAccount:
            existingAccount.setPassword(account.getPassword())
            session.commit()

    def findById(self, id):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        return session.query(Account).filter_by(_Account__id=id).first()

    def findByAccountId(self, accountId):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        print(dir(Account))

        return session.query(Account).filter_by(_Account__accountId=accountId).first()

    def deleteByAccountId(self, accountId):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        account = session.query(Account).filter_by(_Account__accountId=accountId).first()
        if account:
            session.delete(account)
            session.commit()

    def deleteById(self, id):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        account = session.query(Account).filter_by(_Account__id=id).first()
        if account:
            session.delete(account)
            session.commit()
