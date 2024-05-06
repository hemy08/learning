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

    // ����ķ���
    virtual void speak() const {
        cout << name_ << " makes a sound" << endl;
    }

    // ��������ݳ�Ա
    string name_;
};

// ���ࣨ�����ࣩ
class Dog : public Animal { // ʹ��public�̳�
public:
    Dog(const string& name) : Animal(name) {} // ���û���Ĺ��캯��

    // ���า�ǻ���ķ���
    void speak() const override {
        cout << name_ << " barks" << endl;
    }
};

void TestCase_ClassAndDerivedClass()
{
    // �����������
    Animal animal("Generic Animal");
    animal.speak(); // ���: Generic Animal makes a sound

    // �����������
    Dog dog("Fido");
    dog.speak(); // ���: Fido barks

    // ����ָ��ָ��������󣨶�̬��
    Animal* animalPtr = &dog;
    animalPtr->speak(); // ���: Fido barks
}