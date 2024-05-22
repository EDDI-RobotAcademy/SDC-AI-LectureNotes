from dataclasses import dataclass
from datetime import datetime

from sqlalchemy import Column, String, Integer, DateTime
from sqlalchemy.orm import declarative_base, relationship
from passlib.hash import pbkdf2_sha256

# pip3 install passlib

Base = declarative_base()


@dataclass
class Account(Base):
    __tablename__ = 'account'

    __id: int = Column(Integer, primary_key=True, autoincrement=True, name="id")
    __accountId: str = Column(String, name="account_id")
    __password: str = Column(String, name="password")
    __reg_date = Column(DateTime, default=datetime.utcnow, name="reg_date")
    __upd_date = Column(DateTime, default=datetime.utcnow, onupdate=datetime.utcnow, name="upd_date")

    def __init__(self, accountId: str, password: str):
        self.__accountId = accountId
        self.__password = pbkdf2_sha256.hash(password)

    def checkPassword(self, password):
        return pbkdf2_sha256.verify(password, self.__password)

    def getId(self):
        return self.__id

    def getAccountId(self):
        return self.__accountId

    def getPassword(self):
        return self.__password

    def setPassword(self, password):
        self.__password = password

