/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/5.
 */

#ifndef ____HEMY_CODE_REPO__SRC__EXAMS__INTERFACE__H____
#define ____HEMY_CODE_REPO__SRC__EXAMS__INTERFACE__H____

/*
 * 2020_Q2
 */
typedef struct{
    int id;
    int timeStamp;
} LogSystemArray;
LogSystemArray *LogSystemArrayCreate();
void LogSystemArrayAdd(LogSystemArray *obj, int id, int timeStamp);
int LogSystemArrayDelete(LogSystemArray *obj, int id);
int LogSystemArrayQuery(const LogSystemArray *obj, int startTime, int endTime);
void LogSystemArrayFree(LogSystemArray *obj);

/*
 * 2020_Q3
 */
int Postman(int* arr, int arrSize);
int FindMaxNumTimesList(int* nums, int numsSize, int *counts, int countSize, int *timesList, int listSize);
int FindShortestDuration(int* nums, int numsSize);
struct TenderSystemNode {
    int projectId;
    int userId;
    int price;
    int times;
    struct TenderSystemNode *next;
};

typedef struct {
    struct TenderSystemNode *head;
    struct TenderSystemNode *tail;
} TenderSystem;
TenderSystem* TenderSystemCreate();
void TenderSystemAddTender(TenderSystem* obj, int userId, int projectId, int price);
int TenderSystemUpdateTender(TenderSystem* obj, int userId, int projectId, int price);
int TenderSystemRemoveTender(TenderSystem* obj, int userId, int projectId);
int TenderSystemQueryTenderFindMinDst(TenderSystem* obj, int projectId, int price);
int TenderSystemQueryTenderFindUserId(TenderSystem* obj, int projectId, int price, int minDst);
int TenderSystemQueryTender(TenderSystem* obj, int projectId, int price);
void TenderSystemFree(TenderSystem* obj);

/*
 * 2020_Q4
 */
typedef struct {
    int id;
    int timeStamp
} LogInfo;

typedef struct {
    VosList head;
} LogSystemList;

void *LogDataDupFunc(uintptr_t src);
int LogSystemListGetID(uintptr_t value);
int LogSystemListGetTime(uintptr_t value);
LogSystemList *LogSystemListCreate();
void LogSystemListAdd(const LogSystemList *obj, int id, int timeStamp);
int LogSystemListDelete(const LogSystemList *obj, int id);
int LogSystemListQuery(const LogSystemList *obj, int startTime, int endTime);
void LogSystemListFree(const LogSystemList *obj);

int MaxDistanceBetweenSameLetters(char* inputStr);
typedef struct {
    int date;
    int price;
} PriceInfo;
typedef struct {
    VosList head;
} PriceSystem;
void *ItemDataDupFunc(uintptr_t src);
PriceInfo *PriceSystemCheckDate(const PriceSystem *obj, int date);
PriceSystem* PriceSystemCreate();
int PriceSystemAdd(const PriceSystem *obj, int date, int price);
int PriceSystemQuery(const PriceSystem *obj, int date);
int PriceSystemDelete(const PriceSystem *obj, int date);
void PriceSystemFree(PriceSystem *obj);

typedef struct {
    int* tasks;
    int tasksSize;
    int** mutexPairs;
    int mutexPairsSize;
    int *list;
    int listSize;
    int listNum;
    int curBeginPos;
    int curPos;
    int findCount;
}Data;

void CheckDivideInMutexPairs(Data *item);
void CheckDivideInList(Data* item);
int DivideGroupOptimization(int* tasks, int tasksSize, int** mutexPairs, int mutexPairsSize);

#endif //____HEMY_CODE_REPO__SRC__EXAMS__INTERFACE__H____
