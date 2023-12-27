from sqlalchemy.orm import sessionmaker

from mysql.MySQLDatabase import MySQLDatabase
from sqlalchemy.exc import SQLAlchemyError

from account.entity.Account import Account
from product.entity.Product import Product
from product.repository.ProductRepository import ProductRepository


class ProductRepositoryImpl(ProductRepository):
    __instance = None

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.engine = MySQLDatabase.getInstance().getMySQLEngine()
        return cls.__instance

    def __init__(self):
        print("ProductRepositoryImpl 생성자 호출")

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def findAll(self):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        return session.query(Product).all()

    def save(self, product):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        try:
            session.add(product)
            session.commit()

            print(f"product - id: {product.getId()}")
            return product

        except SQLAlchemyError as exception:
            session.rollback()
            print(f"DB 저장 중 에러 발생: {exception}")
            return None

    def findById(self, id):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        return session.query(Product).filter_by(_Product__id=id).first()

    def findByName(self, name):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        print(dir(Account))

        return session.query(Product).filter_by(_Product__name=name).first()

    def deleteById(self, id):
        dbSession = sessionmaker(bind=self.__instance.engine)
        session = dbSession()

        product = session.query(Product).filter_by(_Product__id=id).first()
        if product:
            session.delete(product)
            session.commit()
