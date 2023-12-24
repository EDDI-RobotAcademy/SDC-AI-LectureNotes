# multiprocessing : 여러 작업을 병렬적으로 처리하여 더 빠른 결과를 얻을 수 있음
# 잘 모르고 쓰면 오히려 비효율적일 수 있으므로 프로세스, thread 에 대한 이해가 필요함
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
        print("TaskManageRepositoryImpl Initiator Call")
        self.__receiverTask = None
        self.__transmitterTask = None

    # C++로 치면 static 매서드 작성한 것과 같음
    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    # ps -ef 했을 때 나타나는 Task 생성
    # ps 가 뭔데 ? 현재 실행 중인 프로세스 목록을 보는 명령어
    # -e : 모든 프로세스의 정보 출력
    # -f : 프로세스의 자세한 정보 출력
    # 고로 ps -ef : '현재 실행 중인 모든 프로세스의 자세한 정보 출력' 일 것으로 예상
    def createTask(self, target, args):
        # print(f"createTask: args={args}")
        # Task 가 실행할 함수 -> target
        # Target 이 사용할 인자 -> args
        newTask = multiprocessing.Process(target=target, args=args)
        newTask.start()

        taskEntity = TaskEntity(newTask.pid, target, args)
        self.__taskEntityList.append(taskEntity)


