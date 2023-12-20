from abc import *


class StudentBase(metaclass=ABCMeta):
    @abstractmethod
    def get_name(self):
        raise NotImplementedError

    @abstractmethod
    def get_age(self):
        raise NotImplementedError

    @abstractmethod
    def study(self):
        pass

    @abstractmethod
    def go_to_school(self):
        pass


class Student(StudentBase):
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def study(self):
        print('study hard')

    def go_to_school(self):
        print('go to school')

    def get_name(self):
        return self.name

    def get_age(self):
        return self.age
