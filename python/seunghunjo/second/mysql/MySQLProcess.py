import pymysql
import atexit


class DbProcess:
    __instance = None

    def __new__(cls, *args, **kwargs):
        if not cls.__instance:
            cls.__instance = super(DbProcess, cls).__new__(cls)
        return cls.__instance

    def __init__(self, host=None, user=None, password=None, database=None):
        print("DbProcess 생성자 호출")
        if not hasattr(self, 'initialized'):
            self.__host = host
            self.__user = user
            self.__password = password
            self.__database = database
            self.__connection = None
            self.__cursor = None
            self.__initialized = True

            atexit.register(self.closeConnection)

    @classmethod
    def getInstance(cls):
        if not cls.__instance:
            raise ValueError("DbProcess instance 가 아직 생성되지 않았습니다")
        return cls.__instance

    def connect(self):
        print("MySQL 연결 성공")

        try:
            # MySQL에 접속
            self.__connection = pymysql.connect(
                host=self.__host,
                user=self.__user,
                password=self.__password,
                database=self.__database
            )
            self.__cursor = self.__connection.cursor()
            print("MySQL 연결 성공")
        except Exception as e:
            print(f"MySQL 접속 중 에러 발생: {e}")

    def executeQuery(self, query):
        try:
            self.__cursor.execute(query)
            self.__connection.commit()
            print("쿼리 실행 성공")
        except Exception as e:
            print(f"쿼리 실행 중 에러 발생: {e}")

    def executeSelectQuery(self, query):
        try:
            self.__cursor.execute(query)
            result = self.__cursor.fetchall()
            return result
        except Exception as e:
            print(f"select query 중 에러 발생: {e}")
            return None

    def getAllData(self, table):
        query = f"SELECT * FROM {table};"
        return self.executeSelectQuery(query)

    def insertData(self, table, data):
        columns = ', '.join(data.keys())
        values = ', '.join(f"'{value}'" for value in data.values())
        query = f"INSERT INTO {table} ({columns}) VALUES ({values});"
        self.executeQuery(query)

    def updateData(self, table, data, condition):
        set_clause = ', '.join(f"{key} = '{value}'" for key, value in data.items())
        query = f"UPDATE {table} SET {set_clause} WHERE {condition};"
        self.executeQuery(query)

    def getSingleData(self, table, condition):
        query = f"SELECT * FROM {table} WHERE {condition};"
        result = self.executeSelectQuery(query)
        return result[0] if result else None

    def deleteData(self, table, condition):
        query = f"DELETE FROM {table} WHERE {condition};"
        self.executeQuery(query)

    def closeConnection(self):
        try:
            if self.__connection and getattr(self.__connection, 'open', False):
                self.__cursor.close()
                self.__connection.close()
                print("MySQL 연결 종료")
        except Exception as e:
            print(f"MySQL 연결 종료 중 에러 발생: {e}")

