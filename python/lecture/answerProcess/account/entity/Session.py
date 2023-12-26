from dataclasses import dataclass
from datetime import datetime, timedelta

from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column, Integer, DateTime

Base = declarative_base()


@dataclass
class Session(Base):
    __tablename__ = 'session'

    __id: int = Column(Integer, primary_key=True, autoincrement=True, name="id")
    __sessionId: int = Column(Integer, name="session_id")
    __expirationTime: datetime = Column(DateTime, default=datetime.utcnow() + timedelta(hours=1), name="expiration_time")

    def __init__(self, sessionId: int):
        self.__sessionId = sessionId

    def getSessionId(self):
        return self.__sessionId
