class TaskEntity:
    # PID (Process ID) : 프로세스의 우선 순위를 정하거나 종료하는 등의 다양한 함수 호출에 사용
    def __init__(self, taskPid, target, args):
        self.__taskPid = taskPid
        self.__target = target
        self.__args = args

    def getTaskPid(self):
        return self.__taskPid

    def getTarget(self):
        return self.__target

    def getArgs(self):
        return self.__args

