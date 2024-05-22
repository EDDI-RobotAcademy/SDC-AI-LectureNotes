import abc

from account.entity.Session import Session


class SessionRepository(abc.ABC):
    @abc.abstractmethod
    def save(self, accountSession: Session):
        pass

    @abc.abstractmethod
    def findById(self, id):
        pass

    @abc.abstractmethod
    def findBySessionId(self, sessionId):
        pass

    @abc.abstractmethod
    def deleteBySessionId(self, sessionId):
        pass


