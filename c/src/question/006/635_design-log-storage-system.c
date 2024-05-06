/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 635. 设计日志存储系统
 * link: https://leetcode-cn.com/problems/design-log-storage-system/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/13.
 */

#include "public.h"

/*#define MAX_LOG_ID_NUM 301

typedef struct {
    char* history[MAX_LOG_ID_NUM];
} LogSystem;*/

LogSystem* logSystemCreate()
{
    LogSystem *log = (LogSystem*)malloc(sizeof(LogSystem));
    if (log == NULL) {
        return NULL;
    }

    (void)memset(log, 0, sizeof(LogSystem));
    return log;
}

void logSystemPut(LogSystem* obj, int id, char * timestamp)
{
    int logLen;
    char *logAlloc;

    logLen = (int)strlen(timestamp) + 1;
    logAlloc = (char*)malloc(logLen);
    if (logAlloc == NULL) {
        return;
    }

    (void)memset(logAlloc,0, logLen);

    strcpy(logAlloc, timestamp);
    obj->history[id] = logAlloc;
}

int sysRetrieveLevel(const char *gra)
{
    if (strcmp(gra, "Year") == 0) {
        return 4;
    }

    if (strcmp(gra, "Month") == 0) {
        return 7;
    }

    if (strcmp(gra, "Day") == 0) {
        return 10;
    }

    if (strcmp(gra, "Hour") == 0) {
        return 13;
    }

    if (strcmp(gra, "Minute") == 0) {
        return 16;
    }

    return 19;
}

int* logSystemRetrieve(LogSystem* obj, char * s, char * e, char * gra, int* retSize)
{
    int *result = (int*)malloc(sizeof(int) * MAX_LOG_ID_NUM);
    int count = 0;
    int index = 1;

    (void)memset(result, 0, sizeof(int) * MAX_LOG_ID_NUM);
    int cmpLen = sysRetrieveLevel(gra);

    while(obj->history[index] != NULL) {
        char *tmp = obj->history[index];
        int cmpStart = strncmp(tmp, s, cmpLen);
        int cmpEnd = strncmp(tmp, e, cmpLen);

        if ((0 <= cmpStart) && (cmpEnd <= 0)) {
            result[count] = index;
            count++;
        }
        index++;
    }

    *retSize = count;
    return result;
}

void logSystemFree(LogSystem* obj)
{
    int index = 1;
    while(obj->history[index] != NULL) {
        free(obj->history[index]);
        index++;
    }

    free(obj);
}

/**
 * Your LogSystem struct will be instantiated and called as such:
 * LogSystem* obj = logSystemCreate();
 * logSystemPut(obj, id, timestamp);

 * int* param_2 = logSystemRetrieve(obj, s, e, gra, retSize);

 * logSystemFree(obj);
*/