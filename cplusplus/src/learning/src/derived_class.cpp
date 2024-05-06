//
// Created by z00579768 on 2024/4/25.
//
#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Animal {
public:
    Animal(const string& name) : name_(name) {}

    // 基类的方法
    virtual void speak() const {
        cout << name_ << " makes a sound" << endl;
    }

    // 基类的数据成员
    string name_;
};

// 子类（派生类）
class Dog : public Animal { // 使用public继承
public:
    Dog(const string& name) : Animal(name) {} // 调用基类的构造函数

    // 子类覆盖基类的方法
    void speak() const override {
        cout << name_ << " barks" << endl;
    }
};

void TestCase_ClassAndDerivedClass()
{
    // 创建基类对象
    Animal animal("Generic Animal");
    animal.speak(); // 输出: Generic Animal makes a sound

    // 创建子类对象
    Dog dog("Fido");
    dog.speak(); // 输出: Fido barks

    // 基类指针指向子类对象（多态）
    Animal* animalPtr = &dog;
    animalPtr->speak(); // 输出: Fido barks
}