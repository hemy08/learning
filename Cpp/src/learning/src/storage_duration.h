//
// Created by z00579768 on 2024/4/26.
//

#ifndef LEARNING_CPP_STORAGE_DURATION_H
#define LEARNING_CPP_STORAGE_DURATION_H

#include <string>

using namespace std;

class StaticCLassMember {
public:
    static int count;
    // ¹¹Ôìº¯Êý  https://blog.csdn.net/weixin_74461263/article/details/132250800
    StaticCLassMember() {
        count++;
    }

    static int GetCount() {
        return count;
    }
};


class StorageDuration {
public:
    static void TestCase_StorageDuration();
private:
    static void StaticCount();
    static void StorageDuration_ThreadLocal();
    static void StorageDuration_Mutable();
    static void StorageDuration_Extern();
    static void StorageDuration_Static();
    static void StorageDuration_Register();
    static void StorageDuration_Auto();
};

#endif //LEARNING_CPP_STORAGE_DURATION_H
