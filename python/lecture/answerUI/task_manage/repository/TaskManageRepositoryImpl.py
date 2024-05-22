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

    # ps -ef 했을 때 나타나는 Task 생성
    def createTask(self, target, args):
        print(f"createTask: args={args}")
        # Task가 실행할 함수 -> target
        # target이 사용할 인자 -> args
        newTask = multiprocessing.Process(target=target, args=args)
        newTask.start()

        taskEntity = TaskEntity(newTask.pid, target, args)
        self.__taskEntityList.append(taskEntity)

    def getTaskEntityList(self):
        return self.__taskEntityList

