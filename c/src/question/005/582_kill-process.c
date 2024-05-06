/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved. 
 * Description: 582. 杀死进程
 * link: https://leetcode-cn.com/problems/kill-process/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int PidCmp(const void* a, const void* b)
{
    return (*(int*)a) - (*(int*)b);
}

int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize)
{

    if ((pid == NULL) || (pidSize < 1) || (ppid == NULL) || (ppidSize < 1)) {

        *returnSize = 0;

        return NULL;

    }

    int data[pidSize * 2];

    memset(data, 0, sizeof(int) * pidSize * 2);

    bool exist = false;

    for (int i = 0; i < pidSize; ++i) {

        if (pid[i] == kill) {

            exist = true;

        }

        data[i * 2] = ppid[i];

        data[i * 2 + 1] = pid[i];

    }

    if (exist == false) {

        *returnSize = 0;

        return NULL;

    }

    qsort(data, pidSize, sizeof(int) * 2,  PidCmp);

    int stk[pidSize];

    int top = -1;

    memset(stk, 0, sizeof(int) * pidSize);

    int count = 0;

    int* ans = calloc(pidSize, sizeof(int));

    stk[++top] = kill;

    while (top >= 0) {

        int val = stk[top--];

        ans[count++] = val;

        int* pos = bsearch(&val, data, pidSize, sizeof(int) * 2, PidCmp);

        if (pos == NULL) {

            continue;

        }

        int start = (pos - data) / 2;

        for (int i = start - 1; i >= 0 ; --i) {

            if (data[i * 2] == val) {

                start--;

            } else {

                break;

            }

        }

        for (int i = start; i < ppidSize; ++i) {

            if (data[i * 2] == val) {

                stk[++top] = data[i * 2 + 1];

            }

        }

    }

    *returnSize = count;

    return ans;

}