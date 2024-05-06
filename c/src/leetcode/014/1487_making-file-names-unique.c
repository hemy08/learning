/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 1487. 保证文件名唯一
 * link: https://leetcode-cn.com/problems/making-file-names-unique/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/22.
 */

#include "public.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define NAMES_LEN 22

bool CheckIsRepeat(char **names, int namesSize, const char *src, int *pos)
{
    int len = (int)strlen(src);
    for (int j = 0; j < namesSize; j++) {
        if (strlen(names[j]) != len) {
            continue;
        }

        if (strcmp(names[j], src) == 0) {
            if (pos != NULL) {
                *pos = j;
            }
            return true;
        }
    }

    // 没有重复，继续下一个命名
    return false;
}

char ** getFolderNames(char **names, int namesSize, int *returnSize)
{
    char **results = NULL;
    int *counts = NULL;
    int num;
    int pos = 0;
    char temp[20] = {0};

    counts = (int*)malloc(sizeof(int) * namesSize);
    if (counts == NULL) {
        return NULL;
    }
    memset(counts, 0, sizeof(int) * namesSize);

    results = (char**)malloc(sizeof(char*) * namesSize);
    if (results == NULL) {
        return NULL;
    }

    for (int i = 0; i < namesSize; i++) {
        results[i] = (char*)malloc(sizeof(char) * NAMES_LEN);
        if (results[i] == NULL) {
            return NULL;
        }
        memset(results[i], 0, NAMES_LEN);
    }

    // 返回的第一个names必然是和输入一样的
    memcpy(results[0], names[0], strlen(names[0]));

    // 从第二个开始进行遍历，看看前面是否出现过，以及出现的次数
    for (int i = 1; i < namesSize; i++) {
        if (!CheckIsRepeat(results, i, names[i], &pos)) {
            sprintf(results[i], "%s", names[i]);
            counts[pos] = 0;
            continue;
        }

        // 有重复
        num = counts[pos] + 1;
        while (num) {
            sprintf(temp, "%s(%d)", names[i], num);
            // 没有重复，继续下一个命名
            if (!CheckIsRepeat(results, i, temp, NULL)) {
                break;
            }
            memset(temp, 0, sizeof(temp));
            num++;
        }
        sprintf(results[i], "%s", temp);
        counts[pos] = num;
    }

    *returnSize = namesSize;
    return results;
}

/*
void main()
{
    char *names[100] = {"gta","gta(1)","gta","avalon"};
    int result_size = 0;

    char **result = getFolderNames(names, 4, &result_size);

    for (int i = 0; i < result_size; i++) {
        printf("%s\n", result[i]);
    }
}*/
