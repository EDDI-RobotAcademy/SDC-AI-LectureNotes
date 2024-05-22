from dataclasses import dataclass

from sqlalchemy import Column, String, Integer
from sqlalchemy.orm import declarative_base

Base = declarative_base()


@dataclass
class Order(Base):
    __tablename__ = 'product_order'

    __id = Column(Integer, primary_key=True, autoincrement=True, name="id")
    __accountId = Column(Integer, nullable=False, name="account_id")
    __productId = Column(Integer, nullable=False, name="product_id")

    def __init__(self, accountId: int, productId: int):
        self.__accountId = accountId
        self.__productId = productId

    def getId(self):
        return self.__id

    def getAccountId(self):
        return self.__accountId

    def getProductId(self):
        return self.__productId


