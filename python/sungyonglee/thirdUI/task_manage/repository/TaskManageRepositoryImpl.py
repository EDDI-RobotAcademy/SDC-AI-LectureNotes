import multiprocessing

from task_manage.entity.TaskEntity import TaskEntity
from task_manage.repository.TaskManageRepository import TaskManageRepository


class TaskManageRepositoryImpl(TaskManageRepository):
    __instance = None
    __taskEntityList = []

    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    def __init__(self):
        print("TaskManageRepository 생성자 호출")
        self.__receiverTask = None
        self.__transmitterTask = None

    # C++로 치면 static 매서드 작성한 것과 같음
    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    def createTask(self, target, args):
        newTask = multiprocessing.Process(target=target, )
        newTask.start()

        taskEntity = TaskEntity(newTask.pid, target, args)
        self.__taskEntityList.append(taskEntity)

