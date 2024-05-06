# 基类
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        print(f"{self.name} makes a sound")

    # 子类（派生类）


class Dog(Animal):  # Dog继承自Animal
    def test(self):  # 覆盖基类的speak方法
        print(f"{self.name} barks")

    # 创建Animal和Dog的对象并调用方法


animal = Animal("Generic Animal")
animal.speak()  # 输出: Generic Animal makes a sound

dog = Dog("Fido")
dog.speak()  # 输出: Fido barks