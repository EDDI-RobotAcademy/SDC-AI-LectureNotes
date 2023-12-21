from sqlalchemy.orm import sessionmaker

from account.entity.Account import Account
from account.repository.AccountRepository import AccountRepository
from mysql.MySQLDatabase import MySQLDatabase


class AccountRepositoryImpl(AccountRepository):
    __instance = None

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.engine = MySQLDatabase.getInstance()
        return cls.__instance

    def __init__(self):
        print("TaskManageRepository 생성자 호출")
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

        session.add(account)
        session.commit()

    def update(self, account):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        existing_account = session.query(Account).filter_by(id=account.id).first()
        if existing_account:
            existing_account.__password = account.__password
            session.commit()

    def findById(self, account_id):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        return session.query(Account).filter_by(id=account_id).first()

    def findByAccountId(self, accountId):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        return session.query(Account).filter_by(__accountId=accountId).first()

    def deleteById(self, accountId):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        account = session.query(Account).filter_by(__accountId=accountId).first()
        if account:
            session.delete(account)
            session.commit()

