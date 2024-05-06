#include <iostream>
#include <string>
#include <typeinfo>
#include <type_traits>
#include "public.h"
#include "learning_public.h"
#include "storage_duration.h"

using namespace std;


template <typename T>
const char *GetValueType() {
    if (std::is_same<T, int>::value) {
        return "int";
    } else if (std::is_same<T, double>::value) {
        return "double";
    } else if (std::is_same<T, char>::value) {
        return "char";
    } else if (std::is_same<T, int*>::value) {
        return "int*";
    } else if (std::is_same<T, char*>::value) {
        return "char*";
    } else if (std::is_same<T, const char*>::value) {
        return "const char*";
    } else if (std::is_same<T, string>::value) {
        return "string";
    } else {
        return "unknown type";
    }// and so on...
}

void StorageDuration::StorageDuration_Auto()
{
    WriteLog("-------- Begin TestCase_StorageDuration_Auto");
    auto a = 10;
    auto f=3.14;      //double
    auto s("hello");  //const char*
    auto z = new auto(9); // int*
    auto d = (char*)"Hello World";
    // auto x1 = 5, x2 = 5.0, x3='r';//错误，必须是初始化为同一类型
    WriteLog("+ Type of a is: %s", GetValueType<decltype(a)>());
    WriteLog("+ Type of f is: %s", GetValueType<decltype(f)>());
    WriteLog("+ Type of s is: %s", GetValueType<decltype(s)>());
    WriteLog("+ Type of z is: %s", GetValueType<decltype(z)>());
    WriteLog("+ Type of d is: %s", GetValueType<decltype(d)>());
    WriteLog("-------- End TestCase_StorageDuration_Auto");
}

void StorageDuration::StorageDuration_Register()
{
    WriteLog("-------- Begin TestCase_StorageDuration_Register");
    WriteLog("+ ISO C++17 does not allow 'register' storage class specifier");
    // register int  miles;
    WriteLog("-------- End TestCase_StorageDuration_Register");
}

void StorageDuration::StaticCount() {
    static int calls = 0; // 局部静态变量
    calls++;
    WriteLog("+ This function has been called %d times.", calls);
}

int StaticCLassMember::count = 0;
void StorageDuration::StorageDuration_Static()
{
    WriteLog("-------- Begin TestCase_StorageDuration_Static");
    for (int i = 0; i < 10; ++i) {
        StorageDuration::StaticCount();
    }
    WriteLog("++++++++++++++++++++++++++++++++++++++++++++++++");
    for (int i = 0; i < 10; ++i) {
        auto tmp = new(StaticCLassMember);
        WriteLog("+ StaticCLassMember::count value is %d", StaticCLassMember::GetCount());
    }
    WriteLog("-------- End TestCase_StorageDuration_Static");
}

void StorageDuration::StorageDuration_Extern()
{
    WriteLog("-------- Begin TestCase_StorageDuration_Extern");
    WriteLog("-------- End TestCase_StorageDuration_Extern");
}

void StorageDuration::StorageDuration_Mutable()
{
    WriteLog("-------- Begin TestCase_StorageDuration_Mutable");
    WriteLog("-------- End TestCase_StorageDuration_Mutable");
}


void StorageDuration::StorageDuration_ThreadLocal()
{
    WriteLog("-------- Begin TestCase_StorageDuration_ThreadLocal");
    WriteLog("-------- End TestCase_StorageDuration_ThreadLocal");
}

void TestCase_StorageDuration()
{
    StorageDuration::TestCase_StorageDuration();
}

void StorageDuration::TestCase_StorageDuration() {
    WriteLog("================ Begin TestCase_StorageDuration ================");
    StorageDuration::StorageDuration_Auto();
    StorageDuration::StorageDuration_Register();
    StorageDuration::StorageDuration_Static();
    StorageDuration::StorageDuration_Extern();
    StorageDuration::StorageDuration_Mutable();
    StorageDuration::StorageDuration_ThreadLocal();
    WriteLog("================ End TestCase_StorageDuration ================");
}

