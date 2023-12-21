import atexit

import sqlalchemy
from decouple import config
from sqlalchemy import create_engine


class MySQLDatabase:
    __instance = None
    __mysqlEngine = None

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    def __init__(self):
        if not hasattr(self, '__mysqlEngine') or not self.__mysqlEngine:
            self.__host = config('DB_HOST')
            self.__dbUser = config('DB_USER')
            self.__password = config('DB_PASSWORD')
            self.__database = config('DB_NAME')
            self.__dbPort = config('DB_PORT')

    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def getMySQLEngine(self):
        return self.__mysqlEngine

    def connect(self):
        mysqlUrl = url = sqlalchemy.engine.URL.create(
            drivername="mysql",
            username=self.__dbUser,
            password=self.__password,
            host=self.__host,
            port=self.__dbPort,
            database=self.__database,
        )
        print("연결 문자열:", mysqlUrl)
        self.__mysqlEngine = create_engine(mysqlUrl, echo=True)
        # pip3 install mysqlclient

        atexit.register(self.closeMysqlConnection)

    def closeMysqlConnection(self):
        if self.__mysqlEngine:
            self.__mysqlEngine.dispose()
            print("MySQL 연결 종료")


