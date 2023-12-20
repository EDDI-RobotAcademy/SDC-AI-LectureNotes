class TaskEntity:
    def __init__(self, taskPid, target, args):
        # TODO: Need to refactor for Multiple Receiver and Transmitter
        self.__taskPid = taskPid
        self.__target = target
        self.__args = args

    def getTaskPid(self):
        return self.__taskPid

    def getTarget(self):
        return self.__target

    def getArgs(self):
        return self.__args

