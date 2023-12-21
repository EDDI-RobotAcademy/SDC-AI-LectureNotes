from dataclasses import dataclass
from sqlalchemy import Column, String, Integer
from sqlalchemy.orm import declarative_base
from passlib.hash import pbkdf2_sha256
# pip3 install passlib

Base = declarative_base()


@dataclass
class Account(Base):
    __tablename__ = 'account'

    id: int = Column(Integer, primary_key=True, autoincrement=True)
    accountId: str = Column(String)
    password: str = Column(String)

    def __init__(self, accountId: str, password: str):
        self.__accountId = accountId
        self.__password = pbkdf2_sha256.hash(password)

    def check_password(self, password):
        return pbkdf2_sha256.verify(password, self.password_hash)

    def getAccountId(self):
        return self.__accountId

    def getPassword(self):
        return self.__password

